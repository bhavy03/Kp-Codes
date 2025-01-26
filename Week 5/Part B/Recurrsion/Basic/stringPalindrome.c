#include <stdio.h>
#include <string.h>
int isPalindrom(char *s, int i, int n)
{

    if (i >= n / 2)
    {
        return 1;
    }
    if (s[i] != s[n - i - 1])
    {
        return 0;
    }
    return isPalindrom(s, i + 1, n);
}

int main()
{
    char exp[] = "madam";
    int n = strlen(exp);
    int result = isPalindrom(exp, 0, n);
    if (result)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}