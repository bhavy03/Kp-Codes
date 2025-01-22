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
    // printf("insertAtend");
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
    // printf("display");
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteAtPosition(struct Node *head, int pos)
{
    // printf("deleteAtPosition");
    if (pos < 1)
    {
        return head;
    }
    // if (pos == 1) {
    //   deleteFirst(head);
    // }
    struct Node *ptr = head;
    int index = 1;

    while (ptr != NULL && index < pos - 1)
    {
        ptr = ptr->next;
        index++;
    }
    if (ptr == NULL)
    {
        printf("Position exceeds list length\n");
        // free(newNode); // Free the allocated memory for newNode
        return head;
    }

    struct Node *temp = ptr->next; // Store the node to be deleted
    ptr->next = ptr->next->next;   // Bypass the node to be deleted
    free(temp);
    return head;
}

int findMiddle(struct Node *head)
{
    struct Node *ptr = head;
    int index = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        index++;
    }
    return index / 2;
}
int main()
{
    struct Node *head = NULL;
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        head = insertAtEnd(head, num);
        // if (getchar() == '\n')
        // {
        // break;
        // }
    }
    // int middle = findMiddle(head);
    // printf("middle is %d\n",middle);
    // head = deleteAtPosition(head, middle + 1);
    display(head);
    return 0;
}
