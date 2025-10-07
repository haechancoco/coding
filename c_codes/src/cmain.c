#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct stack {
  int *arr;
  int top;
  int size;
} S_ST;

struct stack *stack_create(int size);
void push(struct stack *stack, int num);
int pop(struct stack *stack);
int empty(struct stack *stack);
int top(struct stack *stack);

int main(void) {
  int n;
  scanf("%d", &n);

  int seq[n];
  int check = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", seq + i);
  }
  
  int in = 1;
  S_ST *s = stack_create(n);
  const int RESULT_SIZE = 2 * n;
  char result[RESULT_SIZE];
  int ridx = 0;
  while (in <= n) {
    if (top(s) != seq[check]) {
      push(s, in++);
      result[ridx++] = '+';
    } else {
      check++;
      pop(s);
      result[ridx++] = '-';
    }
    // printf("%c\n", result[ridx - 1]);
  }

  while (top(s) == seq[check++]) {
    pop(s);
    result[ridx++] = '-';
  }

  if (empty(s)) {
    // printf("\n\nresult:\n");
    for (int i = 0; i < RESULT_SIZE; ++i) {
      printf("%c\n", result[i]);
    }
  } else {
    printf("NO\n");
  }
  return 0;
}




// stack 초기와 함수.
static void stack_init(struct stack *stack, int size) {
  stack->arr = malloc(size * sizeof(int));
  stack->top = 0;
  stack->size = size;
}

// stack을 만들어서 주소를 반환한다.
struct stack *stack_create(int size) {
  struct stack *new = malloc(sizeof(struct stack));
  stack_init(new, size);
  return new;
}

// push X: 정수 X를 스택에 넣는 연산이다.
void push(struct stack *stack, int num) {
  stack->arr[stack->top++] = num;
}
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에
// 들어있는 정수가 없는 경우에는 -1을 출력한다.
int pop(struct stack *stack) {
  if (empty(stack)) {
    return -1;
  }
  stack->top--;
  return stack->arr[stack->top];
}
// size: 스택에 들어있는 정수의 개수를 출력한다.
int length(struct stack *stack) { return stack->top; }
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
int empty(struct stack *stack) { return stack->top == 0 ? 1 : 0; }
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는
// 경우에는 -1을 출력한다.
int top(struct stack *stack) {
  return stack->top == 0 ? -1 : stack->arr[stack->top - 1];
}

// stack_free(&stack) 형식으로 사용. 
// 스텍을 반환하고 NULL로 초기화한다.
void stack_free(S_ST **stack) {
  S_ST *s = *stack;
  free(s->arr);
  s->arr = NULL;
  *stack = NULL;
}
