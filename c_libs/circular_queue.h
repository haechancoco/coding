#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define QUEUE_MAX_SIZE 10000

typedef struct circular_queue ST_CQ;

void queue_init(ST_CQ *q);
ST_CQ *circular_queue_create(void);
int get_idx(int idx, int n);
// push X: 정수 X를 큐에 넣는 연산이다.
void push(ST_CQ *q, int n);
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(ST_CQ *q);
// size: 큐에 들어있는 정수의 개수를 출력한다.
int size(ST_CQ *q);
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty(ST_CQ *q);
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front(ST_CQ *q);
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back(ST_CQ *q);

#endif