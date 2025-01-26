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
        newNode->next = newNode;
        return newNode;
    }
    struct Node *ptr = head->next;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return head;
}
struct Node *deleteAtPosition(struct Node *head, int pos)
{
    return head;
}
void display(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("NULL");
        return;
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    // or
    // ptr = ptr->next;
    // while (ptr != NULL)
    // {
    //     printf("%d ", ptr->data);
    //     ptr = ptr->next;
    // }
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
    // head = deleteAtPosition(head, 3);
    display(head);
}