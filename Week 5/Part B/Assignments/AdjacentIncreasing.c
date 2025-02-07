#include <stdio.h>

int checkOrder(int *arr, int start, int k)
{
    for (int i = start; i < start + k - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int arr[200000];
    int size = 0;
    int num = 0;

    while ((scanf("%d", &num)) == 1)
    {
        arr[size++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }

    int n = size;
    int max_k = 0;

    for (int k = n / 2; k > 0; k--)
    {
        for (int i = 0; i <= n - 2 * k; i++)
        {
            if (checkOrder(arr, i, k) && checkOrder(arr, i + k, k))
            {
                max_k = k;
            }
        }
    }
    printf("%d\n", max_k);
    return 0;
}
