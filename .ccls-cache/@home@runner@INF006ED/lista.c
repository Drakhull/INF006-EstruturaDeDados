#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
  int key;
  struct Node *prev;
  struct Node *next;
} Node;

type