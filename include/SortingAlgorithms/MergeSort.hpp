#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "ASortingAlgo.hpp"
#include "Mutex.hpp"

template <typename Num>
class MergeSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> run(const std::atomic<bool> &timeout);
    std::vector<Num> splitAndSort(const std::atomic<bool> &timeout, const std::vector<Num> &arrayToSort);
    std::vector<Num> merge(const std::vector<Num> &firstHalf, const std::vector<Num> &secondHalf);

public:
    MergeSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array) {};
    ~MergeSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        MergeSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        MergeSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> MergeSort<Num>::run(const std::atomic<bool> &timeout)
{
    return (splitAndSort(timeout, this->_array));
}

template <typename Num>
std::vector<Num> MergeSort<Num>::splitAndSort(const std::atomic<bool> &timeout, const std::vector<Num> &arrayToSort)
{
    if (timeout.load())
        throw TimeoutException();
    if (this->isSorted(arrayToSort))
        return (arrayToSort);

    if (arrayToSort.size() <= 1)
        return (arrayToSort);
    std::vector<Num> leftHalf(arrayToSort.begin(), arrayToSort.begin() + arrayToSort.size() / 2);
    std::vector<Num> rightHalf(arrayToSort.begin() + arrayToSort.size() / 2, arrayToSort.end());
    
    leftHalf = splitAndSort(timeout, leftHalf);
    rightHalf = splitAndSort(timeout, rightHalf);
    
    return (merge(leftHalf, rightHalf));
}

template <typename Num>
std::vector<Num> MergeSort<Num>::merge(const std::vector<Num> &leftHalf, const std::vector<Num> &rightHalf)
{
    size_t leftCursor = 0;
    size_t rightCursor = 0;
    std::vector<Num> mergedArray;

    while (leftCursor != leftHalf.size() && rightCursor != rightHalf.size())
    {
        if (leftHalf[leftCursor] < rightHalf[rightCursor])
            mergedArray.push_back(leftHalf[leftCursor++]);
        else
            mergedArray.push_back(rightHalf[rightCursor++]);
    }
    if (leftCursor != leftHalf.size())
        mergedArray.insert(mergedArray.end(), leftHalf.begin() + leftCursor, leftHalf.end());
    if (rightCursor != rightHalf.size())
        mergedArray.insert(mergedArray.end(), rightHalf.begin() + rightCursor, rightHalf.end());
    return (mergedArray);
}


#endif /* !MERGE_SORT_HPP */