#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringLength(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    char sentence[101];
    // scanf("%[^\n]%*c", sentence);
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
        return 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == '\n')
        {
            sentence[i] = '\0';
            break;
        }
    }
    char *start = sentence;
    char *end = sentence + stringLength(sentence) - 1;
    while (*start == ' ')
        start++;
    while (end >= start && *end == ' ')
        end--;
    char temp[101];
    char *tempPtr = temp;
    while (end >= start)
    {
        while (end >= start && *end == ' ')
            end--;
        char *wordEnd = end;
        while (end >= start && *end != ' ')
            end--;
        char *wordStart = end + 1;
        while (wordStart <= wordEnd)
        {
            *tempPtr++ = *wordStart++;
        }
        if (end >= start)
        {
            *tempPtr++ = ' ';
        }
    }
    *tempPtr = '\0';

    printf("%s\n", temp);
    return 0;
}
