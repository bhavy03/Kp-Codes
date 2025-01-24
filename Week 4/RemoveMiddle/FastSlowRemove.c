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
    else
    {
        newNode->next = head;
        head = newNode;
    }
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
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *deleteAtPosition(struct Node *head, int pos)
{
    int index = 1;
    struct Node *ptr = head;
    while (ptr != NULL && index < pos - 1)
    {
        ptr = ptr->next;
        index++;
    }
    if (ptr == NULL)
    {
        return head;
    }
    printf("%d\n", ptr->data);
    struct Node *temp = ptr->next;
    ptr->next = ptr->next->next;

    free(temp);
    return head;
}
int findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    int index = 1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        index++;
    }
    return index;
}
int main()
{
    struct Node *head = NULL;
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);
    head = insertAtPosition(head, 4, 4);
    int middle = findMiddle(head);
    printf("%d\n", middle);
    head = deleteAtPosition(head, middle);
    display(head);
    return 0;
}
