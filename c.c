#include <stdio.h>

int main() {
<<<<<<< HEAD
  int getal = 0;                                                  /* a 0xffffcc3c v 0 */
  int *ptr_getal;                                                 /* a 0xffffcc30 v ? */
=======
  int getal = 0;                        /* a 0xffffcc3c v 0 */
  int *ptr_getal;                       /* a 0xffffcc30 v ? */
>>>>>>> e6dbb8f5df834e19159ccf339274eefd3195ebdd

  int a,b,c;                            /* let's see how gdb handles this */
  a=1; b=2; c=3;
  printf("getallen = %d,%d,%d\n", a, b, c);

  ptr_getal = &getal;                   /* a 0xffffcc30 v 0xffffcc3c */
  printf("getal = %d\n", getal);
  *ptr_getal = 1;
  
  int **ptr_ptr_getal;                  /* a 0xffffcc28 v ? */
  ptr_ptr_getal = &ptr_getal;           /* 0xffffcc28 v 0xffffcc30 */
  **ptr_ptr_getal = 1;
  printf("getal = %d\n", getal);

  int ***ptr_ptr_ptr_getal;             /* @ 0xffffcc20 v ? */
  ptr_ptr_ptr_getal = &ptr_ptr_getal;   /* @ 0xffffcc20 v 0xffffcc28 */

  ***ptr_ptr_ptr_getal = 2;
  printf("getal = %d\n", getal);

  printf("address getal             = %p\n", &getal);
  printf("rvalue *ptr_getal         = %p\n", ptr_getal);
  printf("lvalue *ptr_getal         = %p\n", &ptr_getal);         
  printf("rvalue *ptr_ptr_getal     = %p\n", ptr_ptr_getal);
  printf("lvalue *ptr_ptr_getal     = %p\n", &ptr_ptr_getal);     
  printf("rvalue *ptr_ptr_ptr_getal = %p\n", ptr_ptr_ptr_getal);
  printf("lvalue *ptr_ptr_ptr_getal = %p\n", &ptr_ptr_ptr_getal);
  printf("rvalue ptr_ptr_ptr_getal  = %p\n", *ptr_ptr_ptr_getal);
  printf("rvalue ptr_ptr_getal      = %p\n", *ptr_ptr_getal);
  printf("rvalue ptr_getal          = %i\n", *ptr_getal);
}
