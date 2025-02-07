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
    else
    {
        struct Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    return head;
}

void display(struct Node *head)
{
    int flag = 0;
    if (head == NULL)
    {
        printf("NULL");
    }
    else
    {
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            if (flag == 0)
            {
                printf("%d", ptr->data);
                flag = 1;
            }
            else
            {
                printf("->%d", ptr->data);
            }
            ptr = ptr->next;
        }
    }
}

struct Node *sum(struct Node *sumHead, struct Node *head1, struct Node *head2)
{
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;
    int carry = 0;
    int upValue = 0;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        // struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        int value = ptr1->data + ptr2->data;
        carry = value / 10;

        if (carry == 0)
        {
            sumHead = insertAtEnd(sumHead, value + upValue);
        }
        else
        {

            sumHead = insertAtEnd(sumHead, (upValue) + (value % 10));
            upValue = carry;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return sumHead;
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *sumHead = NULL;
    int num1;
    scanf("%d", &num1);
    int num2;
    scanf("%d", &num2);
    while (num1 != 0)
    {
        int value = num1 % 10;
        head1 = insertAtEnd(head1, value);
        num1 = num1 / 10;
    }
    while (num2 != 0)
    {
        int value = num2 % 10;
        head2 = insertAtEnd(head2, value);
        num2 = num2 / 10;
    }
    sumHead = sum(sumHead, head1, head2);
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    display(sumHead);
}