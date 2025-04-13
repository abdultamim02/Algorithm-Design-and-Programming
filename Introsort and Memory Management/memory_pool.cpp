#include <cstddef>
#include <vector>
#include <iostream>

#include "memory_pool.h"

using namespace std;

// MemoryPool class constructor
MemoryPool::MemoryPool(size_t chunk_size)
{
    // Initialize the memory pool with a default chunk size
    this->chunk_size = chunk_size;
}

void MemoryPool::Initialize(size_t size)
{
    // Free all previously allocated memory blocks
    chunk_size = size; // Set the new chunk size
    for (auto block : pool)
        delete[] block;
    pool.clear();
    free_list.clear();
}

int *MemoryPool::allocate(size_t size)
{
    allocations++; // increment allocation count

    // check if there is a free block available
    if (!free_list.empty())
    {
        reused_blocks++;               // increment reused block count
        int *block = free_list.back(); // get the last block from the free list
        free_list.pop_back();          // remove it from the free list
        return block;                  // return the block
    }

    // error if requested size too large
    if (size > chunk_size)
    {
        cerr << "Error: Requested size exceeds chunk size!" << endl;
        return nullptr;
    }

    blocks++;                             // increment block count
    int *new_block = new int[chunk_size]; // allocate a new block of memory
    pool.push_back(new_block);            // add it to the pool
    return new_block;                     // return the new block
}

void MemoryPool::deallocate(int *ptr)
{
    if (ptr)
    {
        deallocations++;          // increment deallocation count
        free_blocks++;            // increment free block count
        free_list.push_back(ptr); // add the block to the free list
    }
}

void MemoryPool::printStats()
{
    cout << "Total Allocations: " << allocations << "\n";
    cout << "Total Deallocations: " << deallocations << "\n";
    cout << "Total Blocks: " << blocks << "\n";
    cout << "Total Free Blocks: " << free_blocks << "\n";
    cout << "Total Reused Blocks: " << reused_blocks << "\n";
}

// Destructor to free all allocated memory blocks
MemoryPool::~MemoryPool()
{
    // Free all allocated memory blocks
    for (auto block : pool)
        delete[] block;

    // Clear the pool and free list
    pool.clear();
    free_list.clear();
}