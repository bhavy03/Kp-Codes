#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *wordArr[20];
    int wordCount = 0;
    char exp1[100];

    while (scanf("%s", exp1) == 1)
    {
        wordArr[wordCount] = (char *)malloc((strlen(exp1) + 1) * sizeof(char));
        strcpy(wordArr[wordCount], exp1);
        wordCount++;
        if (getchar() == '\n')
            break;
    }

    for (int i = wordCount-1; i >= 0; i--)
    {
        printf("%s\n", wordArr[i]);
    }

    return 0;
}
