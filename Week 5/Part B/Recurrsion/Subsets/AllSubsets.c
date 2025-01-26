#include <stdio.h>
void subsets(int *arr, int *ans, int index, int idx, int n)
{

    // printf("%d %d\n", index, idx);
    if (index == n)
    {
        for (int i = 0; i < idx; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }

    // include
    ans[idx] = arr[index];

    subsets(arr, ans, index + 1, idx + 1, n);

    // exclude
    subsets(arr, ans, index + 1, idx, n);
}
int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int ans[n];
    int index = 0;
    int idx = 0;
    subsets(arr, ans, index, idx, n);
    // for (int i = 0; i < n; i++) {
    //   printf("%d", arr[i]);
    // }
    return 0;
}
