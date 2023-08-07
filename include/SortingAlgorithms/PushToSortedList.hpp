#ifndef PUSHTOSORTEDLIST_HPP
#define PUSHTOSORTEDLIST_HPP

#include <vector>

#include "ASortingAlgo.hpp"

template <typename Num>
class PushToSortedList : public ASortingAlgo<Num>
{
private:
    std::vector<Num> _sortedList;

    std::vector<Num> run();

public:
    PushToSortedList(const std::vector<Num> &array);
    ~PushToSortedList();
    static std::vector<Num> sort(const std::vector<Num> &array)
    {
        PushToSortedList<Num> algo(array);
        return (algo.run());
    };
};

// ------------------------------
// IMPLEMENTATION
// ------------------------------

template <typename Num>
PushToSortedList<Num>::PushToSortedList(const std::vector<Num> &array) : ASortingAlgo<Num>(array)
{
}

template <typename Num>
PushToSortedList<Num>::~PushToSortedList()
{
}

template <typename Num>
std::vector<Num> PushToSortedList<Num>::run()
{
    while (!this->_array.empty()) {
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
    return (this->_sortedList);
}

#endif // PUSHTOSORTEDLIST_HPP