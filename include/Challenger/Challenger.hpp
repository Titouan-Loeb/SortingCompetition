#ifndef CHALLENGER_HPP
#define CHALLENGER_HPP

#include <map>

#include "BubbleSort.hpp"
#include "PushToSortedList.hpp"
#include "Mutex.hpp"
#include "SortingAlgoStruct.hpp"

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
    std::vector<AlgoInfoStruct<Num>> _algoStructList;
    std::map<SortAlgoFlags, AlgoPrototype<Num>> _functionPointers;
    std::vector<Num> _competitionArray;
    std::vector<std::thread> _threads;
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
    this->_algoStructList.push_back({ SortAlgoFlags::PUSH_TO_SORTED_LIST, "PushToSortedList", &PushToSortedList<Num>::sort });
    this->_competitionArray = competitionArray;
    for (size_t i = 0; i < this->_algoStructList.size(); i++)
        this->_functionPointers.insert(std::make_pair(this->_algoStructList[i].flag, this->_algoStructList[i].func));
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
    for (size_t i = 0; i < this->_algoStructList.size(); i++) {
        std::vector<Num> competitionArrayCopy = this->_competitionArray;
        AlgoInfoStruct<Num> algoInfoCopy = this->_algoStructList[i];
        this->_threads.push_back(std::thread([&, competitionArrayCopy, algoInfoCopy]() mutable {
            auto startTime = std::chrono::steady_clock::now();
            std::vector<Num> resultList = algoInfoCopy.func(competitionArrayCopy);
            auto endTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> duration = endTime - startTime;
            std::lock_guard<std::mutex> lock(synchronizer);
            std::cout << algoInfoCopy.name << " " << duration.count() << "s : { ";
            for (size_t i = 0; i < resultList.size(); i++) {
                if (i == 0)
                    std::cout << resultList[i];
                else
                    std::cout << " < " << resultList[i];
            }
            std::cout << " }" << std::endl;
        }));
    }
    for (size_t i = 0; i < this->_threads.size(); i++)
        this->_threads[i].join();
}

#endif // CHALLENGER_HPPThreadWrapper