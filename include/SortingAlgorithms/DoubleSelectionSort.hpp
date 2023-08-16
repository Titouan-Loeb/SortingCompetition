#ifndef DOUBLE_SELECTIONSORT_HPP
#define DOUBLE_SELECTIONSORT_HPP

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class DoubleSelectionSort : public ASortingAlgo<Num>
{
private:
    size_t _currentMinIndex;
    size_t _currentMaxIndex;

    std::vector<Num> run(const std::atomic<bool> &timeout);
    std::pair<size_t, size_t> findMinAndMax();

public:
    DoubleSelectionSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array)
    {
        this->_currentMinIndex = 0;
        this->_currentMaxIndex = array.size() - 1;
    };
    ~DoubleSelectionSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        DoubleSelectionSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        DoubleSelectionSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> DoubleSelectionSort<Num>::run(const std::atomic<bool> &timeout)
{
    while (!timeout.load() && this->_currentMinIndex < this->_currentMaxIndex) {
        std::pair<size_t, size_t> MinAndMaxIndexes = findMinAndMax();
        if (MinAndMaxIndexes.second == this->_currentMinIndex && MinAndMaxIndexes.first == this->_currentMaxIndex) {
            std::swap(this->_array[this->_currentMinIndex++], this->_array[this->_currentMaxIndex--]);
        } else if (MinAndMaxIndexes.second == this->_currentMinIndex) {
            std::swap(this->_array[this->_currentMaxIndex--], this->_array[MinAndMaxIndexes.second]);
            std::swap(this->_array[this->_currentMinIndex++], this->_array[MinAndMaxIndexes.first]);
        } else {
            std::swap(this->_array[this->_currentMinIndex++], this->_array[MinAndMaxIndexes.first]);
            std::swap(this->_array[this->_currentMaxIndex--], this->_array[MinAndMaxIndexes.second]);
        }
    }
    if (timeout)
        throw TimeoutException();
    return (this->_array);
}

template <typename Num>
std::pair<size_t, size_t> DoubleSelectionSort<Num>::findMinAndMax()
{
    Num min = this->_array[this->_currentMinIndex];
    Num max = this->_array[this->_currentMaxIndex];
    size_t minIndex = this->_currentMinIndex;
    size_t maxIndex = this->_currentMaxIndex;
    for (size_t i = this->_currentMinIndex; i <= this->_currentMaxIndex; i++) {
        if (this->_array[i] < min) {
            min = this->_array[i];
            minIndex = i;
        }
        if (this->_array[i] > max) {
            max = this->_array[i];
            maxIndex = i;
        }
    }
    return (std::pair<size_t, size_t> (minIndex, maxIndex));
}

#endif /* !DOUBLE_SELECTIONSORT_HPP */