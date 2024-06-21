#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "max_heap.h"

int main()
{
    int arr[10] = {14, 16, 8, 10, 7, 9, 2, 3, 1, 4};
    heap *hp = buildMaxHeap(arr, 10);

    printHeap(hp);

    free(hp);
}