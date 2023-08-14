#include <string>
#include <iostream>

#include "Challenger.hpp"
#include "MassiveArray.hpp"



void printUsage(const std::string &binName)
{
    std::cout << "Usage: " << binName << "[-t timeout(ms)]" << std::endl;
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