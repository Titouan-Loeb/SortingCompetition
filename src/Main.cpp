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
    std::vector<int> array = {5, 12, -1, 0, 2, 8, 501, -66, 41, 9, 0, -8001};
    Challenger<int> chal(array);
    chal.challengeAll();
    return (0);
}