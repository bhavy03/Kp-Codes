typedef struct Stack
{
    int *arr;
    int top;
    int size;
} Stack;

void push(Stack *s, int value)
{
    if (s->top == s->size - 1)
        return;
    s->top++;
    s->arr[s->top] = value;
}

int pop(Stack *s)
{
    if (s->top == -1)
        return -1;
    int poppedValue = s->arr[s->top];
    s->top--;
    return poppedValue;
}

int isPrime(int num)
{
    for (int j = 2; j * j <= num; j++)
    {
        if (num % j == 0)
            return 0;
    }
    return 1;
}

int *waiter(int number_count, int *number, int q, int *result_count)
{
    *result_count = number_count;
    int *answers = (int *)malloc(number_count * sizeof(int));
    int primes[q];
    int count = 0;
    int num = 2;

    while (count < q)
    {
        if (isPrime(num))
        {
            primes[count++] = num;
        }
        num++;
    }

    Stack *s1 = (Stack *)malloc(sizeof(Stack));
    Stack *s2 = (Stack *)malloc(sizeof(Stack));
    s1->size = number_count;
    s2->size = number_count;
    s1->top = -1;
    s2->top = -1;
    s1->arr = (int *)malloc(s1->size * sizeof(int));
    s2->arr = (int *)malloc(s2->size * sizeof(int));

    int ansTop = 0;
    for (int i = 0; i < q; i++)
    {

        for (int j = number_count - 1; j >= 0; j--)
        {
            if (number[j] % primes[i] == 0)
            {
                push(s2, number[j]);
            }
            else
            {
                push(s1, number[j]);
            }
        }

        while (s2->top != -1)
        {
            answers[ansTop++] = pop(s2);
        }

        int size = s1->top;
        for (int i = size; i >= 0; i--)
        {
            number[i] = pop(s1);
        }
        number_count = size + 1;
    }

    for (int i = number_count - 1; i >= 0; i--)
    {
        answers[ansTop++] = number[i];
    }

    return answers;
}