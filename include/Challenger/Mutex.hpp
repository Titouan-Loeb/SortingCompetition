#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <mutex>
#include <atomic>

std::mutex synchronizer;
std::atomic<bool> timeout = false;

#endif