#ifndef CHALLENGER_HPP
#define CHALLENGER_HPP

#include <vector>
#include <map>
#include <mutex>

#include "BubbleSort.hpp"
#include "PushToSortedList.hpp"
#include "SortingAlgoStruct.hpp"
#include "ThreadWrapper.hpp"
#include "Mutex.hpp"

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
    // const std::vector<AlgoInfoStruct<Num>> _algoStructList = {
    //     { SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sort },
    //     { SortAlgoFlags::PUSH_TO_SORTED_LIST, "PushToSortedList", &PushToSortedList<Num>::sort },
    // };
    std::vector<AlgoInfoStruct<Num>> _algoStructList;
    std::map<SortAlgoFlags, AlgoPrototype<Num>> _functionPointers;
    std::vector<Num> _competitionArray;
    std::vector<ThreadWrapper<Num>> _competitionThreads;
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
    this->_algoStructList.push_back({ SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sort });
    std::vector<Num> res = BubbleSort<Num>::sort({12, -5, 1});
    printArray<Num>("test", res);
    this->_algoStructList.push_back({ SortAlgoFlags::PUSH_TO_SORTED_LIST, "PushToSortedList", &PushToSortedList<Num>::sort });
    this->_competitionArray = competitionArray;
    for (size_t i = 0; i < this->_algoStructList.size(); i++)
        this->_functionPointers.insert(std::make_pair(this->_algoStructList[i].flag, this->_algoStructList[i].func));
}

template <typename Num>
Challenger<Num>::~Challenger()
{
    this->_competitionArray.clear();
    this->_competitionThreads.clear();
}

template <typename Num>
void Challenger<Num>::challengeAll()
{
    ThreadWrapper<Num> test({ SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sort }, {10, -7, 1});
    test.launchThread();
    test.joinThread();
    for (size_t i = 0; i < this->_algoStructList.size(); i++)
        this->_competitionThreads.push_back(ThreadWrapper<Num>({ SortAlgoFlags::BUBBLE_SORT, "BubbleSort", &BubbleSort<Num>::sort }, {10, -7, 1}));
}

#endif // CHALLENGER_HPPThreadWrapper