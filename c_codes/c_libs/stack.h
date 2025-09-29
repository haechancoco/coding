typedef struct stack S_ST;

struct stack *stack_create(void);
void push(struct stack *stack, int num);
int pop(struct stack *stack);
int size(struct stack *stack);
int empty(struct stack *stack);
int top(struct stack *stack);




