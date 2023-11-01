#ifndef BOOKSTACK_H_INCLUDED
#define BOOKSTACK_H_INCLUDED

#define bookNameS 50
#define bookGenreS 50

typedef struct books
{
    char name[bookNameS];
    char genre[bookGenreS];
} books;

typedef struct node
{
    books book;
    struct node *down;
} node;

typedef struct stack
{
    node *top;
    int stackSize;
} stack;


void printBook(books book);

void insertBook(books *newBook);

void initStack(stack *s);

void push(stack *s);

void pop(stack *s);

void printStack(stack *s);

#endif // BOOKSTACK_H_INCLUDED