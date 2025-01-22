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
    if (head == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->data = data;
        newNode->next = NULL;
        return head;
    }
}

void display(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteAtPosition(struct Node *head, int pos)
{
    if (pos == 1)
    {
        return 0;
    }
    struct Node *ptr = head;
    int index = 1;
    while (index < pos - 1)
    {
        ptr = ptr->next;
        index++;
    }
    struct Node *temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
    return head;
}

int findMiddle(struct Node *head)
{
    struct Node *ptr = head;
    int index = 1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        index++;
    }
    return index / 2 + 1;
}

int main()
{
    struct Node *head = NULL;
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        head = insertAtEnd(head, num);
        // if (getchar() == '\n') {
        //   break;
        // }
    }
    int middle = findMiddle(head);
    head = deleteAtPosition(head, middle);
    display(head);
    return 0;
}
