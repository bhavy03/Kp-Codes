#include <stdio.h>
#include <stdlib.h>
int strLen(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}
char *findSubstring(char *str, int start, int end)
{
    char *subString = (char *)malloc(sizeof(char) * (end - start + 2));
    // char subString[end - start + 1]; this thing can only be used within the function
    int index = 0;
    for (int i = start; i <= end; i++)
    {
        subString[index++] = str[i];
    }
    subString[index] = '\0';
    return subString;
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
    // char *subString = findSubstring(input, 2, 6);
    // printf("%s", subString);

    int maxLength = 0;
    int startIdx = 0;
    if (len == 1)
    {
        printf("%s", input);
        return 0;
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            char *temp = findSubstring(input, i, j);
            if (isPalindrome(temp))
            {
                int currentLen = j - i + 1;
                if (currentLen > maxLength)
                {
                    maxLength = currentLen;
                    startIdx = i;
                }
            }
            free(temp);
        }
    }
    char *longestPalindrome = findSubstring(input, startIdx, startIdx + maxLength - 1);
    printf("%s\n", longestPalindrome);
    free(longestPalindrome);

    return 0;
}
// #include <stdio.h>
// #include <string.h>
//
// char* longestPalindrome(char* s);
// char* expandFromCenter(char* s, int left, int right, char* result);
//
// int main() {
// char input[200];
// printf("Enter the string: ");
// scanf("%s", input);
//
// char* longest = longestPalindrome(input);
// printf("Longest Palindromic Substring: %s\n", longest);
//
// return 0;
// }
//
// char* longestPalindrome(char* s) {
// static char longest[200] = ""; // Static to persist data outside the function
// longest[0] = '\0'; // Reset the string
//
// int n = strlen(s);
//
// for (int i = 0; i < n; i++) {
// char temp[200];
//
// Odd - length palindromes
// expandFromCenter(s, i, i, temp);
// if (strlen(temp) > strlen(longest)) {
// strcpy(longest, temp);
// }
//
//   Even -
// length palindromes
// expandFromCenter(s, i, i + 1, temp);
// if (strlen(temp) > strlen(longest)) {
// strcpy(longest, temp);
// }
// }
//
// return longest;
// }
//
// char* expandFromCenter(char* s, int left, int right, char* result) {
// int n = strlen(s);
//
// while (left >= 0 && right < n && s[left] == s[right]) {
// left--;
// right++;
// }
//
// Extract the substring from left +
// 1 to right - 1
// int start = left + 1;
// int length = right - left - 1;
//
// strncpy(result, &s[start], length);
// result[length] = '\0'; // Null-terminate the string
//
// return result;
// }
//