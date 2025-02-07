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
int *findnse(Stack *s, int *arr, int arrlen)
{
    int *nse = (int *)malloc(arrlen * sizeof(int));
    for (int i = 0; i < arrlen; i++)
    {
        while ((!isEmpty(s)) && s->a[s->top] >= arr[i])
        {
            pop(s);
        }
        if (isEmpty(s))
        {
            nse[i] = -1;
        }
        else
        {
            nse[i] = s->a[s->top];
        }
        push(s, arr[i]);
    }
    return nse;
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
    int *nse = findnse(s, arr, index);
    for (int i = 0; i < index; i++)
    {
        printf("%d ", nse[i]);
    }
    printf("\n");

    // Free allocated memory
    free(s->a);
    free(s);
    free(nse);
    return 0;
}