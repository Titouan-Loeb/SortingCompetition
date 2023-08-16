#ifndef CHALLENGER_HPP
#define CHALLENGER_HPP

#include <map>
#include <thread>

#include "Mutex.hpp"
#include "SortingAlgoStruct.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "CocktailShakerSort.hpp"
#include "BogoSort.hpp"


template <typename Num>
class Challenger
{
private:
    std::vector<Num> _competitionArray;
    std::vector<AlgoInfoStruct<Num>> _algoStructList;
    std::vector<std::jthread> _threads;
    size_t _place;

    void createThreads();
    void waitThreads();

public:
    Challenger(const std::vector<Num> &competitionArray);
    ~Challenger();

    void challengeAll();
    void challengeAllWithTimeout(const int &timeLimit);
    void challengeSpecific(SortAlgoFlags algoFlags);
    void challengeSpecificWithTimeout(SortAlgoFlags algoFlags);
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
Challenger<Num>::Challenger(const std::vector<Num> &competitionArray)
{
    this->_place = 0;
    this->_algoStructList.push_back({ SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back({ SortAlgoFlags::INSERTION_SORT, "InsertionSort", &InsertionSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back({ SortAlgoFlags::SELECTION_SORT, "SelectionSort", &SelectionSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back({ SortAlgoFlags::COCKTAIL_SHAKER_SORT, "CocktailShakerSort", &CocktailShakerSort<Num>::sortWithTimeout });
    this->_algoStructList.push_back({ SortAlgoFlags::BOGO_SORT, "BogoSort", &BogoSort<Num>::sortWithTimeout });
    this->_competitionArray = competitionArray;
}

template <typename Num>
Challenger<Num>::~Challenger()
{
    this->_competitionArray.clear();
    this->_threads.clear();
}

template <typename Num>
void Challenger<Num>::challengeAll()
{
    createThreads();
    waitThreads();
}

template <typename Num>
void Challenger<Num>::challengeAllWithTimeout(const int &timeLimit)
{   
    createThreads();
    std::this_thread::sleep_for(std::chrono::milliseconds(timeLimit));
    timeout.store(true);
    std::cout << "------------- TIME OUT -------------" << std::endl;
    waitThreads();
}

template <typename Num>
void Challenger<Num>::createThreads()
{
    this->_threads.clear();
    this->_place = 0;
    for (size_t i = 0; i < this->_algoStructList.size(); i++) {
        std::vector<Num> competitionArrayCopy = this->_competitionArray;
        AlgoInfoStruct<Num> algoInfoCopy = this->_algoStructList[i];
        this->_threads.push_back(std::jthread([&, competitionArrayCopy, algoInfoCopy]() mutable {
            auto startTime = std::chrono::steady_clock::now();
            try {
                std::vector<Num> resultList = algoInfoCopy.funcTimeout(competitionArrayCopy, timeout);
            } catch (const std::exception &e) {
                std::lock_guard<std::mutex> lock(synchronizer);
                std::cout << algoInfoCopy.name << " -> DNF" << std::endl;
                return;
            }
            auto endTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> duration = endTime - startTime;
            std::lock_guard<std::mutex> lock(synchronizer);
            std::cout << ++this->_place << ". " << algoInfoCopy.name << " -> " << duration.count() << "s" << std::endl;
        }));
    }

}

template <typename Num>
void Challenger<Num>::waitThreads()
{
    for (size_t i = 0; i < this->_threads.size(); i++)
        if (this->_threads[i].joinable())
            this->_threads[i].join();
}

#endif // CHALLENGER_HPPThreadWrapper