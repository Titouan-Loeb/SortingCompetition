#include <string>
#include <iostream>
#include <thread>

#include "Challenger.hpp"
#include "MassiveArray.hpp"
#include "ASortingAlgo.hpp"

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
    Challenger<int> chal(massiveArray);
    chal.challengeAll();
    return (0);
}