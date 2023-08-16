#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class InsertionSort : public ASortingAlgo<Num>
{
private:
    std::vector<Num> _sortedList;

    std::vector<Num> run(const std::atomic<bool> &timeout);

public:
    InsertionSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array) {};
    ~InsertionSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        InsertionSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };
    
    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        InsertionSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> InsertionSort<Num>::run(const std::atomic<bool> &timeout)
{
    while (!timeout.load() && !this->_array.empty()) {
        if (this->_sortedList.empty()) {
            this->_sortedList.push_back(this->_array[0]);
        } else {
            for (size_t i = 0; i < this->_sortedList.size(); i++) {
                if (this->_array[0] > this->_sortedList[i]) {
                    if (i + 1 < this->_sortedList.size())
                        continue;
                    else {
                        this->_sortedList.push_back(this->_array[0]);
                        break;
                    }
                } else {
                    this->_sortedList.insert(this->_sortedList.begin() + i, this->_array[0]);
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

#endif // INSERTIONSORT_HPP