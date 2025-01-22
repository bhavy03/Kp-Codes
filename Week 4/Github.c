#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};

struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  // printf("insertAtend");
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

struct Node *insertAtBeginning(struct Node *head, int data) {
  // printf("insertAtBeginning");
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (head == NULL) {
    newNode->data = data;
    return newNode;
  } else {
    newNode->data = data;
    newNode->next = head;
    return newNode;
  }
}

struct Node *insertAtPosition(struct Node *head, int data, int pos) {
  // printf("insertAtPosition");
  if (pos < 1) {
    return head;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (pos == 1) {
    insertAtBeginning(head, data);
  }

  struct Node *ptr = head;
  int index = 1;

  while (ptr != NULL && index < pos - 1) {
    ptr = ptr->next;
    index++;
  }
  if (ptr == NULL) {
    printf("Position exceeds list length\n");
    free(newNode); // Free the allocated memory for newNode
    return head;
  }

  newNode->data = data;
  newNode->next = ptr->next;
  ptr->next = newNode;
  return head;
}

void display(struct Node *head) {
  // printf("display");
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *updateAtPosition(struct Node *head, int pos, int data) {
  // printf("updateAtPosition");
  // struct Node *newNode = (struct Node *)malloc(sizeof(struct Node);
  if (pos < 1) {
    return head;
  }
  int index = 1;
  struct Node *ptr = head;
  while (ptr != NULL && index != pos) {
    ptr = ptr->next;
    index++;
  }
  if (ptr == NULL) {
    printf("Position exceeds list length\n");
    // free(newNode); // Free the allocated memory for newNode
    return head;
  }
  ptr->data = data;
  return head;
}

struct Node *deleteFirst(struct Node *head) {
  // printf("deleteFirst");
  if (head == NULL) {
    printf("List is empty");
    return head;
  } else {
    struct Node *ptr = head;
    head = head->next;
    ptr->next = NULL;
    free(ptr);
    return head;
  }
}

struct Node *deleteLast(struct Node *head) {
  // printf("deleteLast");
  if (head == NULL) {
    printf("List is empty");
    return head;
  } else if (head->next == NULL) {
    printf("The element is first element");
    free(head); // If there is only one node, free it
    return NULL;
  } else {
    struct Node *ptr = head;
    struct Node *nptr = head->next;
    // while (ptr->next->next != NULL) {
    //   ptr = ptr->next;
    // }
    while (nptr->next != NULL) {
      nptr = nptr->next;
      ptr = ptr->next;
    }
    ptr->next = NULL;
    free(nptr);
    return head;
  }
}

struct Node *deleteAtPosition(struct Node *head, int pos) {
  // printf("deleteAtPosition");
  if (pos < 1) {
    return head;
  }
  if (pos == 1) {
    deleteFirst(head);
  }
  struct Node *ptr = head;
  int index = 1;

  // this ptr!=NULL condition helps us preventing to go 
  // on index after length of node.
  while (ptr != NULL && index < pos - 1) {
    ptr = ptr->next;
    index++;
  }
  if (ptr == NULL) {
    printf("Position exceeds list length\n");
    // free(newNode); // Free the allocated memory for newNode
    return head;
  }

  struct Node *temp = ptr->next; // Store the node to be deleted
  ptr->next = ptr->next->next;   // Bypass the node to be deleted
  free(temp);
  return head;
}

int main() {
  int n;
  scanf("%d", &n);
  if (!(n >= 1 && n <= 100)) {
    printf("Enter valid input of n");
  }
  struct Node *head = NULL;
  // head = deleteFirst(head);
  // head = insertAtBeginning(head, 3);
  // head = insertAtEnd(head, 5);
  // head = insertAtPosition(head, 4, 2);
  // head = updateAtPosition(head, 2, 6);
  // head = deleteFirst(head);
  // head = deleteLast(head);
  // head = deleteAtPosition(head, 2);
  // insertAtBeginning(&head, 4);
  // insertAtBeginning(&head, 5);
  // display(head);
  while (n > 0) {
    int k;
    scanf("%d", &k);
    switch (k) {
    case 1: {
      int data;
      scanf("%d", &data);
      insertAtEnd(head, data);
    } break;
    case 2: {
      int data;
      scanf("%d", &data);
      insertAtBeginning(head, data);
    } break;
    case 3: {
      int data, pos;
      scanf("%d %d", &data, &pos);
      insertAtPosition(head, data, pos);
    } break;
    case 4: {
      display(head);
      break;
    }
    case 5: {
      int data, pos;
      scanf("%d %d", &data, &pos);
      updateAtPosition(head, pos, data);
    } break;
    case 6: {
      deleteFirst(head);
    } break;
    case 7: {
      deleteLast(head);
    } break;
    case 8: {
      int pos;
      scanf("%d ", &pos);
      deleteAtPosition(head, pos);
    } break;
    default:
      printf("Enter Valid input");
      // case 6:
      //   deleteFirst(head);
      //   break;
      // case 7:
      //   deleteLast(head);
      //   break;
      // }
    }
    n--;
  }
  return 0;
}
