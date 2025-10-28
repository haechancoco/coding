typedef struct queue S_QUE;

S_QUE *circular_queue_create(int size);
void push(S_QUE *q, int n);
int pop(S_QUE *q);
int length(S_QUE *q);
int empty(S_QUE *q);
int front(S_QUE *q);
int back(S_QUE *q);



