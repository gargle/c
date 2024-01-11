#include <stdio.h>

/*

  compile with gcc makeH.c -o makeH -O3 -Wall -std=gnu11 -g -O0

  start debugger with gdb makeH

(gdb) b 30
Breakpoint 1 at 0x12f9: file makeH.c, line 30.
(gdb) r
Starting program: /mnt/c/git/c/makeH
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
#   #
#   #
#   #
#####
#   #
#   #
#   #

#####
#   #
#   #
#####
#   #
#   #
#   #

Breakpoint 1, main () at makeH.c:30
30        return 0;
(gdb) print &letterH
$1 = (char *(*)[7]) 0x7fffffffdc50
(gdb) print letterH
$2 = {0x555555556004 "#   #", 0x555555556004 "#   #", 0x555555556004 "#   #", 0x55555555600a "#####",
  0x555555556004 "#   #", 0x555555556004 "#   #", 0x555555556004 "#   #"}
(gdb) print alfabet
$3 = {0x7fffffffdc90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x7fffffffdc50, 0x40000, 0x4, 0x40, 0xc, 0x600000, 0x40, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7ffff7fe6900 <dl_main>, 0x0, 0x7ffff7ffdab0 <_rtld_global+2736>}
(gdb) print alfabet[7]
$4 = (char *(*)[7]) 0x7fffffffdc50
 */

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
