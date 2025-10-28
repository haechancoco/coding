#include <stdio.h>

#include "debug.h"

void print1darr(const int *A, size_t A_size, char *message) {
    if (message != NULL) printf("%s\n", message);
    for (int i = 0; i < A_size; i++) {
        printf("[%d]: %d\n", i, A[i]);
    } printf("\n");
}
