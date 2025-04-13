#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "HeapSort.h"
#include "swap_utils.h"

using namespace std;

void Heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {

        Swap_With_Pool(arr[i], arr[largest]); // Swap root with largest

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest);
    }
}

void HeapSort(vector<int> &arr, int low, int high)
{
    int n = high - low + 1; // Calculate the size of the heap

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i >= 0; i--)
    {
        Swap_With_Pool(arr[0], arr[i]); // Move current root to end

        // Call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}