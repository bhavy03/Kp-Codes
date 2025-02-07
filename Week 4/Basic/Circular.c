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
    struct Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return head;
}
struct Node *deleteAtLast(struct Node *head)
{
    if (head == NULL || head->next == head)
    {
        return NULL;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr->next->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head;
    }
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
    // printf("%d", head->data);
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
    // head = deleteAtLast(head);
    // head = deleteAtLast(head);
    display(head);
}