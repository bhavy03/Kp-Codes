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
struct Node *deleteNodes(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *headPtr = NULL;
    struct Node *headTail = NULL;
    while (ptr != NULL)
    {
        struct Node *temp = ptr->next;
        while (temp != NULL)
        {
            if (temp->data > ptr->data)
            {
                temp = temp->next;
            }
            else
            {
                if (headPtr == NULL)
                {
                    headPtr = ptr;
                    headTail = headPtr;
                }
                else
                {
                    headTail->next = ptr;
                    headTail = headTail->next;
                }
            }
        }
        ptr = ptr->next;
    }
    return headPtr;
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
    head = deleteNodes(head);
    display(head);
    return 0;
}