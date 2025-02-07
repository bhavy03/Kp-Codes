#include <stdio.h>
void subsets(int *arr, int *ans, int index, int idx, int n, int k)
{

    // printf("%d %d\n", index, idx);
    if (index == n)
    {
        if (k == 0)
        {
            for (int i = 0; i < idx; i++)
            {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
        return;
    }

    // include
    ans[idx] = arr[index];
    if (ans[idx] <= k)
    {
        subsets(arr, ans, index, idx + 1, n, k - ans[idx]);
    }

    // exclude
    subsets(arr, ans, index + 1, idx, n, k);
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
    subsets(arr, ans, index, idx, n, k);
    // for (int i = 0; i < n; i++) {
    //   printf("%d", arr[i]);
    // }
    return 0;
}
