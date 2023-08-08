#ifndef SORTINGALGOSTRUCT_HPP
#define SORTINGALGOSTRUCT_HPP

#include <vector>
#include <string>

template <typename Num>
using AlgoPrototype = std::vector<Num> (*)(const std::vector<Num>&);

enum class SortAlgoFlags
{
    BUBBLE_SORT = 0b1,
    INSERTION_SORT = 0b10,
    SELECTION_SORT = 0b100,
    MAX = 0b1000,
};

template <typename Num>
struct AlgoInfoStruct
{
    SortAlgoFlags flag;
    std::string name;
    AlgoPrototype<Num> func;
};

#endif // ISORTINGALGO_HPP