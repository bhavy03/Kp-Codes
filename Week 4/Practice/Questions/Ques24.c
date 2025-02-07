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
struct Node *sort(struct Node *head)
{
    struct Node *temp1 = head;
    struct Node *temp2 = head;
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            int x, y;
            if (temp1->data < 0)
            {
                x = temp1->data * -1;
            }
            if (temp2->data < 0)
            {
                y = temp2->data * -1;
            }
            if (y < x)
            {
                int value = temp1->data;
                temp1->data = temp2->data;
                temp2->data = value;
                swapped = 1;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
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
    head = bubbleSort(head);
    display(head);
    return 0;
}