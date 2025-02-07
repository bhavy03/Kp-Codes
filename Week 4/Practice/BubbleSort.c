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
struct Node *bubbleSort(struct Node *head)
{
    // Check for empty or single node list
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *i, *j;
    int swapped;

    // Loop until no swapping happens
    do
    {
        swapped = 0;
        i = head;

        while (i->next != NULL)
        {
            j = i->next;

            // Swap the data if they are in the wrong order
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
                swapped = 1;
            }

            i = i->next;
        }
    } while (swapped); // Repeat the outer loop until no swaps happen

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