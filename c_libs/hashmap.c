#include <stdlib.h>

#define HASH_MAX 100000

struct node {
  int n;
  int cnt;
  struct node *next;
};

int hash(int n) {
  return (n % HASH_MAX + HASH_MAX) % HASH_MAX;
}

struct node **create_map(void) {
  return calloc(HASH_MAX, sizeof(struct node*));
}

void node_init(struct node *node, int n) {
  node->n = n;
  node->cnt = 1;
  node->next = NULL;
}

struct node *create_node(int n) {
  struct node *new = malloc(sizeof(struct node));
  node_init(new, n);
  return new;
}

void put(struct node **map, int n) {
  const int H = hash(n);
  struct node *new = create_node(n);
  if (map[H] == NULL) {
    map[H] = new;
    return;
  }
  
  struct node *now = map[H];
  struct node *old;
  while (now) {
    if (now->n == n) {
      now->cnt++;
      free(new);
      return;
    }
    else {
      old = now;
      now = now->next;
    }
  }
  old->next = new;
}

int get(struct node **map, int n) {
  const int H = hash(n);
  if (map[H] == NULL) {
    return 0;
  }

  struct node *now = map[H];
  while (now) {
    if (now->n == n) {
      return now->cnt;
    }
    else {
      now = now->next;
    }
  }
  return 0;
}