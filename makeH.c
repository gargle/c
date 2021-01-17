#include <stdio.h>

char *endstars = "#   #";
char *allstars = "#####";

void makeA(char* sptr[]) {
  *sptr++ = allstars;
  *sptr++ = endstars;
  *sptr++ = endstars;
  *sptr++ = allstars;
  *sptr++ = endstars;
  *sptr++ = endstars;
  *sptr = endstars;
}

void printC(char* sptr[]){ 
  for (int i = 0; i<7; i++) {
    printf("%u   %u   %s\n", &sptr[i], sptr[i], sptr[i]);
  }
  puts(" ");
}

int main()
{
  char *alfabet[26][7];

  makeA(alfabet[0]);
  printC(alfabet[0]);

  return 0;
}
