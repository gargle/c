#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ps(char *s) {
  char *t;
  t=strdup(s);
  puts(t);
  return t;
}

char (*lptr[26])[7][5];

char *allstars = "*****";
char *endstars = "*   *";
char *midstars = "  *  ";

void makeH(char *sptr[7]) {
  puts(endstars);
  sptr++=sptr++=sptr++=endstars;
  sptr++=allstars;
  sptr++=sptr++=sptr=endstars;
}

void main() {
  char *s;
  s=ps("hello");
  puts(s);
  free(s);
  makeH(lptr[7]);
}

