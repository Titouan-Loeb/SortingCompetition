#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"

template <typename Num>
class BubbleSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> run(); 
    std::vector<Num> runWithTimeout(const std::atomic<bool> &timeout);

public:
    BubbleSort(const std::vector<Num> &array);
    ~BubbleSort();
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        BubbleSort<Num> algo(array);
        return (algo.run());
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        BubbleSort<Num> algo(array);
        return (algo.runWithTimeout(timeout));
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
std::vector<Num> BubbleSort<Num>::run()
{
    while (!this->isSorted()) {
        for (std::size_t i = 0; i < this->_array.size() - 1; i++) {
            if (this->_array[i] > this->_array[i + 1])
                std::swap(this->_array[i], this->_array[i + 1]);
        }
    }
    return (this->_array);
}

template <typename Num>
std::vector<Num> BubbleSort<Num>::runWithTimeout(const std::atomic<bool> &timeout)
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