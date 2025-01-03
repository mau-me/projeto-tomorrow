#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* prox;
} Node;

typedef struct Pilha {
  Node* head;
} Pilha;

Pilha* createPilha() {
  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->head = NULL;
  return pilha;
}

void push(Pilha* pilha, int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->prox = NULL;

  if (pilha->head == NULL) {
    pilha->head = node;
  } else {
    node->prox = pilha->head;
    pilha->head = node;
  }
}

int pop(Pilha* pilha) {
  if (pilha->head == NULL) {
    return NULL;
  }

  Node* node = pilha->head;
  pilha->head = pilha->head->prox;
  int value = node->value;
  free(node);
  return value;
}

int peek(Pilha* pilha) {
  if (pilha->head == NULL) {
    return NULL;
  }

  return pilha->head->value;
}

void clear(Pilha* pilha) {
  Node* node = pilha->head;
  while (node != NULL) {
    Node* temp = node;
    node = node->prox;
    free(temp);
  }
  pilha->head = NULL;
}

void printPilha(Pilha* pilha) {
  Node* node = pilha->head;
  while (node != NULL) {
    printf("%d\n", node->value);
    node = node->prox;
  }
}

int main() {
  Pilha* pilha = createPilha();
  push(pilha, 1);
  push(pilha, 2);
  push(pilha, 3);
  push(pilha, 4);
  push(pilha, 5);
  printPilha(pilha);
  printf("Pop: %d\n", pop(pilha));
  printf("Pop: %d\n", pop(pilha));
  printf("Peek: %d\n", peek(pilha));
  clear(pilha);
  printPilha(pilha);
  return 0;
}