#include <stdlib.h>

#include "queue.h"
typedef struct queue {
  int *arr;
  int front;
  int back;
  int size;
} S_QUE;

static void queue_init(S_QUE *q, int size) {
  q->arr = malloc(size * sizeof(int));
  q->front = 0;
  q->back = 0;
  q->size = size;
}

S_QUE *queue_create(int size) {
  S_QUE * new = malloc(sizeof(S_QUE));
  queue_init(new, size);
  return new;
}

// push X: 정수 X를 큐에 넣는 연산이다.
void push(S_QUE *q, int n) {
  q->arr[++q->back] = n;
}
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(S_QUE *q) {
  if (empty(q)) {
    return -1;
  }
  q->front++;
  return q->arr[q->front];
}
// length: 큐에 들어있는 정수의 개수를 출력한다.
int length(S_QUE *q) {
  return q->back - q->front;
}
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty(S_QUE *q) {
  return q->front == q->back;
}
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front(S_QUE *q) {
  if (empty(q)) {
    return -1;
  }
  return q->arr[q->front];
}
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back(S_QUE *q) {
  if (empty(q)) {
    return -1;
  }
  return q->arr[q->back];
}

// queue_free(&q) 형식으로 사용, queue의 공간을 반환하고 NULL로 초기화 한다.
void queue_free(S_QUE **que) {
  S_QUE *q = *que;
  free(q->arr);
  q->arr = NULL;
  free(q);
  *que = NULL;
}


#ifdef TEST_QUEUE
#include <stdio.h>

int main(void) {
  int size = 10;
  S_QUE *q = queue_create(size);
  printf("init size: %d\n", q->size);
  printf("init length: %d\n", length(q));

  for (int i = 0; i < 10; ++i) {
    push(q, i);
    printf("leng: %d\n", length(q));
    printf("back: %d\n", back(q));
    printf("back: %d\n", q->back);
    printf("pop: %d\n\n", pop(q));
  }

  return 0;
}

#endif