#include <string>
#include <iostream>

#include "BubbleSort.hpp"
#include "PushToSortedList.hpp"

template <typename Num>
void printArray(const std::string &algoName, const std::vector<Num> &array)
{
    std::cout << algoName << " : "; 
    for (size_t i = 0; i < array.size(); i++) {
        if (i + 1 < array.size())
            std::cout << array[i] << ", ";
        else
            std::cout << array[i] << std::endl;
    }
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    std::vector<int> array = {5, 12, -1, 0, 2};
    printArray<int>("BubbleSort", BubbleSort<int>::sort(array));
    printArray<int>("PushToSortedList", PushToSortedList<int>::sort(array));
    return (0);
}