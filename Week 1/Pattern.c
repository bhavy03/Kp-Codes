#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double minimum (double x, double y)
{
    return (x < y) ? x : y;
}

int main()
{
    int n;
    scanf("%d", &n);
    int originalN = n + 1;
    n = 2 * n;
    for (int row = 1; row < n; row++)
    {
        // for every row run the column
        for (int col = 1; col < n; col++)
        {
            int atEveryIndex = originalN - minimum(minimum(row, col), minimum(n - row, n - col));
            printf("%d ", atEveryIndex);
        }
        printf("\n");
    }
    // Complete the code to print the pattern.
    return 0;
}
