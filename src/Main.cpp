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
    std::vector<int> array = {-87, -24, -93, 63, -83, -87, 57, 40, 86, -64};
    Challenger<int> chal(array);
    chal.challengeAll();
    return (0);
}