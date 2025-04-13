#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>

int MedianOfThree(std::vector<int> &arr, int left, int right);
int Partition(std::vector<int> &arr, int left, int right);
void QuickSort(std::vector<int> &arr, int left, int right, int max_depth);

#endif // QUICK_SORT_H
