#include <stdio.h>
#include <stdlib.h>
#define H 5863588
// #include <editline/readline.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

// function definitions
void initiate_prompt();
void print_list(Node *head);
unsigned long strHash(const char *str);
Node *insert_node_at_head(Node *head, int new_value);
Node *insert_at_tail(Node *head, int value);

Node *head = NULL;
static char input[2048];
int a = 1;
int main() {

  /*
   * Starting the prompt
   */
  initiate_prompt();
  //  head = insert_node_at_head(head, 7);
  // head = insert_node_at_head(head, 5);
  // head = insert_node_at_head(head, 3);
  //  head = insert_at_tail(head, 7);
  // head = insert_at_tail(head, 1);
  // head = insert_at_tail(head, 2);
  //  Node a, b, c;
  // a.value = 5;
  // b.value = 6;
  // c.value = 7;
  //
  // a.next = &b;
  // b.next = &c;
  // c.next = NULL;

  //  print_list(head);
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

void initiate_prompt() {

  printf("Welcome to Linked List in C demonstration. type \"h\" or \"help\" "
         "for help\n");
  while (1) {
    printf("Enter Your command> ");
    scanf("%2047s", input);
    // SWITCH STATEMENT
    switch (strHash(input)) {
    case H:
      printf("Statement 1");
      break;

    default:
      printf("Not a valid entry\n");
      printf(" Type \"h\" for help\n");
      break;
    }
  }
}

unsigned long strHash(const char *str) {
  unsigned long hash = 5381;
  int c;

  printf("str is : %s", str);
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash;
}
