#include <stdlib.h>
#include <stdio.h>

/* as a reminder, pointers can be tricky */

/* &var points to var   */
/* ptr   points to *ptr */

int table[10];

int main(void) {
  char naam[30] = "Johan"; /* naam is a pointer to char, naam is the memory address of the byte naam[0] */

  char *ptrc;         /* pointer to char */
  char *(aptr[30]);   /* array of 30 pointers to char */
  char (*ptra)[30];   /* pointer to array of 30 characters */
  char **ppc;         /* pointer to pointer to char */

  /* https://stackoverflow.com/questions/2094666/pointers-in-c-when-to-use-the-ampersand-and-the-asterisk */

  /* when an array expression appears in most contexts, the type of the expression is implicitly converted from
  "N-element array of T" to "pointer to T", and its value is set to point to the first element in the array. The
  exceptions to this rule are when the array expression appears as an operand of either the & or sizeof operators,
  or when it is a string literal being used as an initializer in a declaration. */

  /* When an array expression appears as an operand to the & operator, the type of the resulting expression is
  "pointer to N-element array of T", or T (*)[N], which is different from an array of pointers (T *[N]) and a
  pointer to the base type (T *). */
  
  ptrc = naam;       /* naam implictly converted to pointer to char */
  ptra = &naam;      /* &naam is a pointer to an array of 30 characters, char (*ptra)[30]! */
  aptr[0] = naam;    /* naam is a pointer to char */
  ppc = &aptr[0];    /* this is the same as ppc = &ptrc */

  printf("naam    : %s\n", naam);
  printf("ptrc    : %s\n", ptrc);
  printf("aptr[0] : %s\n", aptr[0]);
  printf("ptra    : %s\n", ptra);
  printf("ptra    : %s\n", *ptra); printf("ppc : %s\n", *ppc);

  /* and now for something complicated */

  table[4] = 321;

  printf("table element 4 is %d\n", table[4]);

  int (*ptr)[10];
  ptr = &table;

  printf("table element 4 by means of pointer is %d\n", (*ptr)[4]);
  printf("table address is %ld\n", naam);
  printf("table address is %ld\n", &naam);
}
