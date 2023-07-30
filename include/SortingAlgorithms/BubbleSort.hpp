#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include "ASortingAlgo.hpp"
#include <iostream> //TODO: remove

template <typename Num>
class BubbleSort : public ASortingAlgo<Num>
{
public:
    BubbleSort(const std::vector<Num> &array);
    ~BubbleSort();
    static void sort(std::vector<Num> &array)
    {
        BubbleSort<Num> algo(array);
        algo.run();
    };

private:
    void run();
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
void BubbleSort<Num>::run()
{
    while (!this->isSorted()) {
        for (std::size_t i = 0; i < this->_array.size() - 1; i++) {
            if (this->_array[i] > this->_array[i + 1])
                std::swap(this->_array[i], this->_array[i + 1]);
        }
    }
    for (std::size_t i = 0; i < this->_array.size(); i++)
        std::cout << this->_array[i] << " ";
    std::cout << std::endl;
}

#endif // BUBBLESORT_HPP