#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    swap(&arr[first], &arr[last]);
    reverse(arr, first + 1, last - 1);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    reverse(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}