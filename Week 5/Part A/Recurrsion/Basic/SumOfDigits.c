#include <stdio.h>

int digitSum(int n, int sum)
{
    if (n == 0)
    {
        return sum;
    }
    int mod = n % 10;
    sum = sum + mod;
    return digitSum(n / 10, sum);
}
int main()
{
    int n;
    scanf("%d", &n);
    int result = digitSum(n, 0);
    printf("%d", result);
}