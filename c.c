#include <stdio.h>

void main() {
  int getal = 0;
  int *ptr_getal;

  ptr_getal = &getal;
  printf("getal = %d\n", getal);
  *ptr_getal = 1;
  
  int **ptr_ptr_getal;
  ptr_ptr_getal = &ptr_getal;
  **ptr_ptr_getal = 1;
  printf("getal = %d\n", getal);

  int ***ptr_ptr_ptr_getal;
  ptr_ptr_ptr_getal = &ptr_ptr_getal;

  ***ptr_ptr_ptr_getal = 2;
  printf("getal = %d\n", getal);
}

