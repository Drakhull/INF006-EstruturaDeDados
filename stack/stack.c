#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(stack *s)
{
    s->top = NULL;
    s->stackSize = 0;
}

void push(stack *s)
{
    node *newNode = malloc(sizeof(node));
    if (!newNode)
    {
        printf("Memory Allocation error.");
        exit(EXIT_FAILURE);
    }
    else
    {
        // insertBook(&newNode->book);
        newNode->down = s->top;
        s->top = newNode;
        s->stackSize++;
    }
}

void pop(stack *s)
{
    if (s->top)
    {
        node *remove = s->top;
        s->top = remove->down;
        free(remove);
        s->stackSize--;
    }
    else
    {
        printf("\nCannot pop from an empty Stack.\n");
    }
}

void printStack(stack *s)
{
    if (s->top == NULL)
    {
        printf("\n-------------------");
        printf("The Stack is empty.");
        printf("-------------------\n");
        return;
    }

    printf("-------STACK (Size: %d)-------\n", s->stackSize);
    node *current = s->top;
    int i = 1;

    while (current)
    {
        printf("-       (%d•)       -\n", i);
        // printBook(current->???);

        current = current->down;
        i++;
        if (current)
            printf("----------------------\n");
    }

    printf("-------------END-------------\n");
}