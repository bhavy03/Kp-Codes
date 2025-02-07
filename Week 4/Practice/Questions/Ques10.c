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
void display(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("NULL");
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("%d", head->data);
}
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    struct Node *middle = findMiddle(head);
    struct Node *leftHead = head;
    struct Node *rightHead = middle->next;
    struct Node *ptr = rightHead;
    while (ptr->next != leftHead)
    {
        ptr = ptr->next;
    }
    middle->next = leftHead;
    ptr->next = rightHead;
    display(leftHead);
    printf("\n");
    display(rightHead);
    return 0;
}