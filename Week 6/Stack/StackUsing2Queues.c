#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue
typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to initialize a queue
Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->arr = (int *)malloc(capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is empty
int isEmptyQueue(Queue *q)
{
    return (q->front == q->rear);
}

// Function to enqueue an element to the queue
void enqueue(Queue *q, int value)
{
    if (q->rear == q->capacity)
    {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front++];
}

// Function to get the front element of the queue
int front(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

// Stack implementation using two queues
typedef struct Stack
{
    Queue *q1;
    Queue *q2;
    int size;
} Stack;

// Function to create a stack using two queues
Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    stack->size = 0;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return (stack->size == 0);
}

// Function to get the size of the stack
int size(Stack *stack)
{
    return stack->size;
}

// Function to push an element onto the stack
void push(Stack *stack, int value)
{
    // Enqueue the new element to the empty queue (q2)
    enqueue(stack->q2, value);

    // Transfer all elements from q1 to q2 to maintain stack order
    while (!isEmptyQueue(stack->q1))
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    // Swap the roles of q1 and q2, so q1 always contains the stack
    Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    stack->size++;
}

// Function to pop the top element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }

    int value = dequeue(stack->q1);
    stack->size--;
    return value;
}

// Function to peek the top element of the stack without removing it
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return front(stack->q1);
}

int main()
{
    Stack *stack = createStack(10);

    // Testing stack operations
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack)); // 30
    printf("Stack size: %d\n", size(stack));  // 3

    printf("Popped element: %d\n", pop(stack));        // 30
    printf("Popped element: %d\n", pop(stack));        // 20
    printf("Stack size after pop: %d\n", size(stack)); // 1

    printf("Top element: %d\n", peek(stack)); // 10

    pop(stack);                                     // Remove 10
    printf("Is stack empty? %d\n", isEmpty(stack)); // 1 (true)

    return 0;
}
