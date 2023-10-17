#include <stdio.h>
#include <stdlib.h>

#define MAX_node_SIZE 100

typedef struct person {
  char name[MAX_node_SIZE];
  int age;

} person;

typedef struct Node {  
  person p;
  struct Node *next;
} node; 

int main(void) {
  
  printNode(top);
}