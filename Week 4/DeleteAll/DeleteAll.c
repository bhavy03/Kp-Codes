#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (head == NULL) {
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
  } else {
    struct Node *ptr = head;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    return head;
  }
}

void display(struct Node *head) {
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *deleteAtPosition(struct Node *head, int value) {
  struct Node *ptr = head;
  if (ptr->next == NULL && ptr->data == value) {
    printf("NULL");
    return 0;
  }

  while (ptr->next != NULL) {
    if (ptr->next->data == value) {

      struct Node *newTemp = ptr->next;
      ptr->next = ptr->next->next;
      free(newTemp);
    } else {
      ptr = ptr->next;
    }
  }

  return head;
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
  int value;
  scanf("%d", &value);
  head = deleteAtPosition(head, value);
  display(head);
  return 0;
}
