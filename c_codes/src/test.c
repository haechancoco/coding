#include <stdio.h>
#include <inttypes.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

// A[lo..hi]의 연속된 부분 구간의 최대 합을 구한다.
int fastMaxSum(const int *A, int lo, int hi) {
  // 기저 사례: 구간의 길이가 1일 경우
  if (lo == hi) return A[lo];
  // 배열을 A[lo..mid], A[mid+1..hi]의 두 조각으로 나눈다.
  int mid = (lo + hi) / 2;
  // 두 부분에 모두 걸쳐 있는 최대 합을 구한다. 이 구간은
  // A[lo..mid]와 A[mid..hi] 형태를 갖는 구간의 합으로 이루어진다.
  // A[lo..mid]배열의 '접미사'형태를 갖는 최대 구간을 찾는다.
  int left = INT32_MIN, right = INT32_MIN, sum = 0;
  for (int i = mid; i >= lo; --i) {
    sum += A[i];
    left = MAX(left, sum);
  }
  // A[mid + 1..hi]배열의 '접두사' 형태를 갖는 최대 구간을 찾는다.
  sum = 0;
  for (int i = mid + 1; i <= hi; ++i) {
    sum += A[i];
    right = MAX(right, sum);
  }
  // 최대 구간이 두 조각 중 하나에만 속해 있는 (최대 부분 배열이 두 조각을 가로지르지 않는)경우의 답을 재귀 호출로 찾는다.
  int single = MAX(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));

  // 두 경우 중 최대치를 반환한다.
  return MAX(left + right, single);
}


int main(void) {
    int A[] = {101, -1000, 100, 100, 0, 101};
    int A_size = sizeof(A) / sizeof(A[0]);
    printf("%d\n", A_size);
    printf("%d\n", fastMaxSum(A, 0, A_size - 1));

    return 0;
}