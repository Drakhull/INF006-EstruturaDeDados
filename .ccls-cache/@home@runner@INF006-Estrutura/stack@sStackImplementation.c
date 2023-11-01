#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookStack.h"


void menu()
{
    printf("0- Exit\n");
    printf("1- 'Push' Book\n");
    printf("2- 'Pop' Book\n");
    printf("3- 'Print' Books\n");
}

int main(void)
{
    stack *STACK = malloc(sizeof(stack));

    if (!STACK)
    {
        printf("Memory Allocation error.");
        return EXIT_FAILURE;
    }

    initStack(STACK);
    int choice;
    do
    {
        menu();
        printf("Select your option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 0:
            return EXIT_SUCCESS;
            break;

        case 1:
            push(STACK);
            break;

        case 2:
            pop(STACK);
            break;

        case 3:
            printStack(STACK);
            break;

        default:
            break;
        }
    } while (choice);

    while (STACK->top)
    {
        node *temp = STACK->top;
        STACK->top = STACK->top->down;
        free(temp);
    }

    return EXIT_SUCCESS;
}