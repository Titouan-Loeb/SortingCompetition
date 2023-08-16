#include <criterion/criterion.h>
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "CocktailShakerSort.hpp"
#include "BogoSort.hpp"
#include "CheckArrays.hpp"

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

void testAllSort(std::vector<int> array, std::vector<int> sortedArray)
{
    cr_expect(compareLists(BubbleSort<int>::sort(array), sortedArray), "BubbleSort: Lists are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(array), sortedArray), "InsertionSort: Lists are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(array), sortedArray), "SelectionSort: Lists are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(array), sortedArray), "CocktailShakerSort: Lists are not equal");
}

Test(TestingAlgo, BubbleSort)
{
    cr_expect(compareLists(BubbleSort<int>::sort(stupid), stupid_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(easy1), easy1_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(easy2), easy2_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(medium1), medium1_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(medium2), medium2_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(hard1), hard1_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(hard2), hard2_sorted));
    cr_expect(compareLists(BubbleSort<int>::sort(veryHard), veryHard_sorted));
}

Test(TestingAlgo, InsertionSort)
{
    cr_expect(compareLists(InsertionSort<int>::sort(stupid), stupid_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(easy1), easy1_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(easy2), easy2_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(medium1), medium1_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(medium2), medium2_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(hard1), hard1_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(hard2), hard2_sorted));
    cr_expect(compareLists(InsertionSort<int>::sort(veryHard), veryHard_sorted));
}

Test(TestingAlgo, SelectionSort)
{
    cr_expect(compareLists(SelectionSort<int>::sort(stupid), stupid_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(easy1), easy1_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(easy2), easy2_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(medium1), medium1_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(medium2), medium2_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(hard1), hard1_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(hard2), hard2_sorted));
    cr_expect(compareLists(SelectionSort<int>::sort(veryHard), veryHard_sorted));
}

Test(TestingAlgo, CocktailShakerSort)
{
    cr_expect(compareLists(CocktailShakerSort<int>::sort(stupid), stupid_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(easy1), easy1_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(easy2), easy2_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(medium1), medium1_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(medium2), medium2_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(hard1), hard1_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(hard2), hard2_sorted));
    cr_expect(compareLists(CocktailShakerSort<int>::sort(veryHard), veryHard_sorted));
}

Test(TestingAlgo, BogoSort)
{
    cr_expect(compareLists(BogoSort<int>::sort(stupid), stupid_sorted));
}