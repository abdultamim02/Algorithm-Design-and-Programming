#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "QuickSort.h"
#include "swap_utils.h"

using namespace std;

int MedianOfThree(vector<int> &arr, int left, int right)
{
    int mid = left + (right - left) / 2; // Calculate mid index

    // Ensure arr[left] <= arr[mid] <= arr[right]
    if (arr[mid] < arr[left])
        Swap_With_Pool(arr[mid], arr[left]);
    if (arr[right] < arr[left])
        Swap_With_Pool(arr[right], arr[left]);
    if (arr[right] < arr[mid])
        Swap_With_Pool(arr[right], arr[mid]);

    // Place the pivot at the leftmost position
    Swap_With_Pool(arr[mid], arr[left]);

    // Return the pivot value
    return arr[left];
}

int Partition(vector<int> &arr, int left, int right)
{
    int pivot = MedianOfThree(arr, left, right); // Choose pivot using median of three
    int i = left - 1;                            // Index of smaller element
    int j = right + 1;                           // Index of larger element

    // Partitioning process
    while (true)
    {
        // Increment i until we find an element greater than the pivot
        do
        {
            i++;
        } while (arr[i] < pivot);

        // Decrement j until we find an element less than the pivot
        do
        {
            j--;
        } while (arr[j] > pivot);

        // If i and j cross, return j as the partition index
        if (i >= j)
            return j;

        // Swap elements to ensure left side is less than pivot and right side is greater
        Swap_With_Pool(arr[i], arr[j]);
    }
}

void QuickSort(vector<int> &arr, int left, int right, int max_depth)
{
    if (left < right)
    {
        // Partition the array and get the pivot index
        int pivotIndex = Partition(arr, left, right);
        // Recursively sort the left and right sub-arrays
        QuickSort(arr, left, pivotIndex, max_depth - 1);
        QuickSort(arr, pivotIndex + 1, right, max_depth - 1);
    }
}