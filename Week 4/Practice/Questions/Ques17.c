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
struct Node *findOddEven(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;

    while (ptr != NULL)
    {
        if (ptr->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = ptr;
                evenTail = evenHead;
            }
            else
            {
                evenTail->next = ptr;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = ptr;
                oddTail = oddHead;
            }
            else
            {
                oddTail->next = ptr;
                oddTail = oddTail->next;
            }
        }
        ptr = ptr->next;
    }

    if (evenHead == NULL)
    {
        return head;
    }

    evenTail->next = oddHead;

    if (oddTail != NULL)
    {
        oddTail->next = NULL;
    }

    head = evenHead;
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
    head = findOddEven(head);
    display(head);
    return 0;
}