#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRIORITY_MAX 9

int sort[PRIORITY_MAX + 1] = {
  0, 2, 0, 3, 2, 1, 10, 0, 1, 2
};

int get_next_priority(int *sort, int current_p) {
  if (1 > current_p) return -1;
  for (int i = current_p - 1; i >= 0; i--) {
    if (sort[i] != 0) return i;
  }
  return -1;
}


int main(void) {
  printf("main start...\n");
  for (int i = 9; i >= 0; i--) {
    printf("%d, %d\n", i, get_next_priority(sort, i));
  }

  return 0;
}