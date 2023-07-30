#include "BubbleSort.hpp"


int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    std::vector<int> array = {5, 12, -1, 0, 2};
    BubbleSort<int>::sort(array);
    return (0);
}