
#ifndef SORTING_ALGORITHMS_H

#define SORTING_ALGORITHMS_H

#include <vector>

#include "IntroSort.h"

// Function prototypes for sorting algorithms

// Insertion Sort for small arrays
void InsertionSort(std::vector<int> &arr, int low, int high);

// Median of Three function for QuickSort
int MedianOfThree(std::vector<int> &arr, int low, int high);

// Partition function for QuickSort
int Partition(std::vector<int> &arr, int low, int high);

// QuickSort function
void QuickSort(std::vector<int> &arr, int low, int high, int max_depth);

// Heapify function for HeapSort
void Heapify(std::vector<int> &arr, int n, int i);

// HeapSort function
void HeapSort(std::vector<int> &arr, int low, int high);

// Introsort function
void IntroSort(std::vector<int> &arr, int low, int high);

// Introsort utility to handle depth switching
void IntoSortUtil(std::vector<int> &arr, int low, int high, int max_depth);

#endif // SORTING_ALGORITHMS_H