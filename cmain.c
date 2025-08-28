#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
// #include <inttypes.h>
// #include <stdlib.h>

/*
    l 자리수 N
    생성자: g
    생성자의 각 자리수 합: e
    1 <= N <= 1,000,000
    g + e == N
    l <= e <= 9l

*/

int find_digit(int n) {
    int digit = 0;
    while (n) {
        digit++;
        n /= 10;
    }
    return digit;
}

int find_generator(int n) {

}

int main(void) {
    int n;
    scanf("%d", &n);
    int ln = find_digit(n);

    // int strat_l = find_digit(n - 9 * ln) < ln ? ln - 1 : ln;

    int g = INT_MAX;
    for (int e_expec = ln; e_expec <= 9 * ln; e_expec++) {
        // 가능한 e를 가지는 후보 생성자.
        int assume_g = n - e_expec;
        // 후보 생성자 e구하기.
        int assume_eg = 0;
        for (int j = assume_g; j > 0; j /= 10) assume_eg += j % 10;
        // eg와 e_expec가 같으면 g는 생성자.
        if (assume_eg == e_expec && g > assume_g) {
            g = assume_g;
        }
    }
    // 2자리 이상이면 ln - 1 자리 수도 탐색.
    if (ln < 2) {
        g == INT_MAX ? printf("0\n") : printf("%d\n", g);
        return 0;
    }
    ln--;
    for (int e_expec = ln; e_expec <= 9 * ln; e_expec++) {
        // 가능한 e를 가지는 후보 생성자.
        int assume_g = n - e_expec;
        // 후보 생성자 e구하기.
        int assume_eg = 0;
        for (int j = assume_g; j > 0; j /= 10) assume_eg += j % 10;
        // eg와 e_expec가 같으면 g는 생성자.
        if (assume_eg == e_expec && g > assume_g) {
            g = assume_g;
        }
    }
    g == INT_MAX ? printf("0\n") : printf("%d\n", g);
    return 0;
}