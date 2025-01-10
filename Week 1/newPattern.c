#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        for (int a = 0; a < n - i; a++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        for (int k = i - 1; k > 0; k--)
        {
            printf("%d", k);
        }
        printf("\n");
    }
}