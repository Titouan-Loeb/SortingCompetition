#ifndef SORTINGALGOSTRUCT_HPP
#define SORTINGALGOSTRUCT_HPP

#include <vector>
#include <string>

template <typename Num>
using AlgoPrototype = std::vector<Num> (*)(const std::vector<Num>&, const std::atomic<bool> &);

enum class SortAlgoFlags
{
    BUBBLE_SORT = 0b1,
    INSERTION_SORT = 0b10,
    SELECTION_SORT = 0b100,
    COCKTAIL_SHAKER_SORT = 0b1000,
    MAX = 0b10000,
};

template <typename Num>
struct AlgoInfoStruct
{
    SortAlgoFlags flag;
    std::string name;
    AlgoPrototype<Num> func;
};

#endif // ISORTINGALGO_HPP