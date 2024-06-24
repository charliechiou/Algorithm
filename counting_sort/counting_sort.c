#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n, int k)
{
    printf("start\n");
    int *c;
    c = (int *)malloc(sizeof(int) * (k + 1));

    int *b;
    b = (int *)malloc(sizeof(int) * (n));

    for (int i = 0; i <= k; i++)
    {
        c[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        c[arr[j]] = c[arr[j]] + 1;
    }

    for (int i = 1; i <= k; i++)
    {
        c[i] = c[i] + c[i - 1];
    }

    for (int j = n - 1; j >= 0; j--)
    {
        b[c[arr[j]] - 1] = arr[j];
        c[arr[j]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
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
    int n = 0;
    int k = 0;
    int i;

    printf("Input array length: \n");
    scanf("%d", &n);

    printf("Input max int: \n");
    scanf("%d", &k);

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
    counting_sort(arr, n, k);
    printArray(arr, n);

    free(arr);
}