#include <stdio.h>
int strLen(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
int stringCompare(char *input1, char *input2)
{
    for (int i = 0; input1[i] != '\0'; i++)
    {
        if (input1[i] == input2[i])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    char input1[200];
    printf("Enter the String 1\n");
    scanf("%[^\n]%*c", input1);

    char input2[200];
    printf("Enter the String 2\n");
    scanf("%[^\n]%*c", input2);

    int start = 0;
    int end = strLen(input1) - 1;

    while (start < end)
    {
        swap(&input1[start], &input1[end]);
        start++;
        end--;
    }
    if (stringCompare(input1, input2) == 1)
    {
        printf("true");
    }
    else
    {

        printf("false");
    }
}