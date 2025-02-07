#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
// assume **head = **ptr
// **ptr stores the address of head
// and head stores the address of node
// **ptr -> *head -> node;
void insertAtBeginning(struct Node **head, int data)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = data;
  if (*head == NULL)
  {
    *head = ptr;
  }
  else
  {
    (ptr->next) = *head;
    *head = ptr;
  }
}
void display(struct Node *head)
{
  // printf("display");
  struct Node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d", ptr->data);
    ptr = ptr->next;
  }
}
int main()
{
  struct Node *head = NULL;

  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 4);
  insertAtBeginning(&head, 5);
  display(head);
  return 0;
}
