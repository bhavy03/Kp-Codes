#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char sen[200];
    scanf("%[^\n]%*c", sen);
    char temp[20];
    char *stack[100];
    int top = -1;
    for (int i = 0; sen[i] != '\0'; i++)
    {
        int j = 0;
        while (sen[i] != ' ' && sen[i] != '\0')
        {
            temp[j++] = sen[i++];
        }
        temp[j] = '\0';
        if (j > 0) // Only push non-empty words and necessary condition as there may be multiple
        {
            stack[++top] = strdup(temp); // Store the copy of temp in stack
        }
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%s ", stack[i]);
        free(stack[i]);
    }
    return 0;
}
