#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

// Function to initialize the queue
void initializeQueue(struct Queue *q, int capacity)
{
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int *)malloc(capacity * sizeof(int));
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->size == 0;
}

// Check if the queue is full
int isFull(struct Queue *q)
{
    return q->size == q->capacity;
}

// Enqueue operation (Add element to the rear of the queue)
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1);
    q->arr[q->rear] = value;
    q->size++;
}

// Dequeue operation (Remove element from the front of the queue)
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1; // Error condition
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1);
    q->size--;
    return value;
}

// Get the front element of the queue
int front(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->arr[q->front];
}

// Function to implement stack using one queue
struct Stack
{
    struct Queue *q;
};

// Initialize stack
void initializeStack(struct Stack *stack, int capacity)
{
    stack->q = (struct Queue *)malloc(sizeof(struct Queue));
    initializeQueue(stack->q, capacity);
}

// Push operation (Add element to the stack)
void push(struct Stack *stack, int value)
{
    int currentSize = stack->q->size;
    enqueue(stack->q, value);

    // Rotate the queue to make the last element at the front
    for (int i = 0; i < currentSize; i++)
    {
        int frontValue = dequeue(stack->q);
        enqueue(stack->q, frontValue);
    }
    printf("Pushed %d\n", value);
}

// Pop operation (Remove top element from the stack)
int pop(struct Stack *stack)
{
    if (isEmpty(stack->q))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = dequeue(stack->q);
    printf("Popped %d\n", value);
    return value;
}

// Peek operation (Retrieve top element of the stack)
int peek(struct Stack *stack)
{
    if (isEmpty(stack->q))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return front(stack->q);
}

// Size of the stack
int size(struct Stack *stack)
{
    return stack->q->size;
}

// Check if stack is empty
int isEmptyStack(struct Stack *stack)
{
    return isEmpty(stack->q);
}

// Display the stack (contents of the queue)
void display(struct Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->q->front, count = 0; count < stack->q->size; count++)
    {
        printf("%d ", stack->q->arr[i]);
        i = (i + 1) % stack->q->capacity;
    }
    printf("\n");
}

int main()
{
    int choice, capacity = 5;
    struct Stack stack;
    initializeStack(&stack, capacity);

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
            push(&stack, value);
            break;
        }
        case 2:
        {
            int poppedValue = pop(&stack);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
            break;
        }
        case 3:
        {
            printf("Top element: %d\n", peek(&stack));
            break;
        }
        case 4:
        {
            if (isEmptyStack(&stack))
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
            printf("Size of stack: %d\n", size(&stack));
            break;
        }
        case 6:
        {
            display(&stack);
            break;
        }
        case 7:
            printf("Exiting the program.\n");
            free(stack.q->arr);
            free(stack.q);
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
