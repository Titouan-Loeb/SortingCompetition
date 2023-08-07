#ifndef THREAD_HPP
#define THREAD_HPP

#include <thread>
#include <mutex>
#include <vector>
#include <future>
#include <iostream>
#include <utility>

#include "SortingAlgoStruct.hpp"
#include "Mutex.hpp"

template <typename Num>
class ThreadWrapper
{
private:
    std::thread _thread;
    std::vector<Num> _array;
    AlgoInfoStruct<Num> _algoInfo;

public:
    ThreadWrapper(const AlgoInfoStruct<Num> &algo, const std::vector<Num> &array);
    ThreadWrapper(ThreadWrapper &&) = default;
    ~ThreadWrapper() = default;
    void launchThread();
    void wrapperAsync();
    void printResult();
    void joinThread();
};

template <typename Num>
ThreadWrapper<Num>::ThreadWrapper(const AlgoInfoStruct<Num> &algo, const std::vector<Num> &array)
{
    this->_algoInfo = algo;
    this->_array = array;
}

template <typename Num>
void ThreadWrapper<Num>::launchThread()
{
    this->_thread = std::thread(&ThreadWrapper::wrapperAsync, this);
}

template <typename Num>
void ThreadWrapper<Num>::wrapperAsync()
{
    auto startTime = std::chrono::steady_clock::now();
    std::vector<Num> resultList = this->_algoInfo.func(this->_array);
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = endTime - startTime;
    // promiseResult.set_value(resultList);
    std::lock_guard<std::mutex> lock(synchronizer);
    // std::lock_guard(this->_mutex);
    std::cout << this->_algoInfo.name << " " << duration.count() << "s : { ";
    for (size_t i = 0; i < resultList.size(); i++) {
        if (i == 0)
            std::cout << resultList[i];
        else
            std::cout << " < " << resultList[i];
    }
    std::cout << " }" << std::endl;
}

template <typename Num>
void ThreadWrapper<Num>::joinThread()
{
    _thread.join();
}

#endif