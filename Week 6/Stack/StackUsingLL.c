#include <stdio.h>
#include <stdlib.h>
// in this we do insertFirst and deleteFirst
struct Node
{
    int data;
    struct Node *next;
};
// can use this but not provide multiple instances,modularity and encapsulation
// struct Node *top = NULL;
typedef struct Stack
{
    struct Node *top;
} stack;

// int isFull()
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     if (newNode == NULL)
//     {
//         return 1;
//     }
//     free(newNode);
//     return 0;
// }
int isEmpty(stack *s)
{
    if (s->top == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(stack *s, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    return s->top;
    // printf("%d pushed to stack\n", value);
}

// now for this pop operation we are making head which is top in this stack
// as a global pointer cause
// either we can return a value or head pointer but we are returning a value
// and in pop we are changing the head position and returning value
// but after function completion in main the position of head remains same
// so as to change the position of head we either make it global or
// pass the address and excess it as double pointer
int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1; // Returning -1 to indicate error
    }
    struct Node *temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int size(stack *s)
{
    int count = 0;
    struct Node *temp = s->top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = s->top;
    printf("Stack elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    // we have to use dma cause it will help us to use top
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;

    while (1)
    {
        printf("\n1. Push the element\n2. Pop the element\n3. Retrieve the top element\n4. Check if stack is empty\n5. Size of stack\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter the value to push: ");
            scanf("%d", &value);
            s->top = push(s, value);
            display(s);
            break;
        }
        case 2:
        {
            int poppedValue = pop(s);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
            display(s);
            break;
        }
        case 3:
        {
            printf("The top element is: %d\n", peek(s));
            break;
        }
        case 4:
        {
            if (isEmpty(s))
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
            printf("The size of the stack is: %d\n", size(s));
            break;
        }
        case 6:
            printf("Exiting the program.\n");
            free(s); // Free memory allocated for the stack
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}