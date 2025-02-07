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
    newNode->next = NULL;
    newNode->data = data;
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
struct Node *getIntersectionNode(struct Node *headA, struct Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct Node *temp1 = headA;
    struct Node *temp2 = headB;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
        {
            return temp1;
        }

        if (temp1 == NULL)
            temp1 = headB;
        if (temp2 == NULL)
            temp2 = headA;
    }
    return temp1;
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

    struct Node *head2 = NULL;
    // display(head);
    head = getIntersectionNode(head, head2);
    // printf("\n");
    display(head);

    return 0;
}
