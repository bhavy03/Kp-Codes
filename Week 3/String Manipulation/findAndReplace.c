#include <stdio.h>
int main()
{
    printf("Hello World\n");
    char exp[100];
    int arr[26] = {0};
    printf("Enter the expression:\n");
    scanf("%[^\n]%*c", exp);

    char ch;
    printf("Enter the char\n");
    scanf("%c", &ch);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        int index = (exp[i] - 'a');
        arr[index]++;
    }
    // for (int i = 0; i < 26; i++)
    // {
    // if (arr[i] != 0)
    // {
    // printf("%d %d %c\n", i, arr[i], i + 'a');
    // }
    // }
    for (int i = 0; exp[i] != '\0'; i++)
    {
        int index = exp[i] - 'a';
        if (arr[index] == 1)
        {
            exp[i] = ch;
            break;
        }
    }
    printf("%s", exp);
    return 0;
}