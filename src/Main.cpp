#include <string>
#include <iostream>
#include <thread>

#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "Challenger.hpp"

int main(int argc, char** argv)
{
    if (argc == 2 && argv[1] == std::string("-h")) {
        std::cout << "Usage: " << argv[0] << std::endl;
        return (0);
    }
    if (argc != 1) {
        std::cout << "Usage: " << argv[0] << std::endl;
        return (1);
    }
    std::vector<int> array = {-87, -24, -93, 63, -83, -87, 57, 40, 86, -64};
    Challenger<int> chal(array);
    chal.challengeAll();
    return (0);
}