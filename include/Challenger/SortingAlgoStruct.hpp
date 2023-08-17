#ifndef SORTINGALGOSTRUCT_HPP
#define SORTINGALGOSTRUCT_HPP

#include <vector>
#include <string>

template <typename Num>
using AlgoPrototypeWithTimeout = std::vector<Num> (*)(const std::vector<Num>&, const std::atomic<bool> &);

template <typename Num>
using AlgoPrototype = std::vector<Num> (*)(const std::vector<Num>&);

enum class SortAlgoFlags : uint32_t
{
    BUBBLE_SORT = 0b1,
    INSERTION_SORT = 0b10,
    SELECTION_SORT = 0b100,
    COCKTAIL_SHAKER_SORT = 0b1000,
    BOGO_SORT = 0b10000,
    DOUBLE_SELECTION_SORT = 0b100000,
    BINARY_INSERTION_SORT = 0b1000000,
    MERGE_SORT = 0b10000000,
    ALL_SORTING_ALGO = 0b11111111,
};

template <typename Num>
struct AlgoInfoStruct
{
    SortAlgoFlags flag;
    std::string name;
    AlgoPrototypeWithTimeout<Num> funcTimeout;
};

#endif // SORTINGALGOSTRUCT_HPP