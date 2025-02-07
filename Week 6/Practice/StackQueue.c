#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int *arr;
    int front;
    int size;
    int rear;
    int capacity;
} Queue;

int isFull(Queue *q)
{
    return q->rear == q->capacity - 1;
}
void enqueue(Queue *q, int num)
{
    if (isFull(q))
    {
        printf("NO space");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = num;
        q->size++;
    }
}
int isEmpty(Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return -1;
    }
    else
    {
        int value = q->arr[q->front];
        q->front++;
        q->size--;
        return value;
    }
}
int peek(Queue *q)
{
    return q->arr[q->front];
}

typedef struct Stack
{
    Queue *q1;
    int size;
} Stack;

void push(Stack *s, int data)
{
    enqueue(s->q1, data);

    for (int i = 0; i < s->q1->size - 1; i++)
    {
        enqueue(s->q1, dequeue(s->q1));
    }

    // Queue *temp = s->q1;
    // s->q1 = s->q2;
    // s->q2 = temp;
    s->size++;
}
int pop(Stack *s)
{
    s->size--;
    return dequeue(s->q1);
}
int top(Stack *s)
{
    return peek(s->q1);
}
void display(Stack *s)
{
    if (isEmpty(s->q1))
    {
        printf("Queue is empty");
    }
    else
    {
        for (int i = s->q1->front; i <= s->q1->rear; i++)
        {
            printf("%d ", s->q1->arr[i]);
        }
    }
}
Stack *initializeStack(Stack *s, int capacity)
{
    s->q1 = (Queue *)malloc(sizeof(Queue));
    // s->q2 = (Queue *)malloc(sizeof(Queue));
    s->q1->capacity = capacity;
    s->q1->size = 0;
    // s->q2->size = capacity;
    s->q1->arr = (int *)malloc(s->q1->capacity * sizeof(int));
    // s->q2->arr = (int *)malloc(s->q2->size * sizeof(int));
    s->q1->front = s->q1->rear = -1;
    // s->q2->front = s->q2->rear = -1;
    s->size = 0;
    return s;
}
int main()
{
    int choice, capacity = 20;
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s = initializeStack(s, capacity);

    while (1)
    {
        printf("\n1. Push the element\n2. Pop the element\n3. Peek the top element\n4. Check if stack is empty\n5. Size of the stack\n6. Display the stack\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(s, value);
            break;
        }
        case 2:
        {
            int poppedValue = pop(s);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
            break;
        }
        case 3:
        {
            printf("Top element: %d\n", top(s));
            break;
        }
        case 4:
        {
            if (isEmpty(s->q1))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        }
        // case 5:
        // {
        //     printf("Size of stack: %d\n", size(s));
        //     break;
        // }
        case 6:
        {
            display(s);
            break;
        }
        case 7:
            printf("Exiting the program.\n");
            free(s->q1->arr);
            // free(s->q2->arr);
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
