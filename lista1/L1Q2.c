#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30
#define LINE_MAX_SIZE 500

#define FAILURE 0
#define SUCCESS 1

#define BEFORE -1
#define EQUAL 0
#define AFTER 1

typedef struct node {
  char name[NAME_LEN];
  struct node *down;
} node;

typedef struct stack {
  node *top;
  int stackSize;
} stack;

// *START* STACK HEADERS

void initStack(stack *s);

void push(stack *s, char *pushName);

void pop(stack *s);

void printStack(stack *s);

// STACK HEADERS *END*

// *START* FILES HEADERS

int readf(char path[], FILE **file);

void stack2file(FILE *input_file, FILE *output_file);

// FILES HEADERS *END*

int main(void) {
  FILE *input_file = NULL;
  FILE *output_file = fopen("L1Q2.out", "w");

  if (!readf("L1Q2.in", &input_file) || !output_file) {
    printf("\nClosing...\n");
    return EXIT_FAILURE;
  }

  stack2file(input_file, output_file);

  fclose(input_file);
  fclose(output_file);

  return EXIT_SUCCESS;
}

// *START* STACK

void initStack(stack *s) {
  s->top = NULL;
  s->stackSize = 0;
}

void push(stack *s, char *pushName) {
  node *newName = malloc(sizeof(node));
  if (!newName) {
    printf("Memory Allocation error.");
    exit(EXIT_FAILURE);
  } else {
    strcpy(newName->name, pushName);
    newName->down = s->top;
    s->top = newName;
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
    printf("\nCannot pop from an empty Stack.\n");
  }
}

void printStack(stack *s) {
  if (s->top == NULL) {
    printf("\n-------------------");
    printf("The Stack is empty.");
    printf("-------------------\n");
    return;
  }

  printf("-------STACK (Size: %d)-------\n", s->stackSize);
  node *current = s->top;
  int i = 1;

  while (current) {
    printf("-       (%d•)       -\n", i);
    printf("%s", current->name);

    current = current->down;
    i++;
    if (current)
      printf("----------------------\n");
  }

  printf("-------------END-------------\n");
}

// STACK *END*

// *START* FILES

int readf(char path[], FILE **file) {
  *file = fopen(path, "r");
  if (!*file) {
    printf("The program couldn't open the input file.\n");
    return FAILURE;
  } else {
    printf("File is now open.\n");
    return SUCCESS;
  }
}

void stack2file(FILE *input_file, FILE *output_file) {
  char *line = malloc(LINE_MAX_SIZE * sizeof(char)); // dar free
  const char *separator = " \n";
  char *slice;
  int popCounter = 0;

  stack *nameStack = malloc(sizeof(stack)); // dar free

  if (!nameStack) {
    printf("\nStack allocation error.\n");
    return;
  }

  initStack(nameStack);

  while (fgets(line, LINE_MAX_SIZE, input_file) != NULL) {
    slice = strtok(line, separator);
    char *previousName = NULL;
    char *currentName = NULL;
    stack *tempStack = malloc(sizeof(stack));
    if (!tempStack) {
      printf("\nStack allocation error.\n");
      return;
    }

    while (slice) {
      if (!nameStack->top) {
        previousName = slice;
        push(nameStack, slice);
        fprintf(output_file, "push-%s", previousName);
        slice = strtok(NULL, separator);

        currentName = slice;
        if (currentName)
          fprintf(output_file, " ");
        continue;
      }

      // strcmp ((x > b)?) ou seja (B vem depois de A?) se falso, -1, se
      // verdadeiro 1, se igual é 0
      if (slice) {
        while (strcmp(currentName, previousName) >= AFTER && slice) {
          push(nameStack, currentName);
          fprintf(output_file, "push-%s", currentName);
          slice = strtok(NULL, separator);

          previousName = currentName;
          currentName = slice;
          if (currentName)
            fprintf(output_file, " ");
          if (!currentName)
            break;
        }
      }

      if (slice) {
        while (strcmp(currentName, previousName) <= BEFORE) {
          push(tempStack, previousName);
          pop(nameStack);
          previousName = nameStack->top->name;
          popCounter++;

          if (previousName == NULL) {
            if (popCounter) {
              fprintf(output_file, "%dx-pop ", popCounter);
              popCounter = 0;
            }

            push(nameStack, currentName);
            fprintf(output_file, "push-%s", currentName);
            if (tempStack->top->name || currentName)
              fprintf(output_file, " ");
            previousName = currentName;

            while (tempStack->top) {
              push(nameStack, tempStack->top->name);
              fprintf(output_file, "push-%s", tempStack->top->name);
              pop(tempStack);
              if (tempStack->top->name || currentName)
                fprintf(output_file, " ");
            }

            slice = strtok(NULL, separator);
            previousName = nameStack->top->name;
            currentName = slice;
          }

          if (slice) {

            if ((strcmp(currentName, previousName) >= AFTER) && slice) {
              if (popCounter) {
                fprintf(output_file, "%dx-pop ", popCounter);
                popCounter = 0;
              }

              push(nameStack, currentName);
              fprintf(output_file, "push-%s", currentName);
              if (tempStack->top->name || currentName)
                fprintf(output_file, " ");

              while (tempStack->top) {
                push(nameStack, tempStack->top->name);
                fprintf(output_file, "push-%s", tempStack->top->name);
                pop(tempStack);
                if (tempStack->top->name || currentName)
                  fprintf(output_file, " ");
              }

              slice = strtok(NULL, separator);
              previousName = nameStack->top->name;
              currentName = slice;
            }
          }
          if (!currentName)
            break;
        }
      }

      if (slice) {

        if (strcmp(currentName, previousName) == EQUAL) {
          push(nameStack, previousName);
          fprintf(output_file, "push-%s", previousName);
          slice = strtok(NULL, separator);
          currentName = slice;
          if (currentName)
            fprintf(output_file, " ");
        }
      }
    }
    while (nameStack->top) {
      pop(nameStack);
    }
    // Removes the space in the end of all lines
    fseek(output_file, -1, SEEK_END);
    fputc('\n', output_file);

    // fprintf(output_file, "\n");
  }

  // Insert \0 in the end of the file, avoiding a final \n
  fseek(output_file, -1, SEEK_END);
  fputc('\0', output_file);
  while (nameStack->top) {
    node *temp = nameStack->top;
    nameStack->top = nameStack->top->down;
    free(temp);
  }
  free(line);
}

// FILES *END*