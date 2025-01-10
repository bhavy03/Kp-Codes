#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int are_strings_equal(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}
void nonRepeatingWord(char sentence[])
{
    char *ptr = sentence;
    char *array[100];
    int wordIndex = 0;
    int newArr[100];
    while (*ptr != '\0')
    {
        while (*ptr == ' ')
            ptr++;

        array[wordIndex++] = ptr;

        while (*ptr != ' ' && *ptr != '\0')
            ptr++;

        if (*ptr != '\0')
        {
            *ptr = '\0';
            ptr++;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        newArr[i] = 1;
    }
    for (int i = 0; i < wordIndex; i++)
    {
        for (int j = i + 1; j < wordIndex; j++)
        {
            if (newArr[i] == -1)
            {
                continue;
            }
            if (are_strings_equal(array[i], array[j]))
            {
                if (newArr[j] == -1)
                    continue;
                newArr[i] = -1;
                newArr[j] = -1;
            }
        }
    }
    int found = 0;
    for (int i = 0; i < wordIndex; i++)
    {
        if (newArr[i] != -1)
        {
            printf("%s", array[i]);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf(""); 
    }
    printf("\n");
}
int main()
{
    char sentence[100];
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
    {
        return 0;
    }
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == '\n')
        {
            sentence[i] = '\0';
            break;
        }
    }
    nonRepeatingWord(sentence);
    return 0;
}