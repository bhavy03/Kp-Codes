#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
} Stack;

// Function to initialize a stack
void initializeStack(Stack *stack, int capacity)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));
}

// Check if the stack is empty
int isEmptyStack(Stack *stack)
{
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, int value)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack Underflow\n");
        return -1; // Error condition
    }
    return stack->arr[stack->top--];
}

// Get the top element of the stack
int peek(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        return -1; // Error condition
    }
    return stack->arr[stack->top];
}

// Queue structure using two stacks
typedef struct Queue
{
    Stack *stack1;
    Stack *stack2;
} Queue;

// Initialize the queue
void initializeQueue(Queue *queue, int capacity)
{
    queue->stack1 = (Stack *)malloc(sizeof(Stack));
    queue->stack2 = (Stack *)malloc(sizeof(Stack));
    initializeStack(queue->stack1, capacity);
    initializeStack(queue->stack2, capacity);
}

// Enqueue operation (Add element to the queue)
void enqueue(Queue *queue, int value)
{
    // Step 1: Move all elements from stack1 to stack2
    while (!isEmptyStack(queue->stack1))
    {
        push(queue->stack2, pop(queue->stack1));
    }

    // Step 2: Push the new element onto stack1
    push(queue->stack1, value);

    // Step 3: Move all elements back from stack2 to stack1
    while (!isEmptyStack(queue->stack2))
    {
        push(queue->stack1, pop(queue->stack2));
    }
}

// Dequeue operation (Remove element from the queue)
int dequeue(Queue *queue)
{
    if (isEmptyStack(queue->stack1))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return pop(queue->stack1);
}

// Peek operation (Retrieve front element)
int front(Queue *queue)
{
    if (isEmptyStack(queue->stack1))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return peek(queue->stack1);
}

// Check if the queue is empty
int isEmptyQueue(Queue *queue)
{
    return isEmptyStack(queue->stack1) && isEmptyStack(queue->stack2);
}

// Size of the queue
int size(Queue *queue)
{
    return queue->stack1->top + 1;
    // return queue->stack1->top + 1 + queue->stack2->top + 1;
}

// Display the queue (for debugging purposes)
void display(Queue *queue)
{
    printf("Queue elements: ");

    int queueSize = size(queue);

    for (int i = 0; i < queueSize; i++)
    {
        printf("%d ", queue->stack1->arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, capacity = 5;

    // Dynamically allocate memory for the queue
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    initializeQueue(queue, capacity);

    while (1)
    {
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Peek the front element\n4. Check if queue is empty\n5. Size of the queue\n6. Display the queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue, value);
            display(queue);
            break;
        }
        case 2:
        {
            int dequeuedValue = dequeue(queue);
            if (dequeuedValue != -1)
            {
                printf("Dequeued value: %d\n", dequeuedValue);
            }
            display(queue);
            break;
        }
        case 3:
        {
            printf("Front element: %d\n", front(queue));
            break;
        }
        case 4:
        {
            if (isEmptyQueue(queue))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        }
        case 5:
        {
            printf("Size of queue: %d\n", size(queue));
            break;
        }
        case 6:
        {
            display(queue);
            break;
        }
        case 7:
            printf("Exiting the program.\n");
            free(queue->stack1->arr); // Free the memory of stack1
            free(queue->stack2->arr); // Free the memory of stack2
            free(queue->stack1);      // Free the stack1 structure
            free(queue->stack2);      // Free the stack2 structure
            free(queue);              // Free the queue structure
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
