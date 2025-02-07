typedef struct Stack
{
    int *arr;
    int top;
} Stack;
int twoStacks(int maxSum, int a_count, int *a, int b_count, int *b)
{
    int sum = 0;
    int count = 0;

    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->arr = (int *)malloc(a_count * sizeof(int));
    s->top = -1;

    for (int i = 0; i < a_count; i++)
    {
        if (sum + a[i] <= maxSum)
        {
            sum += a[i];
            count++;
            s->top++;
            s->arr[s->top] = a[i];
        }
        else
        {
            break;
        }
    }

    // printf("%d\n",sum);
    // for(int i = 0;i<count;i++){
    //     printf("%d\n",s->arr[i]);
    // }

    int maxCount = 0;
    if (count > maxCount)
    {
        maxCount = count;
    }

    for (int i = 0; i < b_count; i++)
    {
        if (sum + b[i] > maxSum)
        {
            if (s->top == -1)
                break;
            sum -= s->arr[s->top];
            s->top--;
            count--;
            i--;
        }
        else
        {
            sum += b[i];
            count++;
            if (count > maxCount)
            {
                maxCount = count;
            }
        }
    }
    // printf("%d\n",sum);
    // for(int i = 0;i<count;i++){
    //     printf("%d\n",s->arr[i]);
    // }
    return maxCount;
}
