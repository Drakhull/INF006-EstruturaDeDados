#include "bookStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initStack(stack *s) {
  s->top = NULL;
  s->stackSize = 0;
}

void push(stack *s) {
  node *newNode = malloc(sizeof(node));
  if (!newNode) {
    printf("Memory Allocation error.");
    exit(EXIT_FAILURE);
  } else {
    insertBook(&newNode->book);
    newNode->down = s->top;
    s->top = newNode;
    s->stackSize++;
  }
}

void pop(stack *s) {
  if (s->top) {
    node *remove = s->top;
    s->top = remove->down;
    free(remove);
    s->stackSize--;
  } else {
    printf("\nThe Stack is empty.\n");
  }
}

void printStack(stack *s) {
  if (s->top == NULL) {
    printf("The Stack is empty.\n");
    return;
  }

  printf("-------STACK (Size: %d)-------\n", s->stackSize);
  node *current = s->top;
  int i = 1;

  while (current) {
    printf("-       (%d•)       -\n", i);
    printBook(current->book);

    current = current->down;
    i++;
    if (current)
      printf("----------------------\n");
  }

  printf("-------------END-------------\n");
}

void insertBook(books *newBook) {
  printf("Type the book's name: ");
  fgets(newBook->name, 20, stdin);

  printf("Type the book's genre: ");
  fgets(newBook->genre, 20, stdin);

  newBook->name[strcspn(newBook->name, "\n")] = 0;
  newBook->genre[strcspn(newBook->genre, "\n")] = 0;
}

void printBook(books book) {
  printf("Book's Name: %s\n", book.name);
  printf("Book's Genre: %s\n", book.genre);
}