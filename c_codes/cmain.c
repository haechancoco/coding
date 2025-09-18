#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 1000

typedef struct circular_queue {
  int *arr;
  int front;
  int back;
} ST_CQ;

void queue_init(ST_CQ *q) {
  q->arr = malloc(QUEUE_MAX_SIZE * sizeof(int));
  q->front = 0;
  q->back = 1;
}

ST_CQ *circular_queue_create(void) {
  ST_CQ * new = malloc(sizeof(ST_CQ));
  queue_init(new);
  return new;
}

// 순환 큐의 idx + n 번째 인덱스를 반한한다.
int get_idx(int idx, int n) {
    return ((idx + n) % QUEUE_MAX_SIZE + QUEUE_MAX_SIZE) % QUEUE_MAX_SIZE;
}

// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
int empty(ST_CQ *q) {
  return (q->front + 1) % QUEUE_MAX_SIZE == q->back;
}

// size: 큐에 들어있는 정수의 개수를 출력한다.
int size(ST_CQ *q) {
  return (QUEUE_MAX_SIZE + q->back - q->front - 1) % QUEUE_MAX_SIZE;
}

// push X: 정수 X를 큐에 넣는 연산이다.
void push(ST_CQ *q, int n) {
  q->arr[q->back] = n;
  q->back = (q->back + 1) % QUEUE_MAX_SIZE;
}

// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(ST_CQ *q) {
  if (empty(q)) {
    return -1;
  }
  q->front = (q->front + 1) % QUEUE_MAX_SIZE;
  return q->arr[q->front];
}

// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int front(ST_CQ *q) {
  if (empty(q)) {
    return -1;
  }
  return q->arr[(q->front + 1) % QUEUE_MAX_SIZE];
}

// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
int back(ST_CQ *q) {
  if (empty(q)) {
    return -1;
  }
  return q->arr[get_idx(q->front, -1)];
}


int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);

  ST_CQ *q = circular_queue_create();

  for (int i = 1; i <= n; i++) {
    push(q, i);
  }

  int cnt = 0;
  int result[1000];
  int idx = 0;
  while (!empty(q)) {
    if (++cnt % k == 0) {
      cnt = 0;
      result[idx++] = pop(q);
    }
    else {
      push(q, pop(q));
    }
  }
  
  printf("<");
  for (int i = 0; i < n - 1; i++) {
    printf("%d, ", result[i]);
  } printf("%d>\n", result[n-1]);
  
  return 0;
}