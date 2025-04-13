#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <chrono>
#include <iomanip>
#include <stdio.h>
#include <random>
#include <fstream>

#include "sorting_algorithms.h"
#include "memory_pool.h"

MemoryPool memoryPool(1024);

using namespace std;

void PrintArray(vector<int> &arr, int n)
{
    int count = 0; // Counter for the number of elements printed
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
        {
            cout << ", ";
        }
        if (++count % 50 == 0) // Print a new line after every 10 elements
        {
            cout << endl;
        }
    }
    cout << "]" << endl;
}

int *RandomValuesWithDuplicates(int size, int range)
{
    int *temp = memoryPool.allocate(size);

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist(0, range); // distribution in range [0, range]

    for (int i = 0; i < size; ++i)
    {
        if (dist(rng))
            temp[i] = dist(rng);
    }

    return temp;
}

int *ShuffledValues(int size)
{
    int *temp = memoryPool.allocate(size);

    for (int i = 0; i < size; ++i)
    {
        temp[i] = i + 1; // Fill with sequential values
    }

    // Shuffle the array
    random_device rd;
    mt19937 rng(rd());
    shuffle(temp, temp + size, rng);

    return temp;
}

// Function to test the QuickSort algorithm
void QuickSort_Test(vector<int> &arr, int n)
{
    cout << "=============================================================================================" << endl;
    cout << "======================================== QuickSort.h ========================================" << endl;
    cout << "=============================================================================================" << endl;
    cout << "------> Testing QuickSort Method <-------" << endl;

    // Example usage of the Quicksort function
    vector<int> arr1 = arr;
    int n1 = arr1.size();

    cout << "Unsorted array: ";
    PrintArray(arr1, n1);

    // Get the starting time point
    auto start1 = chrono::steady_clock::now();

    // Call QuickSort
    QuickSort(arr1, 0, n1 - 1, 2 * log2(n1));

    // Get the ending time point
    auto end1 = chrono::steady_clock::now();

    // Calculate the duration in milliseconds
    chrono::duration<double, milli> duration1 = end1 - start1;

    cout << "Sorted array: ";
    PrintArray(arr1, n1);

    cout << "Time taken for QuickSort: " << fixed << setprecision(6) << duration1.count() << " ms" << endl;
}

// Function to test the HeapSort algorithm
void HeapSort_Test(vector<int> &arr, int n)
{
    cout << "=============================================================================================" << endl;
    cout << "======================================== HeapSort.h =========================================" << endl;
    cout << "=============================================================================================" << endl;
    cout << "------> Testing HeapSort Method <-------" << endl;
    // Example usage of the Heapsort function
    vector<int> arr2 = arr;
    int n2 = arr2.size();

    cout << "Unsorted array: ";
    PrintArray(arr2, n2);

    // Get the starting time point
    auto start2 = chrono::steady_clock::now();

    // Call HeapSort
    HeapSort(arr2, 0, n2 - 1);

    // Get the ending time point
    auto end2 = chrono::steady_clock::now();

    // Calculate the duration in milliseconds
    chrono::duration<double, milli> duration2 = end2 - start2;

    cout << "Sorted array: ";
    PrintArray(arr2, n2);

    cout << "Time taken for HeapSort: " << fixed << setprecision(6) << duration2.count() << " ms" << endl;
}

// Function to test the InsertionSort algorithm
void InsertionSort_Test(vector<int> &arr, int n)
{
    cout << "=============================================================================================" << endl;
    cout << "===================================== InsertionSort.h =======================================" << endl;
    cout << "=============================================================================================" << endl;
    cout << "------> Testing InsertionSort Method <-------" << endl;
    // Example usage of the InsertionSort function
    vector<int> arr3 = arr;
    int n3 = arr3.size();

    cout << "Unsorted array: ";
    PrintArray(arr3, n3);

    // Get the starting time point
    auto start3 = chrono::steady_clock::now();

    // Call InsertionSort
    InsertionSort(arr3, 0, n3 - 1); // Call InsertionSort

    // Get the ending time point
    auto end3 = chrono::steady_clock::now();

    // Calculate the duration in milliseconds
    chrono::duration<double, milli> duration3 = end3 - start3;

    cout << "Sorted array: ";
    PrintArray(arr3, n3);

    cout << "Time taken for InsertionSort: " << fixed << setprecision(6) << duration3.count() << " ms" << endl;
}

// Function to test the Introsort algorithm
void Introsort_Test(vector<int> &arr, int n)
{
    cout << "=============================================================================================" << endl;
    cout << "======================================== IntroSort.h ========================================" << endl;
    cout << "=============================================================================================" << endl;
    cout << "------> Testing IntroSort Method <-------" << endl;
    // Example usage of the Introsort function
    vector<int> arr4 = arr;
    int n4 = arr4.size();

    cout << "Unsorted array: ";
    PrintArray(arr4, n4);

    // Get the starting time point
    auto start4 = chrono::steady_clock::now();

    // Call Introsort
    IntroSort(arr4, 0, n4 - 1);

    // Get the ending time point
    auto end4 = chrono::steady_clock::now();

    // Calculate the duration in milliseconds
    chrono::duration<double, milli> duration4 = end4 - start4;

    cout << "Sorted array: ";
    PrintArray(arr4, n4);

    cout << "Time taken for IntroSort: " << fixed << setprecision(6) << duration4.count() << " ms" << endl;
}

void EdgeCasesTest()
{
    cout << "\n========================================[ TESTING EDGE CASES ]========================================" << endl;
    cout << "-------------------------------------------> Empty Array <-------------------------------------------" << endl;
    int size1 = 0;                                // Size of the empty array
    int *temp1 = memoryPool.allocate(size1);      // Allocate memory for the empty array
    vector<int> emptyArray(temp1, temp1 + size1); // Create an empty vector

    cout << "Array Size: " << size1 << endl;

    HeapSort_Test(emptyArray, size1);      // Test HeapSort
    QuickSort_Test(emptyArray, size1);     // Test QuickSort
    InsertionSort_Test(emptyArray, size1); // Test InsertionSort
    Introsort_Test(emptyArray, size1);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp1); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Single Element Array <--------------------------------------" << endl;
    int size2 = 1;                                        // Size of the single element array
    int *temp2 = memoryPool.allocate(size2);              // Allocate memory for the single element array
    temp2[0] = 42;                                        // Assign a value to the single element
    vector<int> singleElementArray(temp2, temp2 + size2); // Create a vector from the allocated memory

    cout << "Array Size: " << size2 << endl;

    HeapSort_Test(singleElementArray, size2);      // Test HeapSort
    QuickSort_Test(singleElementArray, size2);     // Test QuickSort
    InsertionSort_Test(singleElementArray, size2); // Test InsertionSort
    Introsort_Test(singleElementArray, size2);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp2); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;
}

// Function to test small arrays with various conditions
void TestSmallArrays()
{
    cout << "\n========================================[ TESTING SMALL ARRAYS ]========================================" << endl;
    cout << "-------------------------------------------> Small Array (Already Sorted) <-------------------------------------------" << endl;
    int size1 = 10;                          // Size of the already sorted array
    int *temp1 = memoryPool.allocate(size1); // Allocate memory for the already sorted array

    for (int i = 0; i < size1; ++i)
    {
        temp1[i] = i + 1; // Fill with sequential values
    }

    vector<int> sortedArray1(temp1, temp1 + size1); // Create a vector from the allocated memory

    cout << "Array Size: " << size1 << endl;

    HeapSort_Test(sortedArray1, size1);      // Test HeapSort
    QuickSort_Test(sortedArray1, size1);     // Test QuickSort
    InsertionSort_Test(sortedArray1, size1); // Test InsertionSort
    Introsort_Test(sortedArray1, size1);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp1); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Small Arrays (Reversed Sorted) <--------------------------------------" << endl;
    int size2 = 10;                          // Size of the reversed sorted array
    int *temp2 = memoryPool.allocate(size2); // Allocate memory for the reversed sorted array

    for (int i = 0; i < size2; ++i)
    {
        temp2[i] = size2 - i; // Fill with reversed sequential values
    }

    vector<int> reversedSortedArray(temp2, temp2 + size2); // Create a vector from the allocated memory

    cout << "Array Size: " << size2 << endl;

    HeapSort_Test(reversedSortedArray, size2);      // Test HeapSort
    QuickSort_Test(reversedSortedArray, size2);     // Test QuickSort
    InsertionSort_Test(reversedSortedArray, size2); // Test InsertionSort
    Introsort_Test(reversedSortedArray, size2);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp2); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Small Arrays (Duplicates) <--------------------------------------" << endl;
    int size3 = 10;                                                  // Size of the array
    int smallArrayRange = 100;                                       // Range of random values
    int *temp3 = RandomValuesWithDuplicates(size3, smallArrayRange); // Allocate memory for random values
    vector<int> arr1(temp3, temp3 + size3);                          // Create a vector from the allocated memory

    cout << "Array Size: " << size3 << endl;

    HeapSort_Test(arr1, size3);      // Test HeapSort
    QuickSort_Test(arr1, size3);     // Test QuickSort
    InsertionSort_Test(arr1, size3); // Test InsertionSort
    Introsort_Test(arr1, size3);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp3); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Small Arrays (Randomly Shuffled) <--------------------------------------" << endl;
    int size4 = 10;                         // Size of the array
    int *temp4 = ShuffledValues(size4);     // Allocate memory for shuffled values
    vector<int> arr2(temp4, temp4 + size4); // Create a vector from the allocated memory

    cout << "Array Size: " << size4 << endl;

    HeapSort_Test(arr2, size4);      // Test HeapSort
    QuickSort_Test(arr2, size4);     // Test QuickSort
    InsertionSort_Test(arr2, size4); // Test InsertionSort
    Introsort_Test(arr2, size4);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp4); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;
}

// Function to test large arrays with various conditions
void TestLargeArray()
{
    cout << "\n========================================[ TESTING LARGE ARRAYS ]========================================" << endl;
    cout << "-------------------------------------------> Large Array (Already Sorted) <-------------------------------------------" << endl;
    int size1 = 1000;                        // Size of the already sorted array
    int *temp1 = memoryPool.allocate(size1); // Allocate memory for the already sorted array

    for (int i = 0; i < size1; ++i)
    {
        temp1[i] = i + 1; // Fill with sequential values
    }

    vector<int> sortedArray(temp1, temp1 + size1); // Create a vector from the allocated memory

    cout << "Array Size: " << size1 << endl;

    HeapSort_Test(sortedArray, size1);      // Test HeapSort
    QuickSort_Test(sortedArray, size1);     // Test QuickSort
    InsertionSort_Test(sortedArray, size1); // Test InsertionSort
    Introsort_Test(sortedArray, size1);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp1); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Large Arrays (Reversed Sorted) <--------------------------------------" << endl;
    int size2 = 1000;                        // Size of the reversed sorted array
    int *temp2 = memoryPool.allocate(size2); // Allocate memory for the reversed sorted array

    for (int i = 0; i < size2; ++i)
    {
        temp2[i] = size2 - i; // Fill with reversed sequential values
    }

    vector<int> reversedSortedArray(temp2, temp2 + size2); // Create a vector from the allocated memory

    cout << "Array Size: " << size2 << endl;

    HeapSort_Test(reversedSortedArray, size2);      // Test HeapSort
    QuickSort_Test(reversedSortedArray, size2);     // Test QuickSort
    InsertionSort_Test(reversedSortedArray, size2); // Test InsertionSort
    Introsort_Test(reversedSortedArray, size2);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp2); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Large Arrays (Duplicates) <--------------------------------------" << endl;
    int size3 = 1000;                                                // Size of the array
    int largeArrayRange = 1000;                                      // Range of random values
    int *temp3 = RandomValuesWithDuplicates(size3, largeArrayRange); // Allocate memory for random values
    vector<int> arr1(temp3, temp3 + size3);                          // Create a vector from the allocated memory

    cout << "Array Size: " << size3 << endl;

    HeapSort_Test(arr1, size3);      // Test HeapSort
    QuickSort_Test(arr1, size3);     // Test QuickSort
    InsertionSort_Test(arr1, size3); // Test InsertionSort
    Introsort_Test(arr1, size3);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp3); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;

    cout << "--------------------------------------> Large Arrays (Randomly Shuffled) <--------------------------------------" << endl;
    int size4 = 1000;                       // Size of the array
    int *temp4 = ShuffledValues(size4);     // Allocate memory for shuffled values
    vector<int> arr2(temp4, temp4 + size4); // Create a vector from the allocated memory

    cout << "Array Size: " << size4 << endl;

    HeapSort_Test(arr2, size4);      // Test HeapSort
    QuickSort_Test(arr2, size4);     // Test QuickSort
    InsertionSort_Test(arr2, size4); // Test InsertionSort
    Introsort_Test(arr2, size4);     // Test Introsort

    cout << endl;

    memoryPool.deallocate(temp4); // Deallocate the memory after use
    memoryPool.printStats();      // Print memory pool statistics

    cout << endl;
}

int main()
{
    ofstream output("test_results.txt");
    if (!output.is_open())
    {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    streambuf *coutBuf = cout.rdbuf(); // Save original buffer
    cout.rdbuf(output.rdbuf());        // Redirect cout to file

    EdgeCasesTest();   // Test edge cases
    TestSmallArrays(); // Test small arrays
    TestLargeArray();  // Test large arrays

    cout.rdbuf(coutBuf); // Restore cout
    output.close();

    cout << "Test Results Written to test_results.txt" << endl;

    return 0;
}