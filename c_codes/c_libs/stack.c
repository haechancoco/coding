#include <stdlib.h>

#include "stack.h"

typedef struct stack {
  int *arr;
  int top;
  int size;
} S_ST;

/*
==static 함수=======================================
*/
// stack 초기와 함수.
static void stack_init(struct stack *stack, int size) {
  stack->arr = malloc(size * sizeof(int));
  stack->top = 0;
  stack->size = size;
}

/*
--static 함수--------------------------------------------------
*/

/*
==공개 함수=========================================
*/

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
int size(struct stack *stack) { return stack->top; }
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
int empty(struct stack *stack) { return stack->top == 0 ? 1 : 0; }
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는
// 경우에는 -1을 출력한다.
int top(struct stack *stack) {
  return stack->top == 0 ? -1 : stack->arr[stack->top - 1];
}

/*
--공개 함수----------------------------------------------
*/