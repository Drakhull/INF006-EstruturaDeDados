#include <stdio.h>

int main(void) {
  int array[10] = {0,1,2,3,4,5,6,7,8,9};

  printf("array value: %d", *(array + (2 * 3)));

}