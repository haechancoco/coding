
typedef struct board S_B;

// 보드를 생성한다. 
S_B *board_create(int ylen, int xlen);
// 보드의 검은칸과 흰칸을 입력받는다.
void get_board(S_B *board);

void check_board(S_B *board);

int sele(S_B *board, int y, int x, int ele);

int gele(S_B *board, int y, int x);

int gylen(S_B *board);

int gxlen(S_B *board);
