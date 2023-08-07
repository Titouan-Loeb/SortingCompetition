#include <criterion/criterion.h>
#include <BubbleSort.hpp>
#include <PushToSortedList.hpp>


bool compareLists(std::vector<int> array, std::vector<int> arraySorted)
{
    if (array.size() != arraySorted.size())
        return false;
    for (size_t i = 0; i < array.size(); i++) {
        if (array[i] != arraySorted[i])
            return false;
    }
    return true;
}

Test(queuetests, create) {
    std::vector<int> array = {5, 4, 3, 2, 1};
    std::vector<int> arraySorted = BubbleSort<int>::sort(array);
    cr_expect(compareLists(arraySorted, {1, 2, 3, 4, 5}) == true, "Lists are not equal");
}