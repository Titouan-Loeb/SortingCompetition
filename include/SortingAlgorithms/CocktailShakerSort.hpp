#ifndef COCKTAILSHAKERSORT_HPP
#define COCKTAILSHAKERSORT_HPP

#include <atomic>

#include "ASortingAlgo.hpp"
#include "CustomException.hpp"
#include "Mutex.hpp"

template <typename Num>
class CocktailShakerSort : public ASortingAlgo<Num>
{
private:
    size_t _maxIndex;
    size_t _minIndex;

    std::vector<Num> run(const std::atomic<bool> &timeout);
    size_t findMinIndex();
    size_t findMaxIndex();

public:
    CocktailShakerSort(const std::vector<Num> &array) : ASortingAlgo<Num>(array)
    {
        this->_minIndex = 0;
        this->_maxIndex = this->_array.size() - 1;
    };
    ~CocktailShakerSort() {};
    
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        CocktailShakerSort<Num> algo(array);
        std::atomic<bool> timeout(false);
        return (algo.run(timeout));
    };

    static std::vector<Num> sortWithTimeout(const std::vector<Num> &array, const std::atomic<bool> &timeout)
    {
        CocktailShakerSort<Num> algo(array);
        return (algo.run(timeout));
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
std::vector<Num> CocktailShakerSort<Num>::run(const std::atomic<bool> &timeout)
{
    while (!timeout.load() && this->_minIndex < this->_maxIndex) {
        size_t minIndex = findMinIndex();
        std::swap(this->_array[this->_minIndex], this->_array[minIndex]);        
        this->_minIndex++;
        size_t maxIndex = findMaxIndex();
        std::swap(this->_array[this->_maxIndex], this->_array[maxIndex]);
        this->_maxIndex--;
    }
    if (timeout)
        throw TimeoutException();
    return (this->_array);
}

template <typename Num>
size_t CocktailShakerSort<Num>::findMinIndex()
{
    Num min = this->_array[this->_minIndex];
    size_t minIndex = this->_minIndex;
    for (size_t i = this->_minIndex + 1; i <= this->_maxIndex; i++) {
        if (this->_array[i] < min) {
            min = this->_array[i];
            minIndex = i;
        }
    }
    return (minIndex);
}

template <typename Num>
size_t CocktailShakerSort<Num>::findMaxIndex()
{
    Num max = this->_array[this->_maxIndex];
    size_t maxIndex = this->_maxIndex;
    for (size_t i = this->_maxIndex - 1; i >= this->_minIndex; i--) {
        if (this->_array[i] > max) {
            max = this->_array[i];
            maxIndex = i;
        }
    }
    return (maxIndex);
}


#endif // COCKTAILSHAKERSORT_HPP