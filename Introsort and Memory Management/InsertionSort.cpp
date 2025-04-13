#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "insertionSort.h"

using namespace std;

void InsertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i]; // The element to be inserted
        int j = i - 1;    // Index of the last sorted element

        // Move elements of arr[low..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move element to the right
            j--;                 // Decrement j to check the next element
        }
        arr[j + 1] = key; // Insert key at the correct position
    }
}