#include <stdio.h>
#include <string.h>

int hash(char *oper) {
    int sum = 0;
    for (int i = 0; oper[i] != '\0'; i++) {
        sum += oper[i];
    }
    return sum;
}

int main(void) {
    printf("%d", -1 % 3);

    return 0;
}