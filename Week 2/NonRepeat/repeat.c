#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// int compareString(char str1[], char str2[])
// {

// while (*str1 != '\0' && *str2 != '\0')
// {

// if (*str1 != *str2)
// {
// return 1; // the strings are different
// }

// str1++;
// str2++;
// }

// if (*str1 == '\0' && *str2 == '\0')
// {
// return 0; // the strings are same
// }
// else
// {
// return 1;
// }
// }
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
    // for (int j = 0; j < i; j++)
    // {
    // printf("Word %d: %s\n", i + 1, array[j]);
    // }
    for (int i = 0; i < wordIndex; i++)
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
        printf(""); // No non-repeating word found
    }
    printf("\n");
    // for (int j = 0; j < i; j++)
    // {
    // int repeating = 0;
    // for (int k = 0; k < i; k++)
    // {
    // if (j != k && (compareString(array[j], array[k])) == 0)
    // {
    // repeating = 1;
    // }
    // }

    // if (!repeating)
    // {
    // printf("%s", array[j]);
    // }
    // }
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
// Since ptr is pointing to specific positions within the sentence and not to a shared temporary buffer,
// each pointer stored in array points to a valid part of the original sentence, and no overwriting occurs.
// The words are still part of the same memory (the original sentence),
// but you are just marking their boundaries (by null-terminating them).

// in previous(NonRepeat) what happens is arr-->ptr-->temp and we are changing value of temp everytime so it points to same temp
// but in this we do is arr-->ptr-->H we change ptr so that value changes.
// arr-->ptr-->H
//        |
//       ptr-->W