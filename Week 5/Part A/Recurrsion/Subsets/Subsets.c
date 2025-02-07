#include <stdio.h>
void subsets(int *arr, int *ans, int index, int idx, int n)
{
    if (index == n)
    {
        return;
    }

    ans[idx] = arr[index];
    printf(", [");
    int flag = 0;
    for (int i = 0; i <= idx; i++)
    {
        if (flag == 0)
        {
            printf("%d", ans[i]);
        }
        else
        {
            printf(" ,%d", ans[i]);
        }
    }
    printf("]");

    subsets(arr, ans, index + 1, idx + 1, n);
    subsets(arr, ans, index + 1, idx, n);
}
int main()
{
    char exp[100];
    scanf("%[^\n]%*c", exp);
    int arr[16];
    int arrIndex = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] != ',') // Only store characters that are not commas
        {
            arr[arrIndex++] = exp[i] - '0'; // Convert the character to its integer value
        }
    }
    int ans[16];
    int index = 0;
    int idx = 0;
    // for (int i = 0; i < arrIndex; i++)
    // {
    //     printf("%d", arr[i]);
    // }
    printf("[[] ");
    subsets(arr, ans, index, idx, arrIndex);
    printf("]");
    return 0;
}
