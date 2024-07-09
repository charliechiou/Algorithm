#include <stdio.h>
#include <stdlib.h>

int find_max(int arr[], int n)
{
    int max_element = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_element)
        {
            max_element = arr[i];
        }
    }
    return max_element;
}

void counting_sort(int arr[], int n, int d)
{
    int *b = (int *)malloc(sizeof(int) * (n + 1));
    int c[10] = {0};

    for (int i = 0; i < n; i++)
    {
        c[(arr[i] / d % 10)]++;
    }

    for (int i = 1; i < 10; i++)
    {
        c[i] += c[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        b[c[(arr[i] / d) % 10] - 1] = arr[i];
        c[(arr[i] / d) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}

void radix_sort(int arr[], int n)
{
    int max_element = find_max(arr, n);

    for (int d = 1; max_element / d > 0; d *= 10)
    {
        counting_sort(arr, n, d);
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
    radix_sort(arr, n);
    printArray(arr, n);

    free(arr);
}