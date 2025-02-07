#include <stdio.h>

int findLength(char *exp, int i)
{
    if (exp[i] == '\0')
    {
        return i;
    }
    return findLength(exp, i + 1);
}
int main()
{
    char string[] = "abcd";
    int length = findLength(string, 0);
    printf("Length of string is: %d", length);
}