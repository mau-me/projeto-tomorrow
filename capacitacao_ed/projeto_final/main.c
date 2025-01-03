#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct Head {
  struct No* raiz;
} head;

typedef struct No {
  char* nome;
  char* categoria;
  float preco;
  int qtd_estoque;
  struct No* esquerda;
  struct No* direita;
} no;

head* inicializa_arvore() {
  head* arvore = NULL;
  arvore = malloc(sizeof(head));

  arvore->raiz = NULL;

  return arvore;
}

void insere_produto(head* arvore) {
  char nome[TAM_NOME];
  char categoria[TAM_NOME];
  float preco;
  int qtd_estoque;

  // Criando o nó com o produto
  no* produto = NULL;
  produto = malloc(sizeof(no));

  if (produto == NULL) {
    printf("Erro ao alocar memória para o produto\n");
    return;
  }

  // Lendo os dados do produto
  printf("Digite o nome do produto: \n");
  scanf("%s", nome);
  printf("Digite a categoria do produto: \n");
  scanf("%s", categoria);
  printf("Digite o preço do produto: \n");
  scanf("%f", &preco);
  printf("Digite a quantidade em estoque do produto: \n");
  scanf("%d", &qtd_estoque);

  // Alocando memória para o nome e a categoria
  produto->nome = malloc(strlen(nome) + 1);
  produto->categoria = malloc(strlen(categoria) + 1);

  // Verificando se a alocação de memória foi bem sucedida
  if (produto->nome == NULL || produto->categoria == NULL) {
    printf("Erro ao alocar memória para o nome ou categoria do produto\n");
    return;
  }

  strcpy(produto->nome, nome);
  strcpy(produto->categoria, categoria);
  produto->preco = preco;
  produto->qtd_estoque = qtd_estoque;

  produto->esquerda = NULL;
  produto->direita = NULL;

  if (arvore->raiz == NULL) {
    arvore->raiz = produto;
  } else {
    no* atual = arvore->raiz;
    no* anterior = NULL;

    while (atual != NULL) {
      anterior = atual;

      if (strcmp(produto->nome, atual->nome) < 0) {
        atual = atual->esquerda;
      } else {
        atual = atual->direita;
      }
    }

    if (strcmp(produto->nome, anterior->nome) < 0) {
      anterior->esquerda = produto;
    } else {
      anterior->direita = produto;
    }
  }
}

no* buscar_produto(head* arvore, char* nome_produto) {
  no* atual = arvore->raiz;

  while (atual != NULL) {
    if (strcmp(nome_produto, atual->nome) == 0) {
      return atual;
    }

    if (strcmp(nome_produto, atual->nome) < 0) {
      atual = atual->esquerda;
    } else {
      atual = atual->direita;
    }
  }

  return NULL;
}

float calcula_preco_total(no* raiz) {
  float preco_total = 0;
  no* atual = raiz;

  while (atual != NULL) {
    return (atual->preco * atual->qtd_estoque) +
           calcula_preco_total(atual->esquerda) +
           calcula_preco_total(atual->direita);
  }

  return preco_total;
}

void imprime_arvore(no* raiz) {
  if (raiz != NULL) {
    imprime_arvore(raiz->esquerda);
    printf("%s\n", raiz->nome);
    printf("%s\n", raiz->categoria);
    printf("%d\n", raiz->qtd_estoque);
    printf("%.2f\n", raiz->preco);
    imprime_arvore(raiz->direita);
  }
}

void imprime_arvore_desenho(no* raiz, int espaco) {
  if (raiz == NULL) {
    return;
  }

  espaco += 10;

  imprime_arvore_desenho(raiz->direita, espaco);

  printf("\n");

  for (int i = 10; i < espaco; i++) {
    printf(" ");
  }

  printf("%s\n", raiz->nome);

  imprime_arvore_desenho(raiz->esquerda, espaco);
}

int menu() {
  printf("1 - Inserir produto\n");
  printf("2 - Buscar produto\n");
  printf("3 - Calcular preço total\n");
  printf("4 - Imprimir árvore\n");
  printf("5 - Limpar tela\n");
  printf("6 - Sair\n");

  int opcao;
  scanf("%d", &opcao);

  return opcao;
}

int main() {
  int produtos;

  head* arvore = inicializa_arvore();
  int opcao;

  do {
    opcao = menu();

    switch (opcao) {
      case 1:
        insere_produto(arvore);
        break;
      case 2:
        char nome_produto[TAM_NOME];
        printf("Digite o nome do produto que deseja buscar: \n");
        scanf("%s", nome_produto);

        no* produto_busca = buscar_produto(arvore, nome_produto);

        if (produto_busca != NULL) {
          printf("Produto encontrado: \n");
          printf("Nome: %s\n", produto_busca->nome);
          printf("Categoria: %s\n", produto_busca->categoria);
          printf("Preço: %.2f\n", produto_busca->preco);
          printf("Quantidade em estoque: %d\n", produto_busca->qtd_estoque);
        } else {
          printf("Produto não encontrado\n");
        }
        break;
      case 3:
        float preco_total = calcula_preco_total(arvore->raiz);
        printf("Preço total: %.2f\n", preco_total);
        break;
      case 4:
        imprime_arvore(arvore->raiz);
        break;
      case 5:
        // Limpando a tela
        system("clear");
        break;
      case 6:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  } while (opcao != 6);
}
