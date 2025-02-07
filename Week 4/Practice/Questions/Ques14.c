#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int count;
    char *string;
    struct Node *next;
};
struct Node *insertAtEnd(struct Node *head, char *exp, int count)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->string = (char *)malloc(10 * sizeof(char));
    int index = 0;
    // while (exp[index] != '\0')
    // {
    //     newNode->string[index] = exp[index];
    //     index++;
    // }
    strcpy(newNode->string, exp);
    newNode->next = NULL;
    newNode->count = count;
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return head;
}
void display(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("NULL");
    }
    while (ptr != NULL)
    {
        printf("%s ", ptr->string);
        ptr = ptr->next;
    }
}
void *findCommon(struct Node *list1, struct Node *list2)
{
    struct Node *commonHead = NULL;
    // struct Node *commonTail = NULL;
    struct Node *temp1 = list1;
    while (temp1 != NULL)
    {
        struct Node *temp2 = list2;
        while (temp2 != NULL)
        {
            if ((strcmp(temp1->string, temp2->string)) == 0)
            {
                temp1->count++;
                temp2->count++;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    struct Node *ptr = list1;
    while (ptr != NULL)
    {
        if (ptr->count == 2)
        {
            printf("%s ", ptr->string);
        }
        ptr = ptr->next;
    }
}

void findUnion(struct Node *list1, struct Node *list2)
{
    display(list1);
    struct Node *ptr = list2;
    while (ptr != NULL)
    {
        if (ptr->count == 1)
        {
            printf("%s ", ptr->string);
        }
        ptr = ptr->next;
    }
}
int main()
{
    char exp[100];
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    while ((scanf("%s", exp)) == 1)
    {
        head1 = insertAtEnd(head1, exp, 1);
        if (getchar() == '\n')
        {
            break;
        }
    }
    while ((scanf("%s", exp)) == 1)
    {
        head2 = insertAtEnd(head2, exp, 1);
        if (getchar() == '\n')
        {
            break;
        }
    }

    // display(head1);
    // display(head2);

    findCommon(head1, head2);
    printf("\n");
    findUnion(head1, head2);

    return 0;
}