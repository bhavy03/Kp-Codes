#include <stdio.h>
#include <stdbool.h>
// int flag = 0;
int printSum(int *arr, int *ans, int index, int idx, int n, int rsum)
{
    int sum = 0;
    if (index == n)
    {
        for (int i = 0; i < idx; i++)
        {
            sum += ans[i];
        }
        // condition satisfied
        if (sum == rsum)
        {
            // flag = 1;
            for (int i = 0; i < idx; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("\n");
            return 1;
        }
        // condition not satisfied
        else
        {
            return 0;
        }
    }

    // include
    ans[idx] = arr[index];
    int l = printSum(arr, ans, index + 1, idx + 1, n, rsum);

    // exclude
    int r = printSum(arr, ans, index + 1, idx, n, rsum);

    return l + r;
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int ans[n];
    int index = 0;
    int idx = 0;
    int sum = 0;
    int count = printSum(arr, ans, index, idx, n, k);
    printf("Count is : %d", count);
    // for (int i = 0; i < n; i++) {
    //   printf("%d", arr[i]);
    // }
    return 0;
}