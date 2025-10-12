/* 문제
  산술평균, 중앙값, 최빈값, 범위(최댓값과 최솟값의 차이)
  1. 산술평균
    배열을 1번 순회하면서 더한다음 배열 크기고 나눈다.
  2. 중앙값
    배열을 계수정렬로 정렬한 다음 배열의 크기 / 2 + 1 번째 요소를 추출한다.
  3. 최빈값
    배열을 계수정렬한 후 가장 큰 요소를 추출한다.
  4. 범위
    배열을 계수정렬한 후
      0번째 요소부터 확인해 최솟값을 찾는다.
      8,000번째 요소부터 확인해 최댓값을 찾는다.
    최댓값과 최솟값을 뺀다.
*/
/* 입력
  입력으로 n (1 <= n <= 500,000) 개의 숫자가 주어진다. 
  단 n 은 홀수이다.
  입력되는 수자의 절댓값은 4,000을 넘지 않는다.

  계수정렬시 가능한 최대값은 500,000 * 4,000 = 2,000,000,000 < int32_max
*/
 

#include <stdio.h>

#define MAX 8001
#define SHIFT 4000

int mean(const int *arr, int n);
int median(const int *arr, int n);
int mod(const int *arr);
int range(const int *arr);

int main(void) {
  

  return 0;
}

int mean(const int *arr, int n) {
  long long sum = 0;
  for (int i = 0; i < MAX; ++i) {
    sum += (i - SHIFT) * arr[i];
  }
  int tenths = sum * 10 / n % 10;
  int res = sum / n;
  if (0 <= tenths && 5 <= tenths) res++;
  else if (tenths < 0 && tenths <= -5) res--;
  return res;
}

int median(const int *arr, int n) {
  int mid_cnt = n / 2 + 1;
  int cnt = 0;
  int mid = 0;
  while (cnt < mid_cnt) {
    cnt += arr[mid++];
  }
  mid--;
  return mid - SHIFT;
}

int mod(const int *arr) {
  int mod1 = -1;
  int mod2 = -1;
  int maxcnt = 0;
  for (int i = MAX - 1; i > 0; --i) {
    if (maxcnt < arr[i]) {
      maxcnt = arr[i];
      mod2 = -1;
      mod1 = i;
    }
    else if (maxcnt <= arr[i]) {
      mod2 = mod1;
      mod1 = i;
    }
  }

  return mod2 == -1 ? mod1 - SHIFT : mod2 - SHIFT;
}

int range(const int *arr) {
  int min, max;
  for (int i = 0; i < MAX; ++i) {
    if (arr[i] > 0) {
      min = i - SHIFT;
      break;
    }
  }
  for (int i = MAX - 1; i > 0; --i) {
    if (arr[i] > 0) {
      max = i - SHIFT;
      break;
    }
  }
  return max - min;
}