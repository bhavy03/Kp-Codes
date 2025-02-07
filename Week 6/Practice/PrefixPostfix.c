#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct Stack
{
    int top;
    char arr[MAX];
} Stack;

// Function to create a stack
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, char c)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to reverse the string
void reverse(char *expr)
{
    int len = strlen(expr);
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = expr[i];
        expr[i] = expr[j];
        expr[j] = temp;
    }
}

// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert Prefix expression to Postfix expression
void prefixToPostfix(char *prefix)
{
    Stack *stack = createStack();

    // Reverse the prefix expression
    reverse(prefix);

    for (int i = 0; i < strlen(prefix); i++)
    {
        char c = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c))
        {
            push(stack, c);
        }
        // If the character is an operator
        else if (isOperator(c))
        {
            // Pop two operands from the stack
            char op1 = pop(stack);
            char op2 = pop(stack);

            // Combine them in postfix order and push back to stack
            char postfix[3] = {op1, op2, c}; // e.g., AB+
            postfix[2] = c;
            for (int i = 0; i < 3; i++)
            {
                push(stack, postfix[i]);
            }
        }
    }

    // The result is the postfix expression in the stack
    printf("Postfix Expression: ");
    while (!isEmpty(stack))
    {
        printf("%c", pop(stack));
    }
    printf("\n");
}

int main()
{
    char prefix[MAX];
    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix);

    return 0;
}
