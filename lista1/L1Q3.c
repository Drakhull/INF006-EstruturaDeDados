#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_MAX_SIZE 500

#define FAILURE 0
#define SUCCESS 1

typedef struct CircularNode {
  float key;
  struct CircularNode *next;
} CircularNode;

typedef struct DoubleLinkedListNode {
  int key;
  CircularNode *headCircular;
  struct DoubleLinkedListNode *next;
  struct DoubleLinkedListNode *previous;
} DoubleLinkedListNode;

typedef struct ListContainer {
  DoubleLinkedListNode *head;
  int size;
} ListContainer;

int readf(char path[], FILE **file);
void initNodes(ListContainer *doubleList);

int main(void) {
  FILE *input_file = NULL;
  FILE *output_file = fopen("L1Q3.out", "w");

  if (!readf("L1Q3.in", &input_file) || !output_file) {
    printf("Closing...\n");
    return EXIT_FAILURE;
  }

  sortf_out(input_file, output_file);

  fclose(input_file);
  fclose(output_file);
  return EXIT_SUCCESS;
}

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

void initNodes(ListContainer *doubleList) {
  for (int i = 0; i < alocSize; i++) {
    numbers[i].numCounter = 0;
    numbers[i].sum = 0;
    int j = 0;
    while (j < 25) {
      numbers[i].num[j] = 0;
      j++;
    }
  }
}

// **Quicksort start**

int partition(int *array, int begin, int final) {
  int left, right, pivot, aux;
  left = begin;
  right = final;
  pivot = array[begin];
  while (left < right) {
    while (left <= final && array[left] <= pivot)
      left++;

    while (right >= 0 && array[right] > pivot)
      right--;

    if (left < right) {
      aux = array[left];
      array[left] = array[right];
      array[right] = aux;
    }
  }
  array[begin] = array[right];
  array[right] = pivot;
  return right;
}

void quickSort(int *array, int begin, int end) {
  int pivot;
  if (end > begin) {
    pivot = partition(array, begin, end);
    quickSort(array, begin, pivot - 1);
    quickSort(array, pivot + 1, end);
  }
}

int partition4Start(start *array, int begin, int final) {
  int left, right;
  start aux, pivot;
  left = begin;
  right = final;
  pivot = array[begin];
  while (left < right) {
    while (left <= final && array[left].sum <= pivot.sum)
      left++;

    while (right >= 0 && array[right].sum > pivot.sum)
      right--;

    if (left < right) {
      aux = array[left];
      array[left] = array[right];
      array[right] = aux;
    }
  }
  array[begin] = array[right];
  array[right] = pivot;
  return right;
}

void quickSort4Start(start *array, int begin, int end) {
  int pivot;
  if (end > begin) {
    pivot = partition4Start(array, begin, end);
    quickSort4Start(array, begin, pivot - 1);
    quickSort4Start(array, pivot + 1, end);
  }
}

// **Quicksort end**

int totalSum(int *numbers, int numCounter) {
  int sum = 0;
  for (int i = 0; i < numCounter; i++) {
    sum += numbers[i];
  }
  return sum;
}

void save_in_outf(FILE *output_file, start *numbers, int startCounter) {
  quickSort4Start(numbers, 0, startCounter - 1);

  for (int i = 0; i < startCounter; i++) {
    fprintf(output_file, "start ");
    for (int j = 0; j < numbers[i].numCounter; j++) {
      fprintf(output_file, "%d", numbers[i].num[j]);
      if (j < numbers[i].numCounter)
        fprintf(output_file, " ");
    }
  }
  fprintf(output_file, "\n");
}

void sortf_out(FILE *input_file, FILE *output_file) {
  char *line = malloc(LINE_MAX_SIZE * sizeof(char));
  const char *separator = " \n";
  char *slice;
  int startCounter = 0;
  int alocSize = 10;
  start *numbers = malloc(alocSize * sizeof(start));
  if (!numbers) {
    printf("Memory allocation error for start numbers.\n");
    return;
  }
  initStructStart(numbers, alocSize);

  while (fgets(line, LINE_MAX_SIZE, input_file) != NULL) {
    slice = strtok(line, separator);

    int index = 0;

    while (slice) {
      if (strcmp(slice, "start") == 0) {
        slice = strtok(NULL, separator);
        if (startCounter > 0) {
          quickSort(numbers[startCounter - 1].num, 0,
                    numbers[startCounter - 1].numCounter - 1);
          numbers[startCounter - 1].sum =
              totalSum(numbers[startCounter - 1].num, index);
        }

        startCounter++;
        if (((startCounter >= 10) && (startCounter % 10) == 0)) {
          int initSize = alocSize;
          alocSize += 10;
          if ((numbers = realloc(numbers, alocSize * sizeof(start))) == NULL) {
            printf("Memory allocation error for start numbers.\n");
            return;
          }
          initStructStart2(numbers, initSize);
        }
        // if (((startCounter >= 5) && ((startCounter % 10) == 5)) ||
        // ((startCounter >= 10) && (startCounter % 10) == 0))
        // {
        //     int newAlocSize = alocSize + 10;
        //     start *newNumbers = realloc(numbers, newAlocSize *
        //     sizeof(start)); if (newNumbers == NULL)
        //     {
        //         printf("Memory allocation error for start numbers.\n");
        //         return;
        //     }
        //     numbers = newNumbers;
        //     alocSize = newAlocSize;
        // }

        index = 0;
        continue;
      }

      numbers[startCounter - 1].num[index] = atoi(slice);
      numbers[startCounter - 1].numCounter++;
      index++;
      slice = strtok(NULL, separator);
    }
    if (startCounter > 0) {
      quickSort(numbers[startCounter - 1].num, 0,
                numbers[startCounter - 1].numCounter - 1);
      numbers[startCounter - 1].sum =
          totalSum(numbers[startCounter - 1].num, index);
    }

    save_in_outf(output_file, numbers, startCounter);
    startCounter = 0;
    initStructStart(numbers, alocSize);
  }

  free(numbers);
  free(line);
}