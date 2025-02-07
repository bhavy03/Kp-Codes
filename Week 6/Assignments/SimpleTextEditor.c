#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    char **stringArr;
    int top;
} Stack;

void append(char *exp, Stack *s)
{
    // if (s->top == 0)
    // {
    //     s->top++;
    //     int len = strlen(exp);
    //     s->stringArr[s->top] = (char *)malloc((len + 1) * sizeof(char));
    //     for (int i = 0; i < len; i++)
    //     {
    //         s->stringArr[s->top][i] = exp[i];
    //     }
    //     s->stringArr[s->top][len] = '\0';
    // }
    // else
    // {

    int prevLen = strlen(s->stringArr[s->top]);
    int currentLen = strlen(exp);

    s->top++;
    s->stringArr[s->top] = (char *)malloc((prevLen + currentLen + 1) * sizeof(char));

    for (int i = 0; i < prevLen; i++)
    {
        s->stringArr[s->top][i] = s->stringArr[s->top - 1][i];
    }

    for (int i = 0; i < currentLen; i++)
    {
        s->stringArr[s->top][prevLen + i] = exp[i];
    }

    s->stringArr[s->top][prevLen + currentLen] = '\0';
    // }
    return;
}

void delete(Stack *s, int k)
{
    int prevLen = strlen(s->stringArr[s->top]);
    if (k > prevLen)
        k = prevLen;

    s->top++;
    s->stringArr[s->top] = (char *)malloc((prevLen - k + 1) * sizeof(char));

    for (int i = 0; i < (prevLen - k); i++)
    {
        s->stringArr[s->top][i] = s->stringArr[s->top - 1][i];
    }

    s->stringArr[s->top][prevLen - k] = '\0';
}

void print(Stack *s, int k)
{
    printf("%c\n", s->stringArr[s->top][k - 1]);
}

void Undo(Stack *s)
{
    if (s->top >= 0)
    {
        free(s->stringArr[s->top]);
        s->top--;
    }
}

int main()
{
    int noOps;
    scanf("%d", &noOps);

    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->stringArr = (char **)malloc((noOps + 1) * sizeof(char *));
    s->top = 0;

    s->stringArr[s->top] = (char *)malloc(1 * sizeof(char));
    s->stringArr[s->top][0] = '\0';

    for (int i = 0; i < noOps; i++)
    {
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            char exp[1001];
            scanf(" %[^\n]", exp);
            append(exp, s);
            break;
        }
        case 2:
        {
            int k;
            scanf("%d", &k);
            delete (s, k);
            break;
        }
        case 3:
        {
            int k;
            scanf("%d", &k);
            print(s, k);
            break;
        }
        case 4:
        {
            Undo(s);
            break;
        }
        }
    }

    for (int i = 0; i <= s->top; i++)
    {
        free(s->stringArr[i]);
    }
    free(s->stringArr);
    free(s);

    return 0;
}
