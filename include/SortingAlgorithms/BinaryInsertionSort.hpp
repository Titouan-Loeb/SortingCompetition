#ifndef BINARY_INSERTION_HPP
#define BINARY_INSERTION_HPP

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class BinaryInsertionSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> _sortedList;
    
    std::vector<Num> run(const std::atomic<bool> &timeout);

public:
    BinaryInsertionSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array) {};
    ~BinaryInsertionSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        BinaryInsertionSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        BinaryInsertionSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> BinaryInsertionSort<Num>::run(const std::atomic<bool> &timeout)
{
    while (!timeout.load() && !this->_array.empty()) {
        if (this->_sortedList.empty()) {
            this->_sortedList.push_back(this->_array[0]);
        } else if (this->_array[0] > this->_sortedList[this->_sortedList.size() - 1]) {
            this->_sortedList.insert(this->_sortedList.end(), this->_array[0]);
        } else if (this->_array[0] < this->_sortedList[0]) {
            this->_sortedList.insert(this->_sortedList.begin(), this->_array[0]);
        } else {
            int leftBound = 0;
            int rightBound = this->_sortedList.size() - 1;
            while (1) {
                if (leftBound > rightBound) {
                    this->_sortedList.insert(this->_sortedList.begin() + leftBound, this->_array[0]);
                    break;
                }
                int middle = (leftBound + rightBound) / 2;
                if (this->_array[0] > this->_sortedList[middle]) {
                    if (leftBound == rightBound) {
                        this->_sortedList.insert(this->_sortedList.begin() + middle + 1, this->_array[0]);
                        break;
                    } else {
                        leftBound = middle + 1;
                    }
                } else if (this->_array[0] < this->_sortedList[middle]) {
                    if (leftBound == rightBound) {
                        this->_sortedList.insert(this->_sortedList.begin() + middle, this->_array[0]);
                        break;
                    } else {
                        rightBound = middle - 1;
                    }
                } else {
                    this->_sortedList.insert(this->_sortedList.begin() + middle, this->_array[0]);
                    break;
                }
            }
        }
        this->_array.erase(this->_array.begin());
    }
    if (timeout)
        throw TimeoutException();
    return (this->_sortedList);
}


#endif // BINARY_INSERTION_HPP