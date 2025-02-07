#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
    char *string;
    int top;
    int size;
} Stack;

void push(Stack *s, char c)
{
    if (s->top == s->size - 1)
    {
        return;
    }
    else
    {
        s->top++;
        s->string[s->top] = c;
    }
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
char pop(Stack *s)
{
    if (s->top == -1)
    {
        return '\0';
    }
    char poppedChar = s->string[s->top];
    s->top--;
    return poppedChar;
}
int main()
{
    char exp[100];
    scanf("%[^\n]%*c", exp);

    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = strlen(exp);
    s->string = (char *)malloc((s->size + 1) * sizeof(char));
    char *str = exp;
    while (*str != '\0')
    {
        push(s, *str++);
    }
    while (!(isEmpty(s)))
    {
        char ch = pop(s);
        printf("%c", ch);
    }
    return 0;
}