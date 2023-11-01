#include <stdio.h>
#include <stdlib.h>

#define MAX_node_SIZE 100

typedef struct node {
  int numbers;
  struct node *down;
} node;

typedef struct stack {
  struct stack *top;
} stack;

node* push(node *n) {
  int val;

  node *newNode = (node *)malloc(sizeof(node));
  if(newNode){
    printf("Enter a number: ");
    scanf("%d", &val);

    newNode->numbers = val;
    newNode->down = n;
    return newNode;
  }
  else 
    printf("\nMemory allocation error.\n");
  return NULL;
}

node* pop(node *top){
  if(top){
    node *aux = top->down;
    free(top);
    return aux;
  }
  return NULL;
}

void printNode(node *top) {
  printf("---STACK---\n");
  while(top){
    printf("%d\n", top->numbers);
    top = top->down;
  }
  if(top == NULL) printf("NULL\n");
  printf("----END----\n");
}

int main(void) {
  node *top = NULL;
  int i = 0;
  while(i < 10){
    top = push(top);
    i++;
  }
  printNode(top);
  i = 0;
  while (i < 5){
    top = pop(top);
    i++;
  }
  printNode(top);
  printNode(top);

  return EXIT_SUCCESS;
}
