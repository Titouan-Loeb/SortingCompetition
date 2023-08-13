#ifndef THREAD_WRAPPER_HPP
#define THREAD_WRAPPER_HPP

#include <thread>
#include <atomic>
#include <functional>

#include "SortingAlgoStruct.hpp"
#include "Mutex.hpp"

template <typename Num>
class ThreadWrapper
{
private:
    std::thread _thread;
    std::atomic<bool> _finished;
    // bool _finished;
    
    void wrapper(const AlgoInfoStruct<Num> algoInfo, std::vector<Num> competitionArray, size_t &place);

public:
    ThreadWrapper(const AlgoInfoStruct<Num> &algoInfo, const std::vector<Num> &competitionArray, size_t &place);
    ThreadWrapper(ThreadWrapper &&) = default;
    ~ThreadWrapper();

    bool isFinished();
    void join();
};

template <typename Num>
ThreadWrapper<Num>::ThreadWrapper(const AlgoInfoStruct<Num> &algoInfo, const std::vector<Num> &competitionArray, size_t &place) : _finished(true)
{
    // this->_finished.store(false);
    // this->_finished = false;
    std::cout << "Init :" << this << std::endl;
    this->_thread = std::thread(&ThreadWrapper::wrapper, this, algoInfo, competitionArray, std::ref(place));
}

template <typename Num>
ThreadWrapper<Num>::~ThreadWrapper()
{
}

template <typename Num>
void ThreadWrapper<Num>::wrapper(const AlgoInfoStruct<Num> algoInfo, std::vector<Num> competitionArray, size_t &place)
{
    auto startTime = std::chrono::steady_clock::now();
    try {
        std::vector<Num> resultList = algoInfo.func(competitionArray, timeout);
    } catch (const std::exception &e) {
        std::lock_guard<std::mutex> lock(synchronizer);
        std::cout << algoInfo.name << " -> DNF" << std::endl;
        return;
    }
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = endTime - startTime;
    std::lock_guard<std::mutex> lock(synchronizer);
    place++;
    std::cout << place << ": " << algoInfo.name << " -> " << duration.count() << "s" << std::endl;
}

template <typename Num>
bool ThreadWrapper<Num>::isFinished()
{
    return (this->_finished.load());
    // return (this->_finished);
};

template <typename Num>
void ThreadWrapper<Num>::join()
{
    this->_thread.join();
};

#endif