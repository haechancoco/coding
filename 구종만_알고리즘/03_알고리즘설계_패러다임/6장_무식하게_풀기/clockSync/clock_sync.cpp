/* 
문제 설명:
  4 * 4 개의 격자 형태로 배치된 열여섯 개의 시계가 있다.
  이 시계들은 모두 12시, 9시, 6시, 혹은 3시를 가리키고 있다.
  목적은 모든 시계들이 12시를 가리키도록 하는 것이다.

  시계의 시간을 조작하는 유일한 방법은 스위치들을 조작하는 것이다.
  스위치는 적게는 세 개에서 많게는 다섯 개의 시계에 연결되어 있다.
  한 스위치를 누를 때마다, 해당 스위치와 연결된 시계들의 시간은 3시간씩 앞으로 움직인다.



입력:
  첫 줄에 테스트 케이스 개수 C(C<=30)가 주어진다.
  각 테스트 케이스는 한 줄에 16개의 정수로 주어지며, 각 정수는 0번부터 15번 까지 각 시계가 
  가리키고 있는 시간을 12, 3, 6, 9 중 하나로 표현한다.  

출력:
  각 테스트 케이스당 정수 하나를 한 줄에 출력합니다. 이 정수는 시계들을 모두 12시로 돌려놓기
  위해 스위치를 눌러야 할 최소 횟수여야 하며, 만약 이것이 불가능할 경우 -1을 출력해야 합니다.
*/
/* 
문제 변형하기:
  1. 버튼을 누르는 순서는 상관없음.
  2. 시계는 12시간이 지나면 제 자리로 돌아옴.
        -> 버튼을 4번 누르면 누르지 않은 상태와 같음. 
        -> 버튼을 4번 이상 누를 필요가 없음.
  
  각 버튼을 누르는 횟수는 0 에서 3 사이의 정수가 됨.
  버튼이 n 개라면 경우의 수는 4^n 가지.
  버튼이 10개라면 4^10 = 1,048,576 가지 완전 탐색으로 충분히 가능.
*/

#include <iostream>
#include <vector>

using namespace std;

// 버튼을 최대로 누르는 수는 3*SWITCHES 이므로 INF는 31로 해도 충분하긴 하다.
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// linked[i][j] = 'x': i번 스위치와 j번 시계가 연결되어 있다.
// linked[i][j] = 'x': i번 스위치와 j번 시계가 연결되어 있지 않다.
const char linked[SWITCHES][CLOCKS + 1] = {
  "xxx.............",
  "...x...x.x.x....",
  "....x.....x...xx",
  "x...xxxx........",
  "......xxx.x.x...",
  "x.x...........xx",
  "...x..........xx",
  "....xx.x......xx",
  ".xxxxx..........",
  "...xxx...x...x.."
};

// 모든 시계가 12시를 가리키고 있는지 확인한다.
bool areAligned(const vector<int>& clocks);

// swtch번 스위치를 누른다.
void push(vector<int>& clocks, int swtch) {
  for (int clock = 0; clock < CLOCKS; ++clock) {
    if (linked[swtch][clock] == 'x') {
      clocks[clock] += 3;
      if (clocks[clock] == 15) clocks[clock] = 3;
    }
  }
}

// clocks: 현재 시계들의 상태
// switch: 이번에 누를 스위치의 번호
// 가 주어질 때, 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다.
// 만약 불가능하다면 INF이상의 큰 수를 반환한다.
int solve(vector<int>& clocks, int swtch) {
  // 기저 사례
  if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;
  // 이 스위치를 0번 누르는 경우부터 세 번 누르는 경우까지를 모두 시도한다.
  int ret = INF;
  for (int cnt = 0; cnt < 4; ++cnt) {
    ret = min(ret, cnt + solve(clocks, swtch + 1));
    push(clocks, swtch);
  }
  // push(clocks, switch)가 네번 호출되었으니 clocks는 원래와 같은 상태가 된다.
  return ret;
}

int main(void) {

    return 0;
}