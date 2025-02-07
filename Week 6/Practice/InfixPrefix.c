#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack structure
typedef struct Stack
{
    int top;
    unsigned capacity;
    char *arr;
} Stack;

// Function to create a stack of given capacity
Stack *createStack(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack operations: Push and Pop
int isFull(Stack *stack) { return stack->top == stack->capacity - 1; }
int isEmpty(Stack *stack) { return stack->top == -1; }
void push(Stack *stack, char op)
{
    if (isFull(stack))
        return;
    stack->arr[++(stack->top)] = op;
}
char pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->arr[(stack->top)--];
}
char peek(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->arr[stack->top];
}

// Function to check if a character is an operator
int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check operator precedence
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to reverse a string
void reverse(char *expr)
{
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
}

// Function to convert infix to postfix
char *infixToPostfix(char *infix)
{
    Stack *stack = createStack(strlen(infix));
    char *postfix = (char *)malloc(strlen(infix) * sizeof(char));
    int k = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c))
        {
            postfix[k++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(')
        {
            push(stack, c);
        }
        // If the character is ')', pop until '(' is encountered
        else if (c == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
            {
                postfix[k++] = pop(stack);
            }
            pop(stack); // Pop '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c))
        {
            while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack)))
            {
                postfix[k++] = pop(stack);
            }
            push(stack, c);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(stack))
    {
        postfix[k++] = pop(stack);
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression

    return postfix;
}

// Function to convert infix to prefix
char *infixToPrefix(char *infix)
{
    // Step 1: Reverse the infix expression and swap parentheses
    reverse(infix);
    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    // Step 2: Convert the modified infix expression to postfix
    char *postfix = infixToPostfix(infix);

    // Step 3: Reverse the postfix expression to get the prefix expression
    reverse(postfix);
    return postfix;
}

// Main function to test the implementation
int main()
{
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char *prefix = infixToPrefix(infix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
