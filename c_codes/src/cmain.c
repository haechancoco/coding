#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
  
  int m ,n;
  scanf("%d %d", &m, &n);

  // 배열 할당
  int nAp_size = n + 1;
  int *nAp = calloc(nAp_size, sizeof(int));

  // print1darr(nap, nap_size);

  // 에라토스테네스의 체
  nAp[0] = nAp[1] = true;

  for (int i = 2; i * i <= n; i++) {
    if (nAp[i] == true) continue;
    for (int j = i * i; j<= n; j += i) {
        nAp[j] = true;
      }
    }
  
  // 출력
  for (int i = m; i <= n; i++) {
    if (nAp[i] == false) {
      printf("%d\n", i);
    }
  }

  return 0;
}