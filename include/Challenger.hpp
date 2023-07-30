#ifndef CHALLENGER_HPP
#define CHALLENGER_HPP

#include <vector>
#include "ISortingAlgo.hpp"

enum class SortingAlorithmFlags
{
    BUBBLE_SORT = 0b1,
};

template <typename Num>
class Challenger
{
private:
public:
    Challenger(std::vector<Num>) {}
    ~Challenger() {}

    void challengeAll();
    void challengeSpecific(SortingAlorithmFlags algos);
};

#endif // CHALLENGER_HPP