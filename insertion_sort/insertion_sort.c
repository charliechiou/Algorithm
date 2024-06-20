#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (j = 1; j < n; j++)
    {
        key = arr[j];
        i = j - 1;

        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }

        arr[i + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 0;
    int i;

    printf("Input array length: \n");
    scanf("%d", &n);

    int *arr;
    arr = (int *)malloc(sizeof(int) * n);

    printf("Input elements in the array : \n");
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("Input array: \n");
    printArray(arr, n);

    printf("Sorted: \n");
    insertionSort(arr, n);
    printArray(arr, n);
}