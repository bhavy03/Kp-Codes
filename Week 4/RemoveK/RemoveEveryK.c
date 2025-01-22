#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
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
    return head;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("NULL");
        return;
    }
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteAtPosition(struct Node *head, int value)
{
    if (head == NULL || value <= 0)
    {
        return head;
    }
    if (value == 1)
    {
        struct Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        return NULL;
    }
    struct Node *ptr1 = head;
    struct Node *ptr2 = head;
    int index = 1;
    while (ptr2 != NULL)
    {
        if (index % value == 0)
        {
            struct Node *newTemp = ptr2;
            ptr1->next = ptr2->next;
            ptr2 = ptr2->next;
            // ptr1 = ptr1->next;
            free(newTemp);
        }
        else
        {
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        index++;
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        head = insertAtEnd(head, num);
        if (getchar() == '\n')
        {
            break;
        }
    }
    int value;
    scanf("%d", &value);
    head = deleteAtPosition(head, value);
    display(head);
    return 0;
}
