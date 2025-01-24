#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    return newNode;
  }
  struct Node *ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = newNode;
  return head;
}

void display(struct Node *head) {
  if (head == NULL) {
    printf("NULL");
    return;
  }
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *reverse(struct Node *head) {
  if (head == NULL) {
    return head;
  }
  struct Node *temp = head;
  struct Node *prev = NULL;
  while (temp != NULL) {
    struct Node *front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

int main() {
  struct Node *head = NULL;
  int num = 0;
  while (scanf("%d", &num) == 1) {
    head = insertAtEnd(head, num);
    if (getchar() == '\n') {
      break;
    }
  }
  head = reverse(head);
  display(head);
  return 0;
}
