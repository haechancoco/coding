/* 
숫자 클수록 중요도 큼.

중요도 순으로 뽑으니 시작 위치 상관 없이
내림차순 정렬 순으로 출력될 것임.
계수정렬 사용하면 될 듯.
근대 중요도 같으면 순서 어떻게 찾음?

(1) 1 1 2 1
괄호 쳐진 문서의 출력 순서가 궁금하다고 하자.
대상의 중요도 보다 큰 문서가 뽑히기 전까지는 큐를 뱅뱅 돔.
-> 대상과 같은 중요도를 가진 문서들의 상대적 순서는 고정됨.
대상의 중요도 + 1 인 문서가 마지막으로 뽑히는 위치가 대상의 천장(시작지점) 일 것.
그대 마지막으로 뽑히는 + 1 중요도의 문서는 어떻게 찾음?

마지막으로 뽑히는 + 1 중요도의 문서(last_up_paper LUP 라고 하자)의 위치를 알기 위해선
위와 동일하게 LUP의 LUP의 위치를 알아야 한다.
즉 최중요 문서의 마지막 부터 알아야 한다.
마지막 순서는 어떻게 찾을 수 있을까?

최중요 문서의 마지막 위치는 큐의 tail 부터 확인했을 때 첫번째로 확인되는 위치이다.
그 다음 문서의 마지막 위치는 LUP의 위치부터 fornt로 확인했을때 가장 첫번재로 확인되는 위치이다.

// 그냥 큐 구현해서 해야 할 듯...

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int find_next_last(int *order, int order_len, int lup_idx, int m_p) {
  for (int i = lup_idx; /* do nothing */; i = (i + order_len - 1) % order_len) {
    if (order[i] == m_p) {
      return i;
    }
  }
}

int main(void) {
  // int t;
  // scanf("%d", &t);
  
  // 문서수와 궁금한 문서 위치 저장
  int n, m;
  scanf("%d %d", &n, &m);

  // 문서 순서와, 정렬 저장.
  int order[n];
  int order_p[n];
  for (int i = 0; i < n; i++) {
    order[i] = 0;
    order_p[i] = 0;
  }
  
  int sort[10] = {0};
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    order[i] = p;
    sort[p]++;
  }
  for (int p = 0, i = 9; i >= 0; i--) {
    if (sort[i] != 0) {
      order_p[p++] = i;
    }
  }
  
  // m의 LUP위치 찾기
  int m_p = order[m];
  int p_idx = 0;
  int lup_idx = -1;
  for (int i = n - 1; order_p[p_idx] > m_p; i = (i + n - 1) % n) {
      if (order[i] == order_p[p_idx]) {
        p_idx++;
        lup_idx = i;
      }
  }

  if (lup_idx == -1) {

  }

  

  return 0;
}