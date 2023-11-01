#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct node
{
    // *INSERT DATA HERE*
    struct node *down;
} node;

typedef struct stack
{
    node *top;
    int stackSize;
} stack;

void initStack(stack *s);

void push(stack *s);

void pop(stack *s);

void printStack(stack *s);

#endif // STACK_H_INCLUDED