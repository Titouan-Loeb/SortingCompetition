#ifndef BOGO_SORT_HPP
#define BOGO_SORT_HPP

#include <random>

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class BogoSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> run(const std::atomic<bool> &timeout);

public:
    BogoSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array) {};
    ~BogoSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        BogoSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };
    
    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        BogoSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> BogoSort<Num>::run(const std::atomic<bool> &timeout)
{
    while (!timeout.load() && !this->isSorted()) {
        std::random_shuffle(this->_array.begin(), this->_array.end());
    }
    if (timeout)
        throw TimeoutException();
    return (this->_array);
}

#endif // BOGO_SORT_HPP