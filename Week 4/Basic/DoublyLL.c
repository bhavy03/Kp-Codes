#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = ptr;
    return head;
}
struct Node *deleteAtPosition(struct Node *head, int pos)
{
    struct Node *ptr = head;
    int index = 1;
    while (ptr != NULL && index < pos-1)
    {
        ptr = ptr->next;
        index++;
    }
    struct Node *temp = ptr->next;
    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;
    free(temp);
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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    int data = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    head = deleteAtPosition(head,3);
    display(head);
}