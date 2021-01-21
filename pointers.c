#include <stdlib.h>
#include <stdio.h>

/* as a reminder, pointers can be tricky */

int main(void) {
  char naam[30] = "Johan";

  char *ptrc;         /* pointer to char */
  char *(aptr[30]);   /* array of 30 pointers to char */
  char (*ptra)[30];   /* pointer to array of 30 characters */
  char **ppc;         /* pointer to pointer to char */

  ptrc = naam;        /* &naam is a pointer to an array of 30 characters! */
  ptra = &naam;       /* see the comment just above this line */
  aptr[0] = naam;     /* naam is a pointer to char */
  ppc = &aptr[0];     /* this is the same as ppc = &ptrc; */

  printf("naam    : %s\n", naam);
  printf("ptrc    : %s\n", ptrc);
  printf("aptr[0] : %s\n", aptr[0]);
  printf("ptra    : %s\n", *ptra);
  printf("ppc     : %s\n", *ppc);
}
