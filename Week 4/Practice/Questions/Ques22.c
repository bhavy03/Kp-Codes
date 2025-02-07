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
struct Node *sort012(struct Node *head)
{
    struct Node *zeroHead = NULL;
    struct Node *zeroTail = NULL;
    struct Node *oneHead = NULL;
    struct Node *oneTail = NULL;
    struct Node *twoHead = NULL;
    struct Node *twoTail = NULL;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == 0)
        {
            if (zeroHead == NULL)
            {
                zeroHead = ptr;
                zeroTail = zeroHead;
            }
            else
            {
                zeroTail->next = ptr;
                zeroTail = zeroTail->next;
            }
        }
        else if (ptr->data == 1)
        {
            if (oneHead == NULL)
            {
                oneHead = ptr;
                oneTail = oneHead;
            }
            else
            {
                oneTail->next = ptr;
                oneTail = oneTail->next;
            }
        }
        else
        {
            if (twoHead == NULL)
            {
                twoHead = ptr;
                twoTail = twoHead;
            }
            else
            {
                twoTail->next = ptr;
                twoTail = twoTail->next;
            }
        }
        ptr = ptr->next;
    }
    zeroTail->next = oneHead;
    oneTail->next = twoHead;
    twoTail->next = NULL;
    return zeroHead;
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
    head = sort012(head);
    display(head);
    return 0;
}