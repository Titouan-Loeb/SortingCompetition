#ifndef ASORTINGALGO_HPP
#define ASORTINGALGO_HPP

#include "ISortingAlgo.hpp"

template <typename Num>
class ASortingAlgo // : public ISortingAlgo<Num>
{
protected:
    std::vector<Num> _array;
    virtual bool isSorted() final;

public:
    ASortingAlgo(const std::vector<Num> &array);
    ~ASortingAlgo();
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
ASortingAlgo<Num>::ASortingAlgo(const std::vector<Num> &array)
{
    this->_array = array;
}

template <typename Num>
ASortingAlgo<Num>::~ASortingAlgo()
{
    this->_array.clear();
}

template <typename Num>
bool ASortingAlgo<Num>::isSorted()
{
    for (std::size_t i = 0; i < this->_array.size() - 1; i++)
        if (this->_array[i] > this->_array[i + 1])
            return (false);
    return (true);
}

#endif // ASORTINGALGO_HPP