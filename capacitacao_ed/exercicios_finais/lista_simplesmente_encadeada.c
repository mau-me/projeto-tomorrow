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

// Remove um nó pelo seu valor
void removerNo(Node* head, int value) {
  Node* aux = head;
  Node* ant = NULL;

  while (aux != NULL) {
    if (aux->value == value) {
      if (ant == NULL) {
        head = aux->prox;
        free(aux);
        return;
      }
      ant->prox = aux->prox;
      free(aux);
      return;
    }
    ant = aux;
    aux = aux->prox;
  }
}

void insert(Lista* lista, int value, int pos) {
  Node* novo = (Node*)malloc(sizeof(Node));
  novo->value = value;

  if (pos == 0) {
    novo->prox = lista->head;
    lista->head = novo;
    return;
  }

  Node* aux = lista->head;
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

  insert(lista, 10, 0);
  insert(lista, 20, 3);
  insert(lista, 30, 6);

  show(lista);

  removerNo(lista->head, 30);

  show(lista);

  return 0;
}