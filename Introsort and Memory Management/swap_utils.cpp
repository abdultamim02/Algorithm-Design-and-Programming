#include "swap_utils.h"
#include "memory_pool.h"

extern MemoryPool memoryPool;

void Swap_With_Pool(int &a, int &b)
{
    int *temp = memoryPool.allocate(1);
    *temp = a;
    a = b;
    b = *temp;
    memoryPool.deallocate(temp);
}
