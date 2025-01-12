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
int isPalindrome(char str[])
{
    int start = 0;
    int end = strLen(str) - 1;
    // printf("%d %d", start, end);
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int main()
{
    char input[200];
    printf("Enter the String\n");
    scanf("%[^\n]%*c", input);
    // if (isPalindrome(input))
    // {
    // printf("Palindrome\n");
    // }
    // else
    // {
    // printf("Not Palindrome\n");
    // }
    int len = strLen(input);
    for(int i =0;input[i]!='\0';i++)
    {
        char *str = input[i];
        for(int j = i+1;j<len;j++){}
    }
    return 0;
}