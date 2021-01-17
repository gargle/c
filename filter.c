#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

size_t lencalc(int *array, size_t len, bool (*func)(int)) {
  int res = 0;
  for (int i = 0; i < len; i++) {
    int temp = func(array[i]);
    if (temp == 1)
      res++;
  }
  return res;
}

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int)) {
  size_t newlen = lencalc(array,len,func);
  *out_array = malloc(sizeof(int)*newlen);
  int cur = 0;
  for (int i = 0; i < len; i++) {
    int temp = func(array[i]);
    if (temp == 1) {
      (*out_array)[cur] = array[i];
      cur++;
    }
  }
  return newlen;
}

bool iseven(int a) {
  return (a%2 == 0);
}

#include <stdio.h>

int main(void) {
    int in[] = {1, 2, 3, 4, 5, 6};
    int *out;
    size_t res = filter(in, 6, &out, iseven); 
    for (int i = 0; i < res; i++)
    {
        printf("%d\n", out[i]);
    }
}
