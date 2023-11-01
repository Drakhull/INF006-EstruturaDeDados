#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *array = {0, 1, 2 ,3,4,5,6,7,8,9};
  int *arrayA = {10,11,12,13,14};

  for(int i = 0; i < 10; i++){
    printf("%d ", array[i]);
  }
  for(int i = 0; i < 10; i++){
    printf("%d ", arrayA[i]);
  }

  printf("Array %d", array[1] * arrayA[2]);
  
}