#ifndef ASORTINGALGO_HPP
#define ASORTINGALGO_HPP

#include <vector>

template <typename Num>
class ASortingAlgo
{
protected:
    std::vector<Num> _array;

    virtual bool isSorted() final;
    virtual bool isSorted(const std::vector<Num> &array) final;
    virtual std::vector<Num> run(const std::atomic<bool> &timeout) = 0;

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
    for (size_t i = 1; i < this->_array.size(); i++)
        if (this->_array[i - 1] > this->_array[i])
            return (false);
    return (true);
}

template <typename Num>
bool ASortingAlgo<Num>::isSorted(const std::vector<Num> &array)
{
    for (size_t i = 1; i < array.size(); i++)
        if (array[i - 1] > array[i])
            return (false);
    return (true);
}

#endif // ASORTINGALGO_HPP