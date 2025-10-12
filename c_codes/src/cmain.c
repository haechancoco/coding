#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 3000007

int main() {
  int num[8001] = {0};
  int t, flag, i, n = 0, avg = 0, mid = 0, mode = 0, range = 0, count = 0;
  char *buf = (char *)calloc(N, sizeof(char));
  char *c = buf;

  ssize_t l = read(0, buf, N);

  while (*c != '\n') {
    n *= 10;
    n += (*c - '0');
    ++c;
  }
  ++c;

  while (c < buf + l - 1) {
    flag = 1;
    t = 0;

    if (*c == '-') {
      flag = -1;
      ++c;
    }

    while (*c != '\n') {
      t *= 10;
      t += (*c - '0');
      ++c;
    }
    ++c;

    t *= flag;

    avg += t;
    ++num[t + 4000];
  }
  free(buf);

  // mid 구하기
  t = 0;
  for (i = 0; i < 8001; ++i) {
    t += num[i];
    if (t > n / 2) {
      mid = i - 4000;
      break;
    }
  }

  // mode 구하기
  for (i = 0; i < 8001; ++i) {
    if (count < num[i]) {
      count = num[i];
      mode = i - 4000;
      flag = 0;
    } else if (count == num[i] && count && !flag) {
      mode = i - 4000;
      flag = 1;
    }
  }

  // range 구하기
  for (i = 8000; i >= 0; --i)
    if (num[i])
      break;

  range = i - 4000;

  for (i = 0; i < 8001; ++i)
    if (num[i])
      break;

  range -= i - 4000;

  printf("%lld\n%d\n%d\n%d", llround((double)avg / n), mid, mode, range);
}