#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

// function definitions
void print_list(Node *head);
Node *insert_node_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int value);

int main() {

  Node *head = NULL;
  //  head = insert_node_at_head(head, 7);
  // head = insert_node_at_head(head, 5);
  // head = insert_node_at_head(head, 3);
  head = insert_at_tail(head, 7);
  head = insert_at_tail(head, 1);
  head = insert_at_tail(head, 2);
  //  Node a, b, c;
  // a.value = 5;
  // b.value = 6;
  // c.value = 7;
  //
  // a.next = &b;
  // b.next = &c;
  // c.next = NULL;

  print_list(head);
}

Node *insert_node_at_head(Node *head, int new_value) {
  Node *newNode = calloc(1, sizeof(Node));
  newNode->value = new_value;

  if (head == NULL)
    return newNode;
  newNode->next = head;
  return newNode;
}

Node *insert_at_tail(Node *head, int value) {
  // create Node
  Node *node = calloc(1, sizeof(Node));
  node->value = value;

  if (head == NULL) {
    return node;
  }
  // traverse to the end
  Node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = node;

  return head;
}

void print_list(Node *head) {
  Node *current;
  current = head;

  int i = 0;
  while (current != NULL) {
    printf("Node %d: %d\n", i, current->value);
    i++;
    current = current->next;
  }
}
