#include <stdio.h>

// it is by parametrized recursion
void print(int i, int sum)
{
    if (i < 1)
    {
        printf("%d\n", sum);
        return;
    }
    print(i - 1, sum + i);
}

// this is by functional recurrsion
int functional(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + functional(n - 1);
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int main()
{
    int n = 5;
    int sum = 0;
    print(n, sum);
    int newSum = functional(n);
    printf("%d\n", newSum);
    int fact = factorial(n);
    printf("%d\n",fact);
}