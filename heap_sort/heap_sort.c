#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "max_heap.h"

int main()
{
    int arr[10] = {14, 10, 16, 8, 7, 9, 3, 4, 1, 2};
    heap *hp = buildMaxHeap(arr, 10);

    printf("<Build Max Heap> \n");
    printHeap(hp);

    printf("\n");

    printf("<Heap Sort> \n");
    printf("Before Sort: \n");
    printHeap(hp);
    heapSort(hp);
    printf("After Sort: \n");
    printHeap(hp);

    // printf("\n");

    // printf("<Find Max> \n");
    // findMax(hp);

    // printf("<Extract Max> \n");
    // int max = extractMax(hp);
    // printf("Max element : %d \n", max);
    // printHeap(hp);
    // printf("Size : %d \n", hp->size);

    // printf("<Increase Key> \n");
    // increaseKey(hp, 3, 11);
    // printHeap(hp);

    // printf("<Inserting Key> \n");
    // insertHeap(hp, 11);
    // printHeap(hp);

    free(hp);
}