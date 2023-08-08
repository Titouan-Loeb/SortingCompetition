#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "ASortingAlgo.hpp"

template <typename Num>
class SelectionSort : public ASortingAlgo<Num>
{
private:
    size_t _currentIndex;
    std::vector<Num> run();
    size_t findMinIndex();

public:
    SelectionSort(const std::vector<Num> &array);
    ~SelectionSort();
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        SelectionSort<Num> algo(array);
        return (algo.run());
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
SelectionSort<Num>::SelectionSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array)
{
    this->_currentIndex = 0;
}

template <typename Num>
SelectionSort<Num>::~SelectionSort()
{
}

template <typename Num>
std::vector<Num> SelectionSort<Num>::run()
{
    while (this->_currentIndex < this->_array.size()) {
        size_t minIndex = findMinIndex();
        std::swap(this->_array[this->_currentIndex], this->_array[minIndex]);
        this->_currentIndex++;
    }
    return (this->_array);
}

template <typename Num>
size_t SelectionSort<Num>::findMinIndex()
{
    Num min = this->_array[this->_currentIndex];
    size_t minIndex = this->_currentIndex;
    for (size_t i = minIndex + 1; i < this->_array.size(); i++) {
        if (this->_array[i] < min) {
            min = this->_array[i];
            minIndex = i;
        }
    }
    return (minIndex);
}

#endif /* !SELECTIONSORT_HPP */