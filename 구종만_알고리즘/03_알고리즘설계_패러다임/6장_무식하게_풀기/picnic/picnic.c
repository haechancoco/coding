/* 
문제설명:
  각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때
  학생들을 짝지을 수 있는 경우의 수를 구하라.

입력:
  첫 줄에 테스트 케이스 수
  테스트 케이스 첫 출에는 학생수: n (2 <= n <= 10)과 친구 쌍의 수: m (0 <= m <= n(n - 1) / 2)
  그 다음 줄엔 m개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어진다.

예제 입력:
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

예제 출력:
  1
  3
  4
*/

#include <stdio.h>
#include <stdbool.h>

int count_pairngs(int n, bool (*areFriends)[n], bool *taken) {
  // 남은 학생들 중 가장 번호가 빠른 학생을 찾는다. (중복으로 세는걸 피하기 위함)
  int firstFree = -1;
  for (int i = 0; i < n; i++) {
    if (!taken[i]) {
      firstFree = i;
      break;
    }
  }
  // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾은거니 종료한다.
  if (firstFree == -1) return 1;
  int ret = 0;
  // 이 학생과 짝지을 학생을 결정한다.
  for (int candidate = firstFree + 1; candidate < n; ++candidate) {
    if (!taken[candidate] && areFriends[firstFree][candidate]) {
      taken[firstFree] = taken[candidate] = true;
      ret += count_pairngs(n, areFriends, taken);
      taken[firstFree] = taken[candidate] = false;
    }
  }
  return ret;
}

int main(void) {
  // 테스트 케이스 수 저장.
  int t;
  scanf("%d", &t);

  while (t--) {
    // 학생수, 친구 쌍의 수 저장.
    int n, m;
    scanf("%d %d", &n, &m);

    // taken: 선택되면 true, 선택되지 않으면 false.
    // areFreinds: 친구 쌍 저장, 친구면 true, 친구 아니면 false.
    bool taken[10] = {0};
    bool areFriends[n][n];
      // areFreinds false로 초기화.
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        areFriends[i][j] = false;
      }
    }
      // 친구쌍 저장.
    for (int i = 0; i < m; ++i) {
      int f1, f2;
      scanf("%d %d", &f1, &f2);
      areFriends[f1][f2] = true;
      areFriends[f2][f1] = true;
    }

    printf("%d\n", count_pairngs(n, areFriends, taken));
  }
  return 0;
}
