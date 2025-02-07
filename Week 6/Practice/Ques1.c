#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int top;
    char **string;
} Stack;
void push(Stack *s, char *exp, int length)
{
    s->top++;
    s->string[s->top] = (char *)malloc(length * sizeof(char));
    strcpy(s->string[s->top], exp);
}
char *pop(Stack *s)
{
    char *poppedString = s->string[s->top];
    s->top--;
    return poppedString;
}
char *formCombined(char *exp1, char *exp2, char c)
{
    int len = strlen(exp1) + strlen(exp2) + 5;
    char *combined = (char *)malloc(len * sizeof(char));
    char *ptr = combined;

    *ptr++ = '(';
    while (*exp1)
        *ptr++ = *exp1++;

    *ptr++ = c;

    while (*exp2)
        *ptr++ = *exp2++;

    *ptr++ = ')';
    *ptr = '\0';

    // sprintf(combined, "(%s%c%s)", exp1, c, exp2);
    return combined;
}
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int isOperand(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int main()
{
    char exp[100];
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->string = (char **)malloc(100 * sizeof(char *));
    s->top = -1;
    scanf("%[^\n]%*c", exp);
    int length = strlen(exp);
    for (int i = length - 1; i >= 0; i--)
    {
        char c = exp[i];
        if (isOperand(c))
        {
            char operand[2] = {c, '\0'};
            push(s, operand, length);
        }
        if (isOperator(c))
        {
            char *exp1 = pop(s);
            char *exp2 = pop(s);
            char *combined = formCombined(exp1, exp2, c);
            push(s, combined, length);
        }
    }
    printf("%s", pop(s));
    return 0;
}