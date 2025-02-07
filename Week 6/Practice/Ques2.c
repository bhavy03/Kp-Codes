// this is how to modify a string
// void removeWhitespaces(char *exp)
// {
// int i = 0, j = 0;
// while (exp[i] != '\0')
// {
// if (exp[i] != ' ' && exp[i] != '\t' && exp[i] != '\n')
// {
// exp[j] = exp[i];
// j++;
// }
// i++;
// }
// exp[j] = '\0';
// }

// this is how to convert corresponding array of chars
// char exp[26] = {0};
// scanf("%[^\n]%*c", exp);
// for (int i = 0; exp[i] != '\0'; i++)
// {
// printf("%d", exp[i] - 'a');
// }

// this is to do if input is int only
// int a;
// if (scanf("%d", &a) != 1)
// printf("no");
// else
// printf("The number is %d\n", a);

// this is to check if a given number is prime or not
// int isPrime(int num)
// {
// if (num < 2)
// return 0; // 0 and 1 are not prime number
// till sqrt of num cause after that repeatations take place
// for (int i = 2; i * i <= num; i++)
// {
// if (num % i == 0)
// {
// return 0; // Not a prime number
// }
// }
// return 1; // Prime number
// }

// this is conversion of ascii values
// printf("\n");
// char ch = ('z'+3);
// int a = (int)(ch);
// printf("%d", a%122);
// printf("%c",'a'+3-1);
// char ch = ('z' + 3);
// int a = (ch - 'a');
// printf("%d\n", a%26);
// printf("%c\n",(a%26)+'a');

// if in static 2D array function declaration the size of arr is not known
// then we have to first write int size then int arr[][size] like this
// void flip(int n, int arr[n][n])
// if arr is statically declared like arr[n][n] in main
// then we can't declare it in function call like this void flip(int n, int **arr)
// cause this a pointer type and in main it arr type

// scanf doesn't take input after space in string but it ignores spaces, newline and tabs integers
// scanf("%d %d",&c,&r);
// or
// scanf("%d", &r);
// scanf("%d",&c);
// these above two both work in same way no difference whether take input as newline or spaced

// In C, when you pass a pointer (e.g., struct Node *head) to a function, the function receives a copy of the pointer,
// not the actual pointer from the calling function. So, when you modify the pointer inside the function,
// you only modify the copy of the pointer within the function scope, not the original pointer in main.
// Even though you modify the content of the node (e.g., ptr->data),
// the head pointer in main doesn't get updated to the new node unless you return the modified pointer back to main.

// Why the copy happens: In C, when you pass a pointer to a function,
// you are passing the value of the pointer (not the address of the original pointer).
// So inside the function, you're working with a local copy of the pointer.
// Any change to the pointer itself (e.g., changing where it points)
// won't affect the original pointer unless you return it and assign it back in main.

// here is the example
// setting ptr = NULL within the function only affects the local copy of the pointer.
// The original pointer p in main remains unchanged.
// void modifyPointer(int *ptr) {
//     *ptr = 10; // Modify the value pointed to by the pointer
//     ptr = NULL; // Modify the pointer itself
// }
// int main() {
//     int x = 5;
//     int *p = &x;
//     printf("Before: x = %d, p = %p\n", x, p);
//     modifyPointer(p);
//     printf("After: x = %d, p = %p\n", x, p);
//     Before: x = 5, p = 0x7ffeefbff58c
//     After: x = 10, p = 0x7ffeefbff58c
//     return 0;
// }

// now this is how to modify the pointer also
// void modifyPointer(int **ptr) {
//     **ptr = 10; // Modify the value pointed to by the pointer
//     *ptr = NULL; // Modify the pointer itself
// }
// modifyPointer(&p);

// void modifyPointer(int **ptr,int **nptr) {
//     // **ptr = 10; // Modify the value pointed to by the pointer
//     *ptr = *nptr ; // Modify the pointer itself
//     printf("%d",**ptr);
// }
// int x = 5,z =12;
// int *p = &x;
// int *k = &z;
// modifyPointer(&p,&k);

// this is to take input as integers
// int main()
// {
// int num = 0;
// while (scanf("%d", &num) == 1)
// {
// printf("%d", num);
// Check if the next character is a newline or space
// if (getchar() == '\n')
// {
// break;
// }
// }
// printf("hello");
// return 0;
// }

// this is to print every string and every char
// #include <stdio.h>
// void print(char **ptr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; *(*(ptr + i) + j) != '\0'; j++)
//         for (int j = 0; ptr[i][j] != '\0'; j++)
//         {
//             printf("%c ", *(*(ptr + i) + j));
//             printf("%c ", ptr[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     char *arr[] = {"Geek", "Geeks", "Geekfor"};
//     for (int i = 0; i < 3; i++)
//     {
//         printf("%s\n", arr[i]);
//     }
//     print(arr, 3);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// typedef struct Stack
// {
//     int *arr;
//     int top;
//     int size;
//     int bottom;
// } Stack;
// int isFull(Stack *s)
// {
//     // printf("%d %d", s->top, s->size);
//     return (s->top == s->size - 1);
// }
// void push(Stack *s, int value)
// {
//     if (isFull(s))
//     {
//         printf("Can't push the values\n");
//         return;
//     }
//     else
//     {
//         if (s->bottom == -1)
//         {
//             s->bottom = 0;
//         }
//         s->top++;
//         s->arr[s->top] = value;
//     }
//     return;
// }
// int isEmpty(Stack *s)
// {
//     return s->bottom == -1;
// }
// int pop(Stack *s)
// {
//     if (isEmpty(s))
//     {
//         printf("Can't pop further\n");
//         return 0;
//     }
//     else
//     {
//         int poppedValue = s->arr[s->bottom];
//         s->bottom++;
//         return poppedValue;
//     }
// }
// void display(Stack *s)
// {
//     if (isEmpty(s))
//     {
//         printf("Stack is empty\n");
//     }
//     else
//     {
//         for (int i = s->bottom; i <= s->top; i++)
//         {
//             printf("%d ", s->arr[i]);
//         }
//     }
// }
// int main()
// {
//     Stack *s = (Stack *)malloc(sizeof(Stack));
//     s->top = -1;
//     s->size = 20;
//     s->bottom = -1;
//     s->arr = (int *)malloc(s->size * sizeof(int));
//     int value;
//     while ((scanf("%d", &value)) == 1)
//     {
//         push(s, value);
//         if (getchar() == '\n')
//         {
//             break;
//         }
//     }
//     display(s);
//     printf("\n");
//     int data = pop(s);
//     printf("Popped Value %d\n", data);
//     data = pop(s);
//     printf("Popped Value %d\n", data);
//     data = pop(s);
//     printf("Popped Value %d\n", data);
//     display(s);
//     free(s->arr);
//     free(s);
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char *string;
    int top;
    int size;
} Stack;

void push(Stack *s, char c)
{
    if (s->top == s->size - 1)
    {
        return;
    }
    else
    {
        s->top++;
        s->string[s->top] = c;
    }
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        return '\0';
    }
    char poppedChar = s->string[s->top];
    s->top--;
    return poppedChar;
}

int main()
{
    char exp[100];
    scanf("%[^\n]%*c", exp);

    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = strlen(exp);
    s->string = (char *)malloc((s->size + 1) * sizeof(char));
    int flag = 1;
    char *str = exp;
    while (*str != '\0')
    {
        char c = *str;

        if (c == ')' || c == '}' || c == ']')
        {
            if (s->top == -1)
            {
                flag = 0;
                break;
            }
            char popped = pop(s);
            if ((popped == '(' && c != ')') ||
                (popped == '{' && c != '}') ||
                (popped == '[' && c != ']'))
            {
                flag = 0;
                break;
            }
        }
        else if (c == '(' || c == '{' || c == '[')
        {
            push(s, c);
        }
        str++;
    }

    if (flag == 1 && s->top == -1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    free(s->string);
    free(s);

    return 0;
}
