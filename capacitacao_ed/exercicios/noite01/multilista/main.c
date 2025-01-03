#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 50

typedef struct No {
  char *nome;
  int idade;
  struct No *prox_nome;
  struct No *prox_idade;
} no;

typedef struct Head {
  struct No *inicio_nomes;
  struct No *inicio_idades;
} head;

void inicializa_lista(head *lista) {
  lista->inicio_nomes = NULL;
  lista->inicio_idades = NULL;
}

// todo
// ! inserção dos nos de nomes com problemas

void add_lista_idade(head *lista, no *novo_no) {
  no *temp = lista->inicio_idades;
  no *anterior = NULL;

  while (temp != NULL && novo_no->idade > temp->idade) {
    anterior = temp;
    temp = temp->prox_idade;
  }

  anterior->prox_idade = novo_no;
  novo_no->prox_idade = temp;
}

void add_lista_nome(head *lista, no *novo_no) {
  printf("dentro de add_lista_nome\n");
  no *temp = lista->inicio_nomes;
  no *anterior = NULL;
  printf("TEMP: %s\n", temp->nome);
  while (temp != NULL) {
    int comparacao = strcmp(temp->nome, novo_no->nome);
    printf("comparacao entre %s e %s eh: %i\n", temp->nome, novo_no->nome,
           comparacao);
    printf("dentro do while de add_lista_nome\n");
    if (comparacao < 0) {
      anterior = temp;
      temp = temp->prox_nome;
    } else {
      break;
    }
  }

  anterior->prox_nome = novo_no;
  novo_no->prox_nome = temp;
}

void add_lista(head *lista, char *nome, int idade) {
  printf("dentro de add_lista\n");
  no *novo_no = (malloc(sizeof(no)));

  novo_no->idade = idade;
  novo_no->nome = nome;
  novo_no->prox_idade = NULL;
  novo_no->prox_nome = NULL;

  if (lista->inicio_idades == NULL && lista->inicio_nomes == NULL) {
    printf("inserindo 'no' no if\n");
    lista->inicio_idades = novo_no;
    lista->inicio_nomes = novo_no;
  } else {
    printf("inserindo 'no' no else\n");
    add_lista_idade(lista, novo_no);
    add_lista_nome(lista, novo_no);
  }
}

void imprimir_lista(head *lista) {
  no *no_aux_idade = lista->inicio_idades;
  no *no_aux_nome = lista->inicio_nomes;
  printf("\n\n");
  while (no_aux_idade != NULL && no_aux_nome != NULL) {
    printf("%s | %i\n", no_aux_nome->nome, no_aux_idade->idade);

    no_aux_idade = no_aux_idade->prox_idade;
    no_aux_nome = no_aux_nome->prox_nome;
  }
}

int main() {
  int tam_lista;
  printf("TAMANHO DA LISTA: \n");
  scanf("%d", &tam_lista);

  head *lista = (head *)malloc(sizeof(head));
  inicializa_lista(lista);
  char nome[TAM_MAX_NOME];
  int idade;

  for (int i = 0; i < tam_lista; i++) {
    scanf(" %[^\n]", nome);
    scanf("%d", &idade);

    add_lista(lista, nome, idade);
  }

  imprimir_lista(lista);

  printf("\n\n");
  // printf("%i, %i", lista->inicio_idades->idade,
  // lista->inicio_idades->prox_idade->idade); printf("%s, %s",
  // lista->inicio_nomes->nome, lista->inicio_nomes->prox_nome->nome);
}