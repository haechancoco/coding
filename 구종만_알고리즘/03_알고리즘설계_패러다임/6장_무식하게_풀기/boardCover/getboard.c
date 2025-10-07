/*
'#': 검은 칸
'.': 흰 칸

board는 다음과 같은 형식의 입력을 기대한다.
H, W (1 <= H, W <= 20)

예시 1)
H: 3, W: 7 
#.....#
#.....#
##...##

예시 2)
#.....#
#.....#
##..###

예시 3)
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########
*/

#include <stdio.h>
#include <stdlib.h>

#include "getboard.h"

#define XMAX 20
#define YMAX 20
typedef struct board {

  char **arr;
  int ylen;
  int xlen;
} S_B;

static void board_init(S_B *board, int ylen, int xlen) {
  board->ylen = ylen;
  board->xlen = xlen;
  board->arr = malloc(ylen * sizeof(char*));
  board->arr[0] = malloc(ylen * xlen * sizeof(char));
  for (int i = 1; i < ylen; i++) {
    board->arr[i] = board->arr[i - 1] + xlen;
  }
}

// 보드를 생성한다. 
S_B *board_create(int ylen, int xlen) {
  S_B *new = malloc(sizeof(S_B));
  board_init(new, ylen, xlen);
  return new;
}

// 보드의 검은칸과 흰칸을 입력받는다.
void get_board(S_B *board) {
  const int YLEN = board->ylen;
  const int XLEN = board->xlen;

  // 일단 문자열 그대로 입력받는다.
  for (int i = 0; i < YLEN; ++i) {
    scanf("%s", board->arr[i]);
  }

  // '#'이 검은 칸, '.'이 흰 칸.
  for (int i = 0; i < YLEN; ++i) {
    for (int j = 0; j < XLEN; ++j) {
      board->arr[i][j] = board->arr[i][j] == '#' ? 1 : 0;
    }
  }
}

void board_free(S_B **board) {
  S_B *b = *board;
  free(b->arr[0]);
  free(b->arr);
  b->arr = NULL;
  free(b);
  *board = NULL;
}

void check_board(S_B *board) {
  const int YLEN = board->ylen;
  const int XLEN = board->xlen;

  for (int i = 0; i < YLEN; ++i) {
    for (int j = 0; j < XLEN; ++j) {
      printf("%d ", board->arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int sele(S_B *board, int y, int x, int ele) {
  board->arr[y][x] = ele;
  return ele;
}


int gele(S_B *board, int y, int x) {
  return board->arr[y][x];
}

int gylen(S_B *board) {
  return board->ylen;
}

int gxlen(S_B *board) {
  return board->xlen;
}

#ifdef TEST_GETBOARD
int main(void) {
  S_B *b = board_create(3, 7);
  get_board(b);
  check_board(b);

  return 0;
}
#endif