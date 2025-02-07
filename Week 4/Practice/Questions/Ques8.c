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
struct Node *reverse(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev = NULL;
    while (ptr != NULL)
    {
        struct Node *front = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = front;
    }
    return prev;
}
struct Node *findKNode(struct Node *temp, int k)
{
    struct Node *ptr = temp;
    int index = 1;
    while (ptr != NULL && index < k)
    {
        ptr = ptr->next;
        index++;
    }
    if (ptr == NULL)
    {
        return NULL;
    }
    return ptr;
}
struct Node *reverseInk(struct Node *head, int k)
{
    struct Node *temp = head;
    struct Node *kthNode = NULL;
    struct Node *nextNode = NULL;
    struct Node *prevNode = NULL;
    while (temp != NULL)
    {
        kthNode = findKNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevNode)
            {
                prevNode->next = temp;
            }
            break;
        }
        nextNode = kthNode->next;
        kthNode->next = NULL;
        kthNode = reverse(temp);
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
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
    head = reverseInk(head, k);
    display(head);
    return 0;
}