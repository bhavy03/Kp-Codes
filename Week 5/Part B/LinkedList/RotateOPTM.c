#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertAtEnd1(struct Node *head, int data)
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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *rotate(struct Node *head1, int k, int length)
{

    int value;
    if (k == length)
    {
        return head1;
    }
    if (k > length)
    {
        value = k % length;
    }
    else
    {
        value = k;
    }

    struct Node *tail = head1;
    while(tail->next != NULL){
        tail = tail->next;
    }

    struct Node *ptr = head1;
    int index = 1;
    while (index < value)
    {
        ptr = ptr->next;
        index++;
    }
    tail->next = head1;
    head1 = ptr->next;
    ptr->next = NULL;
    return head1;
}
int findLength(struct Node *head1)
{
    struct Node *ptr = head1;
    int length = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        length++;
    }
    return length;
}
int main()
{
    struct Node *head1 = NULL;
    int n;
    scanf("%d", &n);
    int data = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head1 = insertAtEnd1(head1, data);
    }

    int k;
    scanf("%d", &k);

    int length = findLength(head1);
    printf("Output: ");
    head1 = rotate(head1, k, length);
    display(head1);

    return 0;
}
