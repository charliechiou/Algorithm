#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i = 0, j = 0, k = 0;

    int *l_arr;
    int *r_arr;
    l_arr = (int *)malloc(sizeof(int) * (n1 + 1));
    r_arr = (int *)malloc(sizeof(int) * (n2 + 1));

    for (i = 0; i < n1; i++)
    {
        l_arr[i] = arr[p + i];
    }

    for (j = 0; j < n2; j++)
    {
        r_arr[j] = arr[q + 1 + j];
    }

    i = 0;
    j = 0;
    l_arr[n1] = 10 ^ 7;
    r_arr[n2] = 10 ^ 7;

    for (k = p; k <= r; k++)
    {
        if (l_arr[i] <= r_arr[j])
        {
            arr[k] = l_arr[i];
            i = i + 1;
        }
        else
        {
            arr[k] = r_arr[j];
            j = j + 1;
        }
    }

    free(l_arr);
    free(r_arr);
}

void merge_sort(int arr[], int p, int r)
{
    int q = floor((p + r + 2) / 2) - 1;
    if (p < r)
    {
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
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
    merge_sort(arr, 0, n - 1);
    printArray(arr, n);

    free(arr);
}