// we print spiral pattern from right then bottom then left then top
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    // int *ptr = result;  // can also do this and then *ptr++ = matrix[top][i];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int arr[m * n], id = 0;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            arr[id++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            arr[id++] = matrix[i][right];
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                arr[id++] = matrix[bottom][i];
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                arr[id++] = matrix[i][left];
            }
            left++;
        }
    }

    printf("[");
    for (int i = 0; i < id; i++)
    {
        printf("%d", arr[i]);
        if (i != id - 1)
            printf(" ");
    }
    printf("]\n");
    return 0;
}
