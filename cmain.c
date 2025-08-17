#include <stdio.h>
// #include <inttypes.h>

int main(void) {
    int y;
    scanf("%d", &y);
    
    int yoon = 0;
    if (y % 400 == 0) yoon = 1;
    else if (y % 4 == 0 && y % 100 != 0) yoon = 1;
    printf("%d", yoon);
    
    return 0;
}