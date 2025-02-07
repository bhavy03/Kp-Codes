#include <stdio.h>

void print(int n)
{
    if (n == 0)
    {
        return;
    }
    printf("hello\n");
    n--;
    // printf("%d", n);
    print(n);
}
int main()
{
    print(5);
    return 0;
}