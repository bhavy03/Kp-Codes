#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
void insertAtBeginning(struct Node **head, int data) {
  // printf("insertAtBeginning");
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  if (head == NULL) {
    ptr->data = data;
    *head = ptr;
  } else {
    ptr->data = data;
    (ptr->next) = *head;
    *head = ptr;
  }
  // return head;
}
void display(struct Node *head) {
  // printf("display");
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d", ptr->data);
    ptr = ptr->next;
  }
}
int main() {
  int m;
  scanf("%d", &m);
  struct Node *head = NULL;

  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 4);
  insertAtBeginning(&head, 5);
  display(head);
return 0;
}
