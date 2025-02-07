#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
int findIndex(struct Node *head)
{
    struct Node *ptr = head;
    int index = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        index++;
    }
    return index - 1;
}
int findDecimal(struct Node *head, int index)
{
    struct Node *ptr = head;
    double sum = 0;
    while (ptr != NULL && index > -1)
    {
        sum = sum + (pow(2, index) * ptr->data);
        // printf("%.2lf\n", sum);
        ptr = ptr->next;
        index--;
    }
    return sum;
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
    // display(head);
    int index = findIndex(head);
    double decimal = findDecimal(head, index);
    // printf("%.2lf", pow(2, a));
    printf("%.2lf", decimal);
    return 0;
}