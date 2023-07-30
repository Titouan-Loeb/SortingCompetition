#ifndef ISORTINGALGO_HPP
#define ISORTINGALGO_HPP

#include <vector>

template <typename Num>
class ISortingAlgo
{
protected:
    virtual void run() = 0;
public:
    ~ISortingAlgo() = default;
    virtual void sort(std::vector<Num> &array);
};

#endif // ISORTINGALGO_HPP