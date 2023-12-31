#include <criterion/criterion.h>

#include "CheckArrays.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "CocktailShakerSort.hpp"
#include "BogoSort.hpp"
#include "DoubleSelectionSort.hpp"
#include "BinaryInsertionSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"    

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

Test(TestingAlgo, DoubleSelectionSort)
{
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(stupid), stupid_sorted), "DoubleSelectionSort stupid: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(easy1), easy1_sorted), "DoubleSelectionSort easy1: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(easy2), easy2_sorted), "DoubleSelectionSort easy2: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(medium1), medium1_sorted), "DoubleSelectionSort medium1: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(medium2), medium2_sorted), "DoubleSelectionSort medium2: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(hard1), hard1_sorted), "DoubleSelectionSort hard1: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(hard2), hard2_sorted), "DoubleSelectionSort hard2: arrays are not equal");
    cr_expect(compareLists(DoubleSelectionSort<int>::sort(veryHard), veryHard_sorted), "DoubleSelectionSort veryHard: arrays are not equal");
}

Test(TestingAlgo, BinaryInsertionSort)
{
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(stupid), stupid_sorted), "BinaryInsertionSort stupid: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(easy1), easy1_sorted), "BinaryInsertionSort easy1: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(easy2), easy2_sorted), "BinaryInsertionSort easy2: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(medium1), medium1_sorted), "BinaryInsertionSort medium1: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(medium2), medium2_sorted), "BinaryInsertionSort medium2: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(hard1), hard1_sorted), "BinaryInsertionSort hard1: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(hard2), hard2_sorted), "BinaryInsertionSort hard2: arrays are not equal");
    cr_expect(compareLists(BinaryInsertionSort<int>::sort(veryHard), veryHard_sorted), "BinaryInsertionSort veryHard: arrays are not equal");
}

Test(TestingAlgo, MergeSort)
{
    cr_expect(compareLists(MergeSort<int>::sort(stupid), stupid_sorted), "MergeSort stupid: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(easy1), easy1_sorted), "MergeSort easy1: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(easy2), easy2_sorted), "MergeSort easy2: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(medium1), medium1_sorted), "MergeSort medium1: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(medium2), medium2_sorted), "MergeSort medium2: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(hard1), hard1_sorted), "MergeSort hard1: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(hard2), hard2_sorted), "MergeSort hard2: arrays are not equal");
    cr_expect(compareLists(MergeSort<int>::sort(veryHard), veryHard_sorted), "MergeSort veryHard: arrays are not equal");
}

Test(TestingAlgo, QuickSort)
{
    cr_expect(compareLists(QuickSort<int>::sort(stupid), stupid_sorted), "QuickSort stupid: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(easy1), easy1_sorted), "QuickSort easy1: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(easy2), easy2_sorted), "QuickSort easy2: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(medium1), medium1_sorted), "QuickSort medium1: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(medium2), medium2_sorted), "QuickSort medium2: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(hard1), hard1_sorted), "QuickSort hard1: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(hard2), hard2_sorted), "QuickSort hard2: arrays are not equal");
    cr_expect(compareLists(QuickSort<int>::sort(veryHard), veryHard_sorted), "QuickSort veryHard: arrays are not equal");
}