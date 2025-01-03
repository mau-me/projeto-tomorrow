#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node* prox;
} Node;

typedef struct Lista {
  Node* head;
} Lista;

Lista* createLista() {
  Lista* lista = (Lista*)malloc(sizeof(Lista));
  lista->head = NULL;
  return lista;
}

void push(Lista* lista, int value) {
  Node* novo = (Node*)malloc(sizeof(Node));
  novo->value = value;
  novo->prox = NULL;

  if (lista->head == NULL) {
    lista->head = novo;
  } else {
    Node* aux = lista->head;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}

void pop(Lista* lista) {
  if (lista->head == NULL) {
    return;
  }

  Node* aux = lista->head;
  lista->head = lista->head->prox;
  free(aux);
}

int front(Lista* lista) {
  if (lista->head == NULL) {
    return NULL;
  }

  return lista->head->value;
}

void show(Lista* lista) {
  Node* aux = lista->head;
  while (aux != NULL) {
    printf("%d ", aux->value);
    aux = aux->prox;
  }
  printf("\n");
}

int main() {
  Lista* lista = createLista();

  push(lista, 1);
  push(lista, 2);
  push(lista, 3);
  push(lista, 4);
  push(lista, 5);

  show(lista);

  pop(lista);
  pop(lista);

  show(lista);

  return 0;
}