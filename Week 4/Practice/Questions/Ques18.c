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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *removeKth(struct Node *head, int k)
{
    struct Node *a = head;
    struct Node *b = head;
    for (int i = 0; i < k; i++)
    {
        b = b->next;
    }
    while (b->next != NULL)
    {
        a = a->next;
        b = b->next;
    }
    a->next = a->next->next;
    a->next->next = NULL;
    // printf("%d", a->data);
    return head;
}
int main()
{
    int num = 0;
    struct Node *head = NULL;
    while ((scanf("%d", &num)) == 1)
    {
        head = insertAtEnd(head, num);
        if (getchar() == '\n')
        {
            break;
        }
    }
    int k;
    scanf("%d", &k);
    head = removeKth(head, k);
    display(head);
    return 0;
}