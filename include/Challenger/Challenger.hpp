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
#include "DoubleSelectionSort.hpp"


template <typename Num>
class Challenger
{
private:
    std::vector<Num> _competitionArray;
    std::map<SortAlgoFlags, AlgoInfoStruct<Num>> _algoStructList;
    std::vector<std::thread> _threads;
    size_t _place;

    void createAllThreads();
    void createSpecificThreads(const SortAlgoFlags &algoFlags);
    void waitThreads();

public:
    Challenger(const std::vector<Num> &competitionArray);
    ~Challenger();

    void challengeAll();
    void challengeAllWithTimeout(const int &timeLimit);
    void challengeSpecific(const uint32_t &algoFlags);
    void challengeSpecificWithTimeout(const SortAlgoFlags &algoFlags, const int &timeLimit);
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
Challenger<Num>::Challenger(const std::vector<Num> &competitionArray)
{
    this->_place = 0;
    this->_algoStructList.insert(std::make_pair(SortAlgoFlags::BUBBLE_SORT, AlgoInfoStruct<Num>{SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sortWithTimeout}));
    this->_algoStructList.insert(std::make_pair(SortAlgoFlags::INSERTION_SORT, AlgoInfoStruct<Num>{SortAlgoFlags::INSERTION_SORT, "InsertionSort", &InsertionSort<Num>::sortWithTimeout}));
    this->_algoStructList.insert(std::make_pair(SortAlgoFlags::SELECTION_SORT, AlgoInfoStruct<Num>{SortAlgoFlags::SELECTION_SORT, "SelectionSort", &SelectionSort<Num>::sortWithTimeout}));
    this->_algoStructList.insert(std::make_pair(SortAlgoFlags::COCKTAIL_SHAKER_SORT, AlgoInfoStruct<Num>{SortAlgoFlags::COCKTAIL_SHAKER_SORT, "CocktailShakerSort", &CocktailShakerSort<Num>::sortWithTimeout}));
    this->_algoStructList.insert(std::make_pair(SortAlgoFlags::BOGO_SORT, AlgoInfoStruct<Num>{SortAlgoFlags::BOGO_SORT, "BogoSort", &BogoSort<Num>::sortWithTimeout}));
    this->_algoStructList.insert(std::make_pair(SortAlgoFlags::DOUBLE_SELECTION_SORT, AlgoInfoStruct<Num>{SortAlgoFlags::DOUBLE_SELECTION_SORT, "DoubleSelectionSort", &DoubleSelectionSort<Num>::sortWithTimeout}));
    this->_competitionArray = competitionArray;
}

template <typename Num>
Challenger<Num>::~Challenger()
{
    this->_competitionArray.clear();
    this->_threads.clear();
}

template <typename Num>
void Challenger<Num>::createAllThreads()
{
    this->_threads.clear();
    this->_place = 0;
    // for (size_t i = 0; i < this->_algoStructList.size(); i++) {
    for (auto algoStruct : this->_algoStructList) {
        std::vector<Num> competitionArrayCopy = this->_competitionArray;
        // AlgoInfoStruct<Num> algoInfoCopy = this->_algoStructList[i];
        AlgoInfoStruct<Num> algoInfoCopy = algoStruct.second;
        this->_threads.push_back(std::thread([&, competitionArrayCopy, algoInfoCopy]() {
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

template <typename Num>
void Challenger<Num>::challengeAll()
{
    createAllThreads();
    waitThreads();
}

template <typename Num>
void Challenger<Num>::challengeAllWithTimeout(const int &timeLimit)
{   
    createAllThreads();
    std::this_thread::sleep_for(std::chrono::milliseconds(timeLimit));
    timeout.store(true);
    std::cout << "------------- TIME OUT -------------" << std::endl;
    waitThreads();
}

// template <typename Num>
// void Challenger<Num>::challengeSpecific(const uint32_t &algoFlags)
// {
//     std::vector<int> allSortFlags = {
//         SortAlgoFlags::BUBBLE_SORT,
//         SortAlgoFlags::INSERTION_SORT,
//         SortAlgoFlags::SELECTION_SORT,
//         SortAlgoFlags::COCKTAIL_SHAKER_SORT,
//         SortAlgoFlags::BOGO_SORT,
//         SortAlgoFlags::DOUBLE_SELECTION_SORT,
//     };

//     for (size_t i = 0; i < allSortFlags.size(); i++) {
//         if (algoFlags & allSortFlags[i]) {
//             std::vector<Num> competitionArrayCopy = this->_competitionArray;
//             AlgoInfoStruct<Num> algoInfoCopy = this->_algoStructList[allSortFlags[i]];
//             this->_threads.push_back(std::thread([&, competitionArrayCopy, algoInfoCopy]() {
//                 auto startTime = std::chrono::steady_clock::now();
//                 try {
//                     std::vector<Num> resultList = algoInfoCopy.funcTimeout(competitionArrayCopy, timeout);
//                 } catch (const std::exception &e) {
//                     std::lock_guard<std::mutex> lock(synchronizer);
//                     std::cout << algoInfoCopy.name << " -> DNF" << std::endl;
//                     return;
//                 }
//                 auto endTime = std::chrono::steady_clock::now();
//                 std::chrono::duration<double> duration = endTime - startTime;
//                 std::lock_guard<std::mutex> lock(synchronizer);
//                 std::cout << ++this->_place << ". " << algoInfoCopy.name << " -> " << duration.count() << "s" << std::endl;
//             }));
//         }
//     }
// }


#endif // CHALLENGER_HPPThreadWrapper