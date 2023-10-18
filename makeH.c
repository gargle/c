#include <stdio.h>

char *endstars = "#   #";
char *allstars = "#####";

void printC(char **sptr) {
  printf("%s\n", *sptr++);
  printf("%s\n", *sptr++);
  printf("%s\n", *sptr++);
  printf("%s\n", *sptr++);
  printf("%s\n", *sptr++);
  printf("%s\n", *sptr++);
  printf("%s\n", *sptr);
}

int main()
{
  char *(*alfabet[26])[7];

  char *letterA[7] = { allstars, endstars, endstars, allstars, endstars, endstars, endstars };
  char *letterH[7] = { endstars, endstars, endstars, allstars, endstars, endstars, endstars };

  alfabet[0] = &letterA;
  alfabet[7] = &letterH;

  printC(*alfabet[7]);
  puts("");
  printC(*alfabet[0]);
  
  return 0;
}
