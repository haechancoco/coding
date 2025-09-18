#include <stdlib.h>

#define QUEUE_MAX_SIZE 10000

struct circular_queue {
  int *arr;
  int front;
  int back;
};

void queue_init(struct circular_queue *q) {
  q->arr = malloc(QUEUE_MAX_SIZE * sizeof(int));
  q->front = 0;
  q->back = 0;
}

struct circular_queue *circular_queue_create(void) {
  struct circular_queue * new = malloc(sizeof(struct circular_queue));
  queue_init(new);
  return new;
}

// push X: 정수 X를 큐에 넣는 연산이다.
void push(struct circular_queue *q, int n) {
  q->arr[q->back++] = n;
}
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(struct circular_queue *q) {
  if (q->front == q->back) {
    return -1;
  }
  int old = q->front++;
  return q->arr[old];
}
// size: 큐에 들어있는 정수의 개수를 출력한다.
int size(struct circular_queue *q) {
  return q->back - q->front;
}
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty(struct circular_queue *q) {
  return q->front == q->back;
}
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front(struct circular_queue *q) {
  if (q->front == q->back) {
    return -1;
  }
  return q->arr[q->front];
}
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back(struct circular_queue *q) {
  if (q->front == q->back) {
    return -1;
  }
  return q->arr[q->back - 1];
}