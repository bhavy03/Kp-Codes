#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int *arr;
    int size;
} Queue;
void enqueue(Queue *q, int data)
{
    if (q->rear == q->size - 1)
    {
        return;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}
int dequeue(Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        return -1;
    }
    else
    {
        int value = q->arr[q->front];
        q->front++;
        return value;
    }
}
int isEmpty(Queue *q)
{
    return (q->front == -1 || q->front > q->rear);
}
void print(Queue *q, int numBits)
{
    int arr[numBits];
    int index = numBits - 1;
    for (int i = 0; i < numBits; i++)
    {
        arr[i] = 0;
    }
    // printf("places %d\n", noPlaces);
    while (q->front <= q->rear)
    {
        int bit = dequeue(q);
        arr[index--] = bit;
    }
    // printf("%d ", bit);
    for (int i = 0; i < numBits; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    int numBits = 0;
    int temp = n;
    while (temp > 0)
    {
        numBits++;
        temp = temp / 2;
    }
    // printf("bits %d\n", numBits);
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    q->size = 50;
    q->arr = (int *)malloc(q->size * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        q->front = q->rear = -1;
        while (num > 0)
        {
            int mod = num % 2;
            enqueue(q, mod);
            num = num / 2;
        }
        print(q, numBits);
    }
    free(q->arr);
    free(q);

    return 0;
}