#include <stdio.h>
#include <stdlib.h>

// void removeWhitespaces(char *exp)
// {
// char *p = exp;
// char *q = exp;
// while (*q != '\0')
// {
// if (!isspace(*q))
// {
// *p++ = *q;
// }
// q++;
// }
// *p = '\0';
// };

void removeWhitespaces(char *exp)
{
    int i = 0, j = 0;

    // Loop through each character in the string
    while (exp[i] != '\0')
    {
        // Check if the character is not a whitespace (spaces, tabs, etc.)
        if (exp[i] != ' ' && exp[i] != '\t' && exp[i] != '\n')
        {
            exp[j] = exp[i]; // Copy non-whitespace character
            j++;
        }
        i++;
    }

    // Null-terminate the modified string
    exp[j] = '\0';
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int checkValidity(char *exp)
{
    char oprs[4] = {'+', '-', '*', '/'};
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];

        // Check for invalid characters
        if (!(c >= '0' && c <= '9') && !isOperator(c))
        {
            return 0; // Invalid character
        }

        // Check for sequential operators
        if (isOperator(c) && isOperator(exp[i + 1]))
        {
            return 0; // Consecutive operators
        }
        // if (!(exp[i] >= '0' && exp[i] <= '9') && !(exp[i] == '+' || exp[i] == '*' || exp[i] == '-' || exp[i] == '/'))
        // {
        // return 0;
        // }
        // if ((exp[i] == oprs[0] || exp[i] == oprs[1] || exp[i] == oprs[2] || exp[i] == oprs[3]) && (exp[i + 1] == oprs[0] || exp[i + 1] == oprs[1] || exp[i + 1] == oprs[2] || exp[i + 1] == oprs[3]))
        // {
        // return 0;
        // }
        if (exp[i] == '/' && exp[i + 1] == '0')
        {
            return 2;
        }
    }
    return 1;
}

int ifIsdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int strLen(const char *exp)
{
    int length = 0;
    while (exp[length] != '\0')
    {
        length++;
    }
    return length;
}

// The const ensures the function does not modify the input string.
// This is important for safety when working with pointers to strings passed to functions.

int calculate(const char *exp)
{
    int stack[100];
    int top = -1;
    char sign = '+';
    int num = 0;
    int i = 0;
    int len = strLen(exp);

    for (i = 0; i < len; i++)
    {
        char c = exp[i];

        if (ifIsdigit(c))
        {
            num = num * 10 + (c - '0');
        }

        // if the char is operator or end of string
        if (!ifIsdigit(c) || i == len - 1)
        {
            if (sign == '+')
            {
                stack[++top] = num;
            }
            else if (sign == '-')
            {
                stack[++top] = -num;
            }
            else if (sign == '*')
            {
                stack[top] = stack[top] * num;
            }
            else if (sign == '/')
            {
                stack[top] = stack[top] / num;
            }

            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (i = 0; i <= top; i++)
    {
        result += stack[i];
    }

    return result;
}

int main()
{
    int ans;
    char exp[100];
    printf("Enter the mathematical expression: ");
    fgets(exp, 100, stdin);
    removeWhitespaces(exp);
    ans = checkValidity(exp);
    if (ans == 1)
    {
        int result = calculate(exp);
        printf("Result: %d\n", result);
    }
    else if (ans == 2)
    {
        printf("Error: Division by zero.\n");
    }
    else
    {
        printf("Invalid expression\n");
    };
    return 0;
}

// Input: "3+5*2-8"
// Initialize: stack = [], sign = '+', num = 0.
// Process c = '3' → num = 3.
// Process c = '+':
// Push 3 to stack → stack = [3].
// Update sign = '+', num = 0.
// Process c = '5' → num = 5.
// Process c = '*':
// Push 5 to stack → stack = [3, 5].
// Update sign = '*', num = 0.
// Process c = '2' → num = 2.
// Process c = '-':
// Multiply top: stack = [3, 10].
// Update sign = '-', num = 0.
// Process c = '8' → num = 8.
// End of string:
// Push -8 to stack → stack = [3, 10, -8].
// Final Result: 3 + 10 - 8 = 5.