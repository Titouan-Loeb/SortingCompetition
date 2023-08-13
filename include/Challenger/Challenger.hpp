#ifndef CHALLENGER_HPP
#define CHALLENGER_HPP

#include <map>
#include <thread>

#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "CocktailShakerSort.hpp"
#include "Mutex.hpp"
#include "SortingAlgoStruct.hpp"
#include "CustomException.hpp"

template <typename Num>
static void printArray(const std::string &algoName, const std::vector<Num> &array)
{
    std::cout << algoName << " : "; 
    for (size_t i = 0; i < array.size(); i++) {
        if (i + 1 < array.size())
            std::cout << array[i] << ", ";
        else
            std::cout << array[i] << std::endl;
    }
}

template <typename Num>
class Challenger
{
private:
    std::vector<Num> _competitionArray;
    std::vector<AlgoInfoStruct<Num>> _algoStructList;
    std::vector<std::jthread> _threads;
    // std::vector<std::threThreadWrapperad> _threads;
    size_t _place;

    void waitThreads();
public:
    Challenger(const std::vector<Num> &competitionArray);
    ~Challenger();

    void challengeAll();
    void challengeSpecific(SortAlgoFlags algoFlags);
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
Challenger<Num>::Challenger(const std::vector<Num> &competitionArray)
{
    this->_algoStructList.push_back(AlgoInfoStruct<Num>{ SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back(AlgoInfoStruct<Num>{ SortAlgoFlags::INSERTION_SORT, "InsertionSort", &InsertionSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back(AlgoInfoStruct<Num>{ SortAlgoFlags::SELECTION_SORT, "SelectionSort", &SelectionSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back(AlgoInfoStruct<Num>{ SortAlgoFlags::COCKTAIL_SHAKER_SORT, "CocktailShakerSort", &CocktailShakerSort<Num>::sortWithTimeout });
    this->_competitionArray = competitionArray;
    this->_place = 0;
}
 
template <typename Num>
Challenger<Num>::~Challenger()
{
}

template <typename Num>
void Challenger<Num>::challengeAll()
{
    for (auto algoStruct : this->_algoStructList) {
        // auto wrapper = [&] {
        //     auto startTime = std::chrono::steady_clock::now();
        //     try {
        //         std::vector<Num> resultList = algoStruct.second.func(this->_competitionArray, timeout);
        //     } catch (const std::exception &e) {
        //         std::lock_guard<std::mutex> lock(synchronizer);
        //         std::cout << algoStruct.second.name << " -> DNF" << std::endl;
        //         return;
        //     }
        //     auto endTime = std::chrono::steady_clock::now();
        //     std::chrono::duration<double> duration = endTime - startTime;
        //     std::lock_guard<std::mutex> lock(synchronizer);
        //     this->_place++;
        //     std::cout << this->_place << ": " << algoStruct.second.name << " -> " << duration.count() << "s" << std::endl;
        // };
        // ThreadWrapper<Num> wrap(algoStruct.second, this->_competitionArray, this->_place);
        // this->_threadMap.insert(std::make_pair(key, std::move(wrap)));
        this->_threads.push_back(std::jthread([&]() mutable {
            auto startTime = std::chrono::steady_clock::now();
            try {
                std::vector<Num> resultList = algoStruct.func(this->_competitionArray, timeout);
            } catch (const std::exception &e) {
                std::lock_guard<std::mutex> lock(synchronizer);
                std::cout << algoStruct.name << " -> DNF" << std::endl;
                return;
            }
            auto endTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> duration = endTime - startTime;
            std::lock_guard<std::mutex> lock(synchronizer);
            std::cout << this->_place++ << ". " << algoStruct.name << " -> " << duration.count() << "s";
        }));
        // this->_threadMap.insert(std::make_pair(key, std::move(ThreadWrapper<Num>(algoStruct.second, this->_competitionArray, this->_place))));
        // ThreadWrapper<Num> threadWrapper(algoStruct.second, this->_competitionArray, this->_place);
        // this->_threadMap.emplace(key, std::move(threadWrapper));
    }
    waitThreads();
}

template <typename Num>
void Challenger<Num>::waitThreads()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    timeout.store(true);
    for (size_t i = 0; i < this->_threads.size(); i++)
        this->_threads[i].join();
}

#endif // CHALLENGER_HPP