#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        a[i] = rand();

    clock_t start = clock();

    mergeSort(a, 0, n - 1);

    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken = %lf seconds\n", timeTaken);

    return 0;
}