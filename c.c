#include <stdio.h>

void main() {
  int getal = 0;                                                  /* a 0xffffcc3c v 0 */
  int *ptr_getal;                                                 /* a 0xffffcc30 v ? */

  ptr_getal = &getal;                                             /* a 0xffffcc30 v 0xffffcc3c */
  printf("getal = %d\n", getal);
  *ptr_getal = 1;
  
  int **ptr_ptr_getal;                                           /* a 0xffffcc28 v ? */
  ptr_ptr_getal = &ptr_getal;                                    /* a 0xffffcc28 v 0xffffcc30 */
  **ptr_ptr_getal = 1;
  printf("getal = %d\n", getal);

  int ***ptr_ptr_ptr_getal;                                      /* @ 0xffffcc20 v ? */
  ptr_ptr_ptr_getal = &ptr_ptr_getal;                            /* @ 0xffffcc20 v 0xffffcc28 */

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
