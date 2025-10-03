#include <stdlib.h>

#include "circular_queue.h" 

// size - 1개 저장 가능.
typedef struct circular_queue {
  int *arr;
  int front;
  int back;
  int size;
} ST_CQ;

void queue_init(ST_CQ *q, int size) {
  q->arr = malloc(size * sizeof(int));
  q->front = 0;
  q->back = 1;
  q->size = size;
}

ST_CQ *circular_queue_create(int size) {
  ST_CQ * new = malloc(sizeof(ST_CQ));
  queue_init(new, size);
  return new;
}
// 순환 큐의 idx + n 번째 인덱스를 반한한다.
int get_idx(ST_CQ *q, int idx, int n) {
  const int QSIZE = q->size;

  return ((idx + n) % QSIZE + QSIZE) % QSIZE;
}

// push X: 정수 X를 큐에 넣는 연산이다.
void push(ST_CQ *q, int n) {
  const int QSIZE = q->size;

  q->arr[q->back] = n;
  q->back = (q->back + 1) % QSIZE;
}

// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(ST_CQ *q) {
  const int QSIZE = q->size;

  if (empty(q)) {
    return -1;
  }
  q->front = (q->front + 1) % QSIZE;
  return q->arr[q->front];
}

// lenght: 큐에 들어있는 정수의 개수를 출력한다.
int length(ST_CQ *q) {
  const int QSIZE = q->size;

  return (QSIZE + q->back - q->front - 1) % QSIZE;
}

// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty(ST_CQ *q) {
  const int QSIZE = q->size;

  return (q->front + 1) % QSIZE == q->back;
}

// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front(ST_CQ *q) {
  const int QSIZE = q->size;

  if (empty(q)) {
    return -1;
  }
  return q->arr[(q->front + 1) % QSIZE];
}

// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back(ST_CQ *q) {
  if (empty(q)) {
    return -1;
  }
  return q->arr[get_idx(q, q->back, -1)];
}

#ifdef TEST_CIRCULAR_QUEUE
#include <stdio.h>

int main(void) {
  int size = 10;
  ST_CQ *q = circular_queue_create(10);
  printf("empty f: %d\n", front(q));
  for (int i = 0; i < size; ++i) {
    push(q, i);
    printf("%d\nf: %d\n", i,  back(q));
    printf("l: %d\n\n", length(q));
  }
}
#endif