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
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
struct Node *reverse(struct Node *leftHead)
{
    struct Node *ptr = leftHead;
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
struct Node *mergeAlternate(struct Node *leftHead, struct Node *rightHead)
{
    struct Node *temp1 = leftHead;
    struct Node *temp2 = rightHead;
    while (temp1 != NULL && temp2 != NULL)
    {
        struct Node *temp1Next = temp1->next; 
        struct Node *temp2Next = temp2->next; 

        // Merge temp1 and temp2
        temp1->next = temp2;     // Link temp1 to temp2
        temp2->next = temp1Next; // Link temp2 to the next node of temp1

        // Move temp1 and temp2 to their next nodes
        temp1 = temp1Next;
        temp2 = temp2Next;
    }
    return leftHead;
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
    middle->next = NULL;
    rightHead = reverse(rightHead);
    head = mergeAlternate(leftHead, rightHead);
    display(head);
    return 0;
}