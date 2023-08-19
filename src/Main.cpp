#include <string>
#include <iostream>

#include "Challenger.hpp"
#include "MassiveArray.hpp"

#include "DoubleSelectionSort.hpp"

void printUsage(const std::string &binName)
{
    std::cout << "Usage: " << binName << " [-t timeout(ms)]" << std::endl;
}

void printArray(const std::vector<int> array)
{
    for (size_t i = 0; i < array.size(); i++) {
        std::cout << array[i] << " < ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    Challenger<int> chal(massiveArray);
    
    if (argc == 1) {
        chal.challengeAll();;
        return (0);
    }
    if (argc == 2 && argv[1] == std::string("-h")) {
        printUsage(argv[0]);
        return (0);
    }
    if (argc == 3 && argv[1] == std::string("-t")) {
        int timeLimit = std::stoi(argv[2]);
        chal.challengeAllWithTimeout(timeLimit);
        return (0);
    }
    printUsage(argv[0]);
    return (1);
}

// int main()
// {
//     Challenger<int> chal(arrayEasy2);
//     chal.challengeSpecific((uint32_t)SortAlgoFlags::QUICK_SORT);
// }