#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Stack
{
    int top;
    char **stringArr;
    int capacity;
} Stack;

void addWeb(Stack *s, char *url)
{
    // if (s->top == s->capacity - 1) // Check if stack is full
    // {
    //     s->capacity *= 2; // Double the capacity
    //     s->stringArr = realloc(s->stringArr, s->capacity * sizeof(char *));
    // }
    int len = strlen(url);
    s->top++;
    s->stringArr[s->top] = (char *)malloc((len + 1) * sizeof(char));
    if (s->stringArr[s->top] == NULL)
    {
        printf("Memory allocation failed!\n");
    }

    char *str = url;
    int index = 0;
    while (*str != '\0')
    {
        s->stringArr[s->top][index++] = *str++;
    }
    s->stringArr[s->top][index] = '\0';
    // strcpy(s->stringArr[s->top], url);
}
void history(Stack *s)
{
    int tempTop = s->top;
    if (tempTop == -1)
    {
        printf("NO preview history available\n");
        return;
    }
    while (tempTop >= 0)
    {
        printf("%s\n", s->stringArr[tempTop]);
        tempTop--;
    }
}
void edit(Stack *s)
{
    for (int i = s->top, j = 0; i > -1, j <= s->top; i--, j++)
    {
        printf("%d %s\n", j + 1, s->stringArr[i]);
    }
    printf("Enter the number\n");
    int x;
    scanf("%d", &x);

    char exp[100];
    scanf("%s", exp);
    strcpy(s->stringArr[s->top - x + 1], exp);
    printf("String Updated Successfully\n");
    history(s);
}
char *removed(Stack *s)
{
    if (s->top == -1)
    {
        printf("No URLs to remove\n");
        return NULL;
    }

    char *removedUrl = s->stringArr[s->top];
    s->top--; // Decrement top after accessing the element
    return removedUrl;
}
int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->capacity = 20;
    s->stringArr = (char **)malloc(s->capacity * sizeof(char *));
    int choice;
    while (1)
    {
        printf("1. Add a website\n2. View History\n3. Edit URL\n4. Remove recent\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
        {
            printf("Enter the url:\n");
            char url[100];
            scanf("%[^\n]%*c", url);
            addWeb(s, url);
            break;
        }
        case 2:
        {
            history(s);
            break;
        }
        case 3:
        {
            edit(s);
            break;
        }
        case 4:
        {
            char *exp = removed(s);
            if (exp != NULL)
            {
                printf("The removed string is: %s\n", exp);
                free(exp); // Make sure to free the memory once you're done using it
            }
            break;
        }
        default:
        {
            printf("Enter valid choice");
        }
        }
    }
    for (int i = 0; i <= s->top; i++)
    {
        free(s->stringArr[i]);
    }
    free(s->stringArr);
    free(s);
    return 0;
}