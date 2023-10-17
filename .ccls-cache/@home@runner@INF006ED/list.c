#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  int key;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct List{
  Node *head;
}List;

void init_list(List *list){
  list->head = NULL;
  return;
}

Node * list_search(List *L, int k){
  Node *x = L->head;
  while(x != NULL && x->key != k){
    x = x->next;
  }
  return x;
}

void list_insert(List *L, Node * x){
  x->next = L->head;
  if(L->head != NULL){
    L->head->prev = x;
  }
  L->head = x;
  x->prev = NULL;
  return;
}

void print_list(List *L){
  Node *x = L->head;
  while(x != NULL){
    printf("%d", x->key);
    printf("<->");
    x = x->next;
  }
  printf("Null");
}
int main(void){
  List *estoque = (List*)malloc(sizeof(List));
  init_list(estoque);
  for(int i =0; i < 10; i++){
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = i;
    list_insert(estoque, n);
  }
  print_list(estoque);
  printf("\n\nFim");
  
  return EXIT_SUCCESS;
  
}