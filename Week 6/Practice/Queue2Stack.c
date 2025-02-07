#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    int *arr;
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
        s->arr[s->top] = data;
    }
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    else
    {
        int popped = s->arr[s->top];
        s->top--;
        return popped;
    }
}
int top(Stack *s)
{
    return s->arr[s->top];
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
typedef struct Queue
{
    Stack *s1;
    Stack *s2;
    int size;
} Queue;
Queue *intializeQueue(Queue *q, int capacity)
{
    q->s1 = (Stack *)malloc(sizeof(Stack));
    q->s2 = (Stack *)malloc(sizeof(Stack));
    q->s1->top = -1;
    q->s2->top = -1;
    q->s1->size = capacity;
    q->s2->size = capacity;
    q->s1->arr = (int *)malloc(q->s1->size * sizeof(int));
    q->s2->arr = (int *)malloc(q->s2->size * sizeof(int));
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value)
{
    while (!isEmpty(q->s1))
    {
        push(q->s2, pop(q->s1));
    }
    push(q->s1, value);
    while (!isEmpty(q->s2))
    {
        push(q->s1, pop(q->s2));
    }
}
int dequeue(Queue *q)
{
    if (isEmpty(q->s1))
    {
        printf("Underflow");
        return -1;
    }
    int popped = q->s1->arr[q->s1->top];
    q->s1->top--;
    return popped;
}
int peek(Queue *q)
{
    return q->s1->arr[q->s1->top];
}
int isEmptyQueue(Queue *q)
{
    return isEmpty(q->s1) && isEmpty(q->s2);
}

int size(Queue *q)
{
    return q->s1->top + 1;
    // return queue->stack1->top + 1 + queue->stack2->top + 1;
}
void display(Queue *q)
{
    printf("Queue elements: ");

    int queueSize = q->s1->top;

    for (int i = 0; i < queueSize + 1; i++)
    {
        printf("%d ", q->s1->arr[i]);
    }
    printf("\n");
}
int main()
{
    int choice, capacity = 20;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q = intializeQueue(q, capacity);

    while (1)
    {
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Peek the top element\n4. Check if queue is empty\n5. Size of the queue\n6. Display the queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            enqueue(q, value);
            break;
        }
        case 2:
        {
            int poppedValue = dequeue(q);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
            break;
        }
        case 3:
        {
            printf("Front element: %d\n", peek(q));
            break;
        }
        case 4:
        {
            if (isEmptyQueue(q))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        }
        case 5:
        {
            printf("Size of Queue: %d\n", size(q));
            break;
        }
        case 6:
        {
            display(q);
            break;
        }
        case 7:
            printf("Exiting the program.\n");
            free(q->s1->arr);
            free(q->s2->arr);
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
