#include <string>
#include <iostream>
#include <thread>

#include "BubbleSort.hpp"
#include "PushToSortedList.hpp"
#include "Challenger.hpp"

void testThread()
{
    std::cout << "hello" << std::endl;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    std::mutex mutex;
    std::vector<int> array = {5, 12, -1, 0, 2};
    Challenger<int> chal(array);
    chal.challengeAll();
    printArray<int>("PushToSortedList", PushToSortedList<int>::sort(array));
    return (0);
}