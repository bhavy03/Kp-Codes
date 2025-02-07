#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Freq
{
    int freq;
    char *string;
} Freq;

int strCmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

int findIndex(Freq *allFreq, char *str, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        if (strCmp(str, allFreq[i].string))
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char exp[1001];
    scanf("%[^\n]%*c", exp);
    int k;
    scanf("%d", &k);
    char *wordArr[100];
    int wordCount = 0;
    char *str = exp;
    while (*str != '\0')
    {
        while (*str == ' ')
        {
            str++;
        }
        if (*str != '\0')
        {
            wordArr[wordCount++] = str;
        }
        while (*str != ' ' && *str != '\0')
        {
            str++;
        }
        if (*str != '\0')
        {
            *str = '\0';
            str++;
        }
    }

    // for(int i=0;i<wordCount;i++)printf("%s ,", wordArr[i]);
    // printf("\n");

    Freq allFreq[100];
    int counter = 0;
    for (int i = 0; i < wordCount; i++)
    {
        int index = findIndex(allFreq, wordArr[i], counter);
        if (index == -1)
        {
            allFreq[counter].string = wordArr[i];
            allFreq[counter++].freq = 1;
        }
        else
        {
            allFreq[index].freq++;
        }
    }

    int flag = 0;
    printf("[");
    for (int i = 0; i < counter; i++)
    {
        if (allFreq[i].freq < k)
        {
            if (flag == 0)
            {
                printf("\"%s\"", allFreq[i].string);
                flag = 1;
            }
            else
            {
                printf(", \"%s\"", allFreq[i].string);
            }
        }
    }
    printf("]");

    return 0;
}
