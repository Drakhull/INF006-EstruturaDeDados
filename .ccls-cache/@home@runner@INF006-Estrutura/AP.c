#include <stdio.h>
#include <stdlib.h>

int main(void){
  int array[10] = {0, 1, 2 ,3,4,5,6,7,8,9};
  int arrayA[5] = {10,11,12,13,14};

  int *PA1 = array;
  int *PA2 = arrayA;

  for(int i = 0; i < 10; i++){
    printf("%d ", array[i]);
  }
  for(int i = 0; i < 5; i++){
    printf("%d ", arrayA[i]);
  }
  PA1 = (PA1 + 3);

  printf("Array %p", PA1);
  
}