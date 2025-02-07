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
int findKth(struct Node *head, int k)
{
    struct Node *ptr = head;
    int index = 1;
    while (ptr != NULL && index < k)
    {
        ptr = ptr->next;
        index++;
    }
    return ptr->data;
}
int optFind(struct Node *head, int k)
{
    struct Node *a = head;
    struct Node *b = head;
    for (int i = 0; i < k; i++)
    {
        b = b->next;
    }
    while (b != NULL)
    {
        a = a->next;
        b = b->next;
    }
    return a->data;
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
    int optValue = optFind(head, k);
    printf("%d\n", optValue);

    head = reverse(head);
    int value = findKth(head, k);
    printf("%d\n", value);
    // display(head);
    return 0;
}