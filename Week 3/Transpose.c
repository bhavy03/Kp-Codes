#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // Transpose the matrix in-place
    // for (int i = 0; i < n; i++) {
    // for (int j = i + 1; j < n; j++) {
    // int temp = arr[i][j];
    // arr[i][j] = arr[j][i];
    // arr[j][i] = temp;
    // }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}
