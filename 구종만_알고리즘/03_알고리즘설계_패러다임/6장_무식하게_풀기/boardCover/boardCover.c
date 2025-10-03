#include <stdio.h>
#include <stdbool.h>

#include "getboard.h"

const int coverType[][3][2] = {
  { {0, 0}, {0, 1}, {1, 1} }, // 'ㄱ'
  { {0, 0}, {1, 0}, {0, 1} }, // 옆으로 뒤집힌 'ㄱ'
  { {0, 0}, {1, 0}, {1, 1} }, // 'ㄴ'
  { {0, 0}, {1, 0}, {1, -1} } // 옆으로 뒤집힌 'ㄴ'
};

enum {
  // 블럭 종류 개수.
  TYPENUM = sizeof(coverType) / sizeof(coverType[0]),
  // 블럭을 구성하는 블럭 수.
  STYPENUM = sizeof(coverType[0]) / sizeof(coverType[0][0])
};

bool set(S_B *board, int y, int x, int type, int delta);
int cover(S_B *board);

int main(void) {

  return 0;
}


// board[y][x]를 type번 방법으로 덮거나, 덮었던 블록을 없엔다.
// delta 1 이면 덮고, -1 이면 덮었던 블록을 없엔다.
// 만약 블록이 제데로 덮이지 않은 경우 (게임판 밖으로 나가거나,
// 겹치거나 같은 칸을 덮을 때) false를 반환한다.
bool set(S_B *board, int y, int x, int type, int delta) {
  bool ok = true;
  for (int i = 0; i < STYPENUM; ++i) {
    const int ny = y + coverType[type][i][0];
    const int nx = x + coverType[type][i][1];
    if (ny < 0 || ny >= board->ylen || nx < 0 || nx >= board->xlen) {
      ok = false;
    }
    else if ((board->b[ny][nx] += delta) > 1) {
      ok = false;
    }
  }
  return ok;
}


// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
// board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
// board[i][j] = 0 아직 덮이지 않은 칸.
int cover(S_B *board) {
  // 아직 채우지 못한 칸 중 가장 위줄 왼쪽에 있는 칸을 찾는다.
  int y = -1, x = -1;
  for (int i = 0; i < board->ylen; ++i) {
    for (int j = 0; j < board->xlen; ++j) {
      if (board->b[i][j] == 0) {
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1) break;
  }
  // 기저 사례: 모든 칸을 채웠으면 1을 반환한다.
  if (y == -1) return 1;
  int ret = 0;
  for (int type = 0 ; type < TYPENUM; ++type) {
    // 만약 board[y][x]를 type형태로 덮을 수 있으면 재귀 호출한다.
    if (set(board, y, x, type, 1)) {
      ret += cover(board);
    }
    // 덮었던 블록을 다시 치운다.
    set(board, y, x, type, -1);
  }
  return ret;
}

