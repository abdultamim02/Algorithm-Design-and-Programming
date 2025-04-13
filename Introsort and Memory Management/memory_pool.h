#ifndef MEMORY_POOL_H

#define MEMORY_POOL_H

#include <cstddef> // for size_t

#include <vector>

// Memory Pool Class
class MemoryPool
{

public:
    // Constructor to initialize the memory pool with a default chunk size
    MemoryPool(size_t chunk_size = 1024);

    // Destructor to free all allocated memory chunks
    ~MemoryPool();

    // Initialize the memory pool with a specific chunk size
    void Initialize(size_t size);

    // Allocate memory block of requested size
    int *allocate(size_t size);

    // Deallocate previously allocated memory
    void deallocate(int *ptr);

    // Print statistics about memory allocations and deallocations
    void printStats();

private:
    size_t chunk_size;            // The chunk size for allocation
    std::vector<int *> pool;      // Vector to keep track of allocated chunks
    std::vector<int *> free_list; // Stack to store free memory blocks
    int allocations = 0;          // Number of allocations
    int deallocations = 0;        // Number of deallocations
    int blocks = 0;               // Number of blocks allocated
    int free_blocks = 0;          // Number of free blocks in the pool
    int reused_blocks = 0;        // Number of reused blocks
};

#endif // MEMORY_POOL_H