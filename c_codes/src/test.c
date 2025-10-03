#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct t {
  int *arr;
  int i;
};

int test(struct t *t) {
  return t->arr[(t->i)++];
}


int main(void) {
  struct t t;
  t.arr = malloc(10 * sizeof(int));
  t.i = 0;
  printf("%d\n", test(&t));

  return 0;
}