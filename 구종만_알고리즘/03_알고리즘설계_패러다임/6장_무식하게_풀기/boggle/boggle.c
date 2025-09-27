/* 
boggle게임에 대한 설명
{U, R, L, P, M},
{X, P, R, E, T},
{G, I, A, E, T},
{X, T, N, Z, Y},
{X, O, Q, R, S}

시작 지점으로 부터 상하좌우/대각선으로 인접한 칸들의 글자들을 이어서
단어를 찾는 게임.
한 글자가 2 번 이상 사용될 수 있음.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define XMAX 5
#define YMAX 5
#define DMAX 8

bool in_range(int y, int x);
bool recursive_solve(int y, int x, const char (*board)[5], const char *word);

char board[YMAX][XMAX] = {
    {'U', 'R', 'L', 'P', 'M'},
    {'X', 'P', 'R', 'E', 'T'},
    {'G', 'I', 'A', 'E', 'T'},
    {'X', 'T', 'N', 'Z', 'Y'},
    {'X', 'O', 'Q', 'R', 'S'}
};

int dy[DMAX] = {-1, 0, 1, -1, 0, 1, 1, -1};
int dx[DMAX] = {-1, -1, -1, 1, 1, 1, 0, 0};

int main(void) {
    printf("%d\n", recursive_solve(1, 1, board, "PRETTY"));

    return 0;
}

bool in_range(int y, int x) {
    return y >= 0 && YMAX > y && x >= 0 && XMAX > x;
}

bool recursive_solve(int y, int x, const char (*board)[5], const char *word) {
    // 기저 사례1: 시작 위치가 범위 밖이면 무조건 실패.
    if (!in_range(y, x)) return false;

    // 기저 사례2: 첫 글자가 일치하지 않으면 실패.
    // printf("[%d,%d] %c\n", y, x, board[y][x]);
    if (board[y][x] != word[0]) return false;

    // 기저 사례3: 단어 길이가 1이면 성공.
    if (strlen(word) == 1) return true;
    
    // 인접한 여덟 칸을 검사한다.
    for (int direc = 0; direc < DMAX; direc++) {
        int next_y = y + dy[direc];
        int next_x = x + dx[direc];
        if (recursive_solve(next_y, next_x, board, word + 1)) {
            return true;
        }
    }
    return false;
}