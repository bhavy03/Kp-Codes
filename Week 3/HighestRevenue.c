#include <stdio.h>
int main()
{
    int M;
    int N;
    scanf("%d", &M);
    scanf("%d", &N);
    char companyNames[M][100];
    int annualRev[M][N];
    int max_sum = 0;
    for (int i = 0; i < M; i++)
    {
        scanf("%s", companyNames[i]);
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &annualRev[i][j]);
        }
    }
    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += annualRev[i][j];
        }
        if (sum > max_sum)
        {
            max_sum = sum;
        }
    }
    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += annualRev[i][j];
        }
        if (sum == max_sum)
        {
            printf("%s\n", companyNames[i]);
        }
    }
    return 0;
}

// here is the optimized version
// for (int i = 0; i < M; i++) {
// scanf("%s", companyNames[i]);
// sum[i] = 0; // Initialize sum for each company
// for (int j = 0; j < N; j++) {
// scanf("%d", &annualRev[i][j]);
// sum[i] += annualRev[i][j]; // Calculate total revenue for the company
// }
// if (sum[i] > max_sum) {
// max_sum = sum[i]; // Update max revenue
// }
// }

// Output : Companies with the maximum revenue
// for (int i = 0; i < M; i++) {
// if (sum[i] == max_sum) {
// printf("%s\n", companyNames[i]); // Print each company on a new line
// }
// }