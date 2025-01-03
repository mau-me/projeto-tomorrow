#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* prox;
} Node;

typedef struct Vetor {
  Node* head;
} Vetor;

Vetor* createVetor() {
  Vetor* vetor = (Vetor*)malloc(sizeof(Vetor));
  vetor->head = NULL;
  return vetor;
}

void push(Vetor* vetor, int value) {
  Node* novo = (Node*)malloc(sizeof(Node));
  novo->value = value;
  novo->prox = NULL;

  if (vetor->head == NULL) {
    vetor->head = novo;
  } else {
    Node* aux = vetor->head;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

void pop(Vetor* vetor) {
  if (vetor->head == NULL) {
    return;
  }

  Node* aux = vetor->head;
  Node* ant = NULL;
  while (aux->prox != NULL) {
    ant = aux;
    aux = aux->prox;
  }

  if (ant == NULL) {
    vetor->head = NULL;
  } else {
    ant->prox = NULL;
  }

  free(aux);
}

void insert(Vetor* vetor, int value, int pos) {
  Node* novo = (Node*)malloc(sizeof(Node));
  novo->value = value;

  if (pos == 0) {
    novo->prox = vetor->head;
    vetor->head = novo;
    return;
  }

  Node* aux = vetor->head;
  Node* ant = NULL;
  for (int i = 0; i < pos; i++) {
    if (aux == NULL) {
      return;
    }
    ant = aux;
    aux = aux->prox;
  }

  ant->prox = novo;
  novo->prox = aux;
}

void show(Vetor* vetor) {
  Node* aux = vetor->head;
  while (aux != NULL) {
    printf("%d ", aux->value);
    aux = aux->prox;
  }
  printf("\n");
}

int main() {
  Vetor* vetor = createVetor();

  push(vetor, 1);
  push(vetor, 2);
  push(vetor, 3);
  push(vetor, 4);
  push(vetor, 5);

  show(vetor);

  pop(vetor);
  pop(vetor);

  show(vetor);

  insert(vetor, 10, 0);
  insert(vetor, 20, 2);
  insert(vetor, 30, 4);

  show(vetor);

  return 0;
}