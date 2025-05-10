#include <stdio.h>
#include <stdlib.h>

#define H 177645
#define C 177640
#define ADD 193450094
#define REMOVE 6952682928051
#define CHANGE 6952099022091
#define SIZE 6384506208
#define EXIT 6384018879
#define SHOW 6384504774

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
void check_LL_Status();

Node *head = NULL;
int size = 0;
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
  // head = insert_at_tail(head, 7);
  //  head = insert_at_tail(head, 1);
  //  head = insert_at_tail(head, 2);
  //  Node a, b, c;
  //  a.value = 5;
  //  b.value = 6;
  //  c.value = 7;
  //
  //  a.next = &b;
  //  b.next = &c;
  //  c.next = NULL;

  print_list(head);
}

void check_LL_Status() {
  if (head == NULL) {
    printf("Linked List has not been initiated");
  } else {
    printf("Linked List has been initiated");
  }
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

  printf("Printing List\n");
  int i = 0;
  while (current != NULL) {
    printf("Node %d: %d\n", i, current->value);
    i++;
    current = current->next;
  }

  printf("Printing DONE\n");
}

void initiate_prompt() {

  printf("Welcome to Linked List in C demonstration. type \"H\" for help\n");
  while (1) {
    printf("Enter Your command> ");
    scanf("%2047s", input);
    // SWITCH STATEMENT
    switch (strHash(input)) {
    case H:
      printf("\nAvailable Commands:\n");
      printf("1. 'ADD' - Add a number to the end of the list\n");
      printf("2. 'SHOW' - Display all numbers in the list\n");
      printf("3. 'EXIT' - Exit the program\n");
      printf("\nNote that all commands are in caps\n");
      break;
    case C:
      check_LL_Status();
      break;
    case ADD: {
      int addVal = 0;
      size++;
      printf("Enter Number:");
      scanf("%d", &addVal);
      // head = calloc(1, sizeof(Node));
      // printf("%p\n", head);
      head = insert_at_tail(head, addVal);
      printf(" Node Added\n");

      break;
    }
    case REMOVE:
      printf("REMOVE functionality not yet implemented\n");
      break;
    case CHANGE:
      printf("CHANGE functionality not yet implemented\n");
      break;
    case SIZE:
      printf("Size: %d\n", size);
      //      printf("SIZE functionality not yet implemented\n");
      break;
    case SHOW:
      print_list(head);
      break;
    case EXIT:
      printf("Goodbye\n");
      exit(0);
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

  //  printf("str is : %s", str);
  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;
  //  printf("str is : %ld\n", hash); <- USED for getting the hash value, which
  //  I can assign to a new command
  return hash;
}
