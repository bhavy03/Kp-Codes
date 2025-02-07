#include <stdio.h>
#include <stdlib.h>
typedef struct Stack
{
    int *a;
    int top;
    int size;
} Stack;
void push(Stack *s, int data)
{
    if (s->top == s->size - 1)
    {
        return;
    }
    else
    {
        s->top++;
        s->a[s->top] = data;
    }
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
void pop(Stack *s)
{
    if (isEmpty(s))
    {
        return;
    }
    else
    {
        int popped = s->a[s->top];
        s->top--;
        // return popped;
    }
}
int *findNge(Stack *s, int *arr, int arrlen)
{
    int *nge = (int *)malloc(arrlen * sizeof(int));
    for (int i = arrlen - 1; i >= 0; i--)
    {
        while ((!isEmpty(s)) && s->a[s->top] <= arr[i])
        {
            pop(s);
        }
        if (isEmpty(s))
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = s->a[s->top];
        }
        push(s, arr[i]);
    }
    return nge;
}

int main()
{
    int arr[20];
    int num;
    int index = 0;

    while ((scanf("%d", &num)) == 1)
    {
        arr[index++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = index;
    s->a = (int *)malloc((s->size) * sizeof(int));
    int *nge = findNge(s, arr, index);
    for (int i = 0; i < index; i++)
    {
        printf("%d ", nge[i]);
    }
    printf("\n");

    // Free allocated memory
    free(s->a);
    free(s);
    free(nge);
    return 0;
}