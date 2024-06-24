#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    int temp;

    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;

    return i + 1;
}

void quick_sort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 6;
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
    quick_sort(arr, 0, n - 1);
    printArray(arr, n);

    free(arr);
}