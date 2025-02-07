#include <stdio.h>
int count = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void arrSort(int *arr, int n)
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
void maxMatching(int *arr1, int n, int start1, int *arr2, int m, int start2)
{
    int left = start1;
    int right = start2;
    int end1 = n - 1;
    int end2 = m - 1;
    while (left <= end1 && right <= end2)
    {
        if (arr1[left] <= arr2[right])
        {
            count++;
            left++;
            right++;
        }
        else
        {
            right++;
        }
    }
}
int main()
{
    int arr1[100];
    int arr2[100];
    int i = 0;
    int j = 0;
    int num = 0;

    while ((scanf("%d", &num)) == 1)
    {
        arr1[i++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    while ((scanf("%d", &num)) == 1)
    {
        arr2[j++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    int n = i;
    int m = j;
    arrSort(arr1, n);
    arrSort(arr2, m);
    int left1 = 0;
    int left2 = 0;
    maxMatching(arr1, n, left1, arr2, m, left2);
    printf("%d", count);
    return 0;
}