#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int size;
} Stack;
int isEmpty(Stack *s)
{
    return s->top == -1;
}
void push(Stack *s, int data)
{
    if (s->top == s->size - 1)
    {
        return;
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

void pop(Stack *s)
{
    if (s->top == -1)
    {
        return;
    }
    s->top--;
}

int *findPse(Stack *s, int *a, int arrlen)
{
    int N = arrlen;
    int *pse = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        int count = 1;
        while ((!isEmpty(s)) && a[s->arr[s->top]] < a[i])
        {
            count += pse[s->arr[s->top]];
            pop(s);
        }
        pse[i] = isEmpty(s) ? 1 : count;
        push(s, i);
    }
    return pse;
}

int main()
{
    int num;
    int a[20];
    int index = 0;

    while ((scanf("%d", &num)) == 1)
    {
        a[index++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = index;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int *pse = findPse(s, a, index);
    for (int i = 0; i < index; i++)
    {
        printf("%d ", pse[i]);
    }
    return 0;
}