#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class QuickSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> run(const std::atomic<bool> &timeout);
    Num findPivot(const size_t &first, const size_t &last);
    void pivotAndSort(const std::atomic<bool> &timeout, const size_t &first, const size_t &last);

public:
    QuickSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array) {};
    ~QuickSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        QuickSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        QuickSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> QuickSort<Num>::run(const std::atomic<bool> &timeout)
{
    pivotAndSort(timeout, 0, this->_array.size() - 1);
    return (this->_array);
}

template <typename Num>
Num QuickSort<Num>::findPivot(const size_t &first, const size_t &last)
{
    size_t idx1 = first;
    size_t idx2 = (first + last) / 2;
    size_t idx3 = last;

    if (this->_array[idx1] > this->_array[idx2])
        std::swap(this->_array[idx1], this->_array[idx2]);
    if (this->_array[idx2] > this->_array[idx3])
        std::swap(this->_array[idx2], this->_array[idx3]);
    if (this->_array[idx1] > this->_array[idx2])
        std::swap(this->_array[idx1], this->_array[idx2]);
    std::swap(this->_array[idx2], this->_array[idx3]);
    return (this->_array[idx3]);
}

template <typename Num>
void QuickSort<Num>::pivotAndSort(const std::atomic<bool> &timeout, const size_t &first, const size_t &last)
{
    if (timeout.load())
        throw TimeoutException();
    if (this->isSorted(std::vector<Num>(this->_array.begin() + first, this->_array.begin() + last + 1)))
        return;

    Num pivot = findPivot(first, last);
    int swap = first - 1;

    for (size_t i = first; i <= last - 1; i++)
        if (this->_array[i] <= pivot) {
            swap++;
            if (swap < (int) i)
                std::swap(this->_array[swap], this->_array[i]);
        }
    size_t pivotNewIdx = swap + 1;
    std::swap(this->_array[pivotNewIdx], this->_array[last]);
    pivotAndSort(timeout, first, pivotNewIdx - 1);
    pivotAndSort(timeout, pivotNewIdx + 1, last);

    // Num pivot = findPivot(first, last);
    // size_t leftIdx = first;
    // size_t rightIdx = last - 1;

    // //pivot elements
    // while (leftIdx < rightIdx) {
    //     while (leftIdx < rightIdx && this->_array[leftIdx] <= pivot && leftIdx < last - 1)
    //         leftIdx++;
    //     while (leftIdx < rightIdx && this->_array[rightIdx] > pivot && rightIdx > first)
    //         rightIdx--;
    //     if (leftIdx >= rightIdx)
    //         break;
    //     std::swap(this->_array[leftIdx++], this->_array[rightIdx--]);
    // }
    // size_t pivotNewIdx = leftIdx;
    // if (this->_array[leftIdx] <= pivot && leftIdx < last - 1)
    //     pivotNewIdx = leftIdx + 1;
    // std::swap(this->_array[last], this->_array[pivotNewIdx]);
    // // sort the two parts
    // pivotAndSort(timeout, first, pivotNewIdx - 1);
    // if (timeout.load())
    //     throw TimeoutException();
    // pivotAndSort(timeout, pivotNewIdx + 1, last);
    // if (timeout.load())
    //     throw TimeoutException();
}


#endif /* !QUICK_SORT_HPP */