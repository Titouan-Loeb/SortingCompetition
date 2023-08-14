#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class BubbleSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> run(const std::atomic<bool> &timeout);

public:
    BubbleSort(const std::vector<Num> &array);
    ~BubbleSort();
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        BubbleSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        BubbleSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
BubbleSort<Num>::BubbleSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array)
{
}

template <typename Num>
BubbleSort<Num>::~BubbleSort()
{
}

template <typename Num>
std::vector<Num> BubbleSort<Num>::run(const std::atomic<bool> &timeout)
{
    while (!timeout.load() && !this->isSorted()) {
        for (std::size_t i = 0; i < this->_array.size() - 1; i++) {
            if (this->_array[i] > this->_array[i + 1])
                std::swap(this->_array[i], this->_array[i + 1]);
        }
    }
    if (timeout)
        throw TimeoutException();
    return (this->_array);
}

#endif // BUBBLESORT_HPP