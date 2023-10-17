#include <stdio.h>

int main(void) {
  int *p;
  int array[] = {0,1,2,3,4,5,6,7,8,9};

  p = array;
  
  
  printf("endereço guardado em p: %p\n", p);
  printf("endereço de em array: %p\n\n", &array);
  for(int i = 0; i < 10; i++){
    printf("valores guardados em array: %d\n", p[i]);
  }
  p++;
  printf("endereço guardado em p: %p\n", p);
  printf("endereço de em array: %p\n\n", &array);
  for(int i = 0; i < 10; i++){
    printf("valores guardados em array: %d\n", p[i]);
  }
  return 0;
}