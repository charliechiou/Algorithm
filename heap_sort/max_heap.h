#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int *arr;
    int size;
    int capacity;
};

typedef struct Heap heap;

heap *buildMaxHeap(int *nums, int capacity);
void maxHeapify(heap *h, int i);
void printHeap(heap *h);
void heapSort(heap *h);

int findMax(heap *h);
int extractMax(heap *h);
void increaseKey(heap *h, int i, int key);
void insertHeap(heap *h, int key, int capacity);

heap *buildMaxHeap(int *nums, int capacity)
{
    heap *h = (heap *)malloc(sizeof(heap));

    if (h == NULL)
    {
        printf("Memory error!");
        return NULL;
    }

    h->size = 0;
    h->capacity = capacity;
    h->arr = (int *)malloc(capacity * sizeof(int));

    if (h->arr == NULL)
    {
        printf("Memory error!");
        return NULL;
    }

    int i;

    for (i = 0; i < capacity; i++)
    {
        h->arr[i] = nums[i];
    }

    h->size = i;

    for (i = (h->size - 2) / 2; i >= 0; i--)
    {
        maxHeapify(h, i);
    }

    return h;
}

void maxHeapify(heap *h, int i)
{
    int l = i * 2 + 1;
    int r = i * 2 + 1 + 1;
    int largest;

    if (l < h->size && h->arr[l] > h->arr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r < h->size && h->arr[r] > h->arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = h->arr[largest];
        h->arr[largest] = h->arr[i];
        h->arr[i] = temp;
        maxHeapify(h, largest);
    }
}

void printHeap(heap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

void heapSort(heap *h)
{
    int i;
    int temp;
    int h_size_temp = h->size;
    for (i = h->size - 1; i >= 0; i--)
    {
        temp = h->arr[0];
        h->arr[0] = h->arr[i];
        h->arr[i] = temp;
        h->size--;
        maxHeapify(h, 0);
    }
    h->size = h_size_temp;
}

int findMax(heap *h)
{
    maxHeapify(h, 0);
    printf("max element : %d \n", h->arr[0]);
    return h->arr[0];
}

int extractMax(heap *h)
{
    int max;

    if (h->size < 1)
    {
        printf("heap overflow!");
    }

    max = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    maxHeapify(h, 0);

    return max;
}