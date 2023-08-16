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

Test(TestingAlgo, BubbleSort)
{
    cr_expect(compareLists(BubbleSort<int>::sort(stupid), stupid_sorted), "BubbleSort stupid: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(easy1), easy1_sorted), "BubbleSort easy1: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(easy2), easy2_sorted), "BubbleSort easy2: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(medium1), medium1_sorted), "BubbleSort medium1: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(medium2), medium2_sorted), "BubbleSort medium2: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(hard1), hard1_sorted), "BubbleSort hard1: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(hard2), hard2_sorted), "BubbleSort hard2: arrays are not equal");
    cr_expect(compareLists(BubbleSort<int>::sort(veryHard), veryHard_sorted), "BubbleSort veryHard: arrays are not equal");
}

Test(TestingAlgo, InsertionSort)
{
    cr_expect(compareLists(InsertionSort<int>::sort(stupid), stupid_sorted), "InsertionSort stupid: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(easy1), easy1_sorted), "InsertionSort easy1: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(easy2), easy2_sorted), "InsertionSort easy2: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(medium1), medium1_sorted), "InsertionSort medium1: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(medium2), medium2_sorted), "InsertionSort medium2: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(hard1), hard1_sorted), "InsertionSort hard1: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(hard2), hard2_sorted), "InsertionSort hard2: arrays are not equal");
    cr_expect(compareLists(InsertionSort<int>::sort(veryHard), veryHard_sorted), "InsertionSort veryHard: arrays are not equal");
}

Test(TestingAlgo, SelectionSort)
{
    cr_expect(compareLists(SelectionSort<int>::sort(stupid), stupid_sorted), "SelectionSort stupid: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(easy1), easy1_sorted), "SelectionSort easy1: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(easy2), easy2_sorted), "SelectionSort easy2: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(medium1), medium1_sorted), "SelectionSort medium1: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(medium2), medium2_sorted), "SelectionSort medium2: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(hard1), hard1_sorted), "SelectionSort hard1: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(hard2), hard2_sorted), "SelectionSort hard2: arrays are not equal");
    cr_expect(compareLists(SelectionSort<int>::sort(veryHard), veryHard_sorted), "SelectionSort veryHard: arrays are not equal");
}

Test(TestingAlgo, CocktailShakerSort)
{
    cr_expect(compareLists(CocktailShakerSort<int>::sort(stupid), stupid_sorted), "CocktailShakerSort stupid: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(easy1), easy1_sorted), "CocktailShakerSort easy1: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(easy2), easy2_sorted), "CocktailShakerSort easy2: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(medium1), medium1_sorted), "CocktailShakerSort medium1: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(medium2), medium2_sorted), "CocktailShakerSort medium2: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(hard1), hard1_sorted), "CocktailShakerSort hard1: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(hard2), hard2_sorted), "CocktailShakerSort hard2: arrays are not equal");
    cr_expect(compareLists(CocktailShakerSort<int>::sort(veryHard), veryHard_sorted), "CocktailShakerSort veryHard: arrays are not equal");
}

Test(TestingAlgo, BogoSort)
{
    cr_expect(compareLists(BogoSort<int>::sort(stupid), stupid_sorted), "stupid: arrays are not equal");
}