#include <stdio.h>
// int flag = 0;
void printSum(int *arr, int *ans, int index, int idx, int n, int rsum)
{
    int sum = 0;
    // we are putting these in if as the subsets are formed at the very last index
    if (index == n)
    {
        for (int i = 0; i < idx; i++)
        {
            sum += ans[i];
        }
        // if (sum == rsum && flag == 0)
        // this is to print only one
        if (sum == rsum)
        {
            // flag = 1;
            for (int i = 0; i < idx; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }

        // this is to print all subsets sums
        // printf("%d\n", sum);
        return;
    }

    // include
    ans[idx] = arr[index];
    printSum(arr, ans, index + 1, idx + 1, n, rsum);

    // exclude
    printSum(arr, ans, index + 1, idx, n, rsum);
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
    printSum(arr, ans, index, idx, n, k);
    // for (int i = 0; i < n; i++) {
    //   printf("%d", arr[i]);
    // }
    return 0;
}