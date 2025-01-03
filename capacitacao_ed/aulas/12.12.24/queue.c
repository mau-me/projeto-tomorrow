#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
	int data;
	struct No *prox;
} nodo; 

typedef struct Head {
    struct No *inicio;
} head;


void add_fila(head *fila, int valor){
  if(fila->inicio == NULL){
    nodo *no = malloc(sizeof(nodo));
    no->data = valor;
    fila->inicio = &no;
  }

  return;
}


int main(){
  head *fila = (head *) malloc(sizeof(head));
  fila->inicio = NULL;

  add_fila(fila, 4);
  
  print("%d", fila->inicio->data);

  nodo *no = malloc(sizeof(no));
  no->data = 4;
  no->prox = NULL;

  fila->inicio = &no;

  printf("%d\n", no->data);

}
// Algoritmo de Round Robin

