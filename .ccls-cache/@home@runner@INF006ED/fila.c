/*Aritmética modular*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define maxSize 100

typedef struct{
  float * Q;
  int head;
  int tail;
}Queue;

void init(Queue * q){
  q->head = q->tail = 0;
  q->Q = malloc(maxSize * sizeof (float));
}

void enqueue(Queue *q, float x)
{
  q->Q[q->tail] = x;
  if (q->tail == maxSize - 1) q->tail = 0;
  else q->tail = q->tail + 1;
}

void printQueue(Queue * q)
{
  int i = q->head;
  int j = q->tail;
  printf("[");
  while (i != j)
  {
    if (i == j-1) printf("%.2f", q->Q[i]);
    else printf("%.2f, ", q->Q[i]);
    i = (i + 1) % maxSize;
  }
  printf("]\n");
}

// int dequeue(int queue[])
// {
//     x = queue[q_head]
// }

int main(void) 
{
  /*Enqueue*/  
  
  Queue * f = malloc(sizeof(Queue));
  init (f);
  
  enqueue(f, 3.4);
  enqueue(f, 8.2);
  enqueue(f, 9.5);

  printQueue(f);
  
  return EXIT_SUCCESS;
}