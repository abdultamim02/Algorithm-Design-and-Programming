#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "QuickSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"

using namespace std;

void IntoSortUtil(vector<int> &arr, int left, int right, int depthLimit)
{
    if (right - left <= 16) // If the size of the array is small, use InsertionSort
    {
        InsertionSort(arr, left, right); // Sort the array using InsertionSort
    }
    else if (depthLimit == 0) // If the depth limit is reached, use HeapSort
    {
        HeapSort(arr, left, right); // Sort the array using HeapSort
    }
    else
    {
        int pivotIndex = Partition(arr, left, right);             // Partition the array
        IntoSortUtil(arr, left, pivotIndex, depthLimit - 1);      // Sort the left part
        IntoSortUtil(arr, pivotIndex + 1, right, depthLimit - 1); // Sort the right part
    }
}

void IntroSort(vector<int> &arr, int low, int high)
{
    int depthLimit = 2 * log2(high - low + 1); // Calculate the depth limit for Introsort
    IntoSortUtil(arr, low, high, depthLimit);  // Call the utility function to sort the array
}