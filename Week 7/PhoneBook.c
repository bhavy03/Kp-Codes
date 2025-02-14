#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    char *name;
    long long number;
    struct Node *next;
} Node;

Node *hash_map[100] = {NULL};
int hash_function(char *name)
{
    int sum = 0;
    int size = strlen(name);
    for (int i = 0; i < size; i++)
    {
        sum += name[i];
    }
    int index = sum % 100;
    return index;
}

int exists(int idx, char *name, long long number)
{
    Node *ptr = hash_map[idx];
    while (ptr)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            ptr->number = number;
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

Node *insertAtEnd(Node *head, char *name, long long number)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(node->name, name);
    node->number = number;
    node->next = NULL;

    if (head == NULL)
    {
        return node;
    }

    Node *ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = node;
    return head;
}

void add(char *name, long long number)
{
    int index = hash_function(name);
    if (exists(index, name, number))
    {
        return;
    }
    hash_map[index] = insertAtEnd(hash_map[index], name, number);
    return;
}

void search(char *name)
{
    int index = hash_function(name);
    Node *ptr = hash_map[index];
    while (ptr)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            printf("%lld\n", ptr->number);
            return;
        }
        ptr = ptr->next;
    }
    printf("Not Found\n");
    return;
}

void delete(char *name)
{
    int index = hash_function(name);
    Node *ptr = hash_map[index];
    if (ptr == NULL)
    {
        printf("Not Found\n");
        return;
    }
    if (strcmp(ptr->name, name) == 0)
    {
        hash_map[index] = hash_map[index]->next;
        printf("Success\n");
        return;
    }
    while (ptr->next != NULL)
    {
        if (strcmp(ptr->next->name, name) == 0)
        {
            ptr->next = ptr->next->next;
            printf("Success\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Not Found\n");
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    char exp[1000];
    while (getchar() == ' ')
        ;
    while (n--)
    {
        scanf("%[^\n]%*c", exp);

        if (exp[0] == 'a')
        {
            char name[101];
            long long number = 0;
            sscanf(exp, "add(\"%[^\"]\", %lld)", name, &number);
            add(name, number);
            printf("Success\n");
        }
        else if (exp[0] == 's')
        {
            char name[101];
            sscanf(exp, "search(\"%[^\"]\")", name);
            search(name);
        }
        else if (exp[0] == 'd')
        {
            char name[101];
            sscanf(exp, "delete(\"%[^\"]\")", name);
            delete (name);
        }
    }

    return 0;
}
