#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min = INT_MAX;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void findDifference(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] < min)
            {
                min = arr[j] - arr[i];
            }
        }
    }
}

void findPairs(int *arr, int n, int min)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] - arr[i] == min)
            {
                if (flag == 0)
                {
                    printf("[%d,%d]", arr[i], arr[j]);
                    flag = 1;
                }
                else
                {
                    printf(",[%d,%d]", arr[i], arr[j]);
                }
            }
        }
    }
}
int main()
{
    int arr[20];

    int i = 0;
    int num = 0;
    while ((scanf("%d", &num)) == 1)
    {
        arr[i++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    int n = i;
    sortArray(arr, n);
    findDifference(arr, n);
    printf("%d\n", min);
    findPairs(arr, n, min);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    return 0;
}
