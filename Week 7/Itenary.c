#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct paths
{
    char *start;
    char *end;
} paths;

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

int findSource(paths *allPaths, int n)
{
    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < n; j++)
        {
            if (strCmp(allPaths[i].start, allPaths[j].end))
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
            return i;
    }
    return 0;
}

int findNext(paths *allPaths, char *last, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strCmp(allPaths[i].start, last))
        {
            return i;
            break;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    paths allPaths[100000];

    char exp[1000];
    scanf("\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n]%*c", exp);
        int size = strlen(exp);

        char *str = exp;
        char *e = (str) + (size - 1);
        while (*e == ' ')
            e--;

        while (*str == ' ')
        {
            str++;
        }

        int index = 0;
        allPaths[i].start = (char *)malloc(101 * sizeof(char));
        while (*str != '-')
        {
            allPaths[i].start[index] = *str;
            str++;
            index++;
        }
        index--;
        allPaths[i].start[index] = '\0';

        while (*str == ' ' || *str == '-' || *str == '>')
        {
            str++;
        }

        index = 0;
        allPaths[i].end = (char *)malloc(101 * sizeof(char));
        while (str <= e)
        {
            allPaths[i].end[index] = *str;
            str++;
            index++;
        }

        allPaths[i].end[index] = '\0';
    }

    int sourceIndex = findSource(allPaths, n);
    printf("%s->%s", allPaths[sourceIndex].start, allPaths[sourceIndex].end);

    char *last = allPaths[sourceIndex].end;
    for (int i = 0; i < n - 1; i++)
    {
        int current = findNext(allPaths, last, n);
        if (current != -1)
        {
            printf(", %s->%s", allPaths[current].start, allPaths[current].end);
            last = allPaths[current].end;
        }
    }

    return 0;
}
