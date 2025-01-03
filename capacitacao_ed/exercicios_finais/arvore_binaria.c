#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

struct Pessoa {
  int idade;
  char nome;
  struct Pessoa* prox;
};

int soma(int num1, int num2) {
  return num1 + num2;
}

int main() {
  int a, b, result = 0;

  printf("Tamanho de um inteiro: %ld\n", sizeof(struct Pessoa));

  char cidade[3];

  struct Pessoa* pessoa02;

  pessoa02 = malloc(sizeof(struct Pessoa));

  struct Pessoa pessoa[10];

  pessoa[0].prox = &pessoa[1];

  printf("digite a cidade:\n");
  scanf("%s", cidade);

  printf("%s\n", cidade);

  static int idade = 20;

  printf("Digite os dois números:\n");
  scanf("%i %i", &a, &b);

  printf("%d %d\n", TAM_MAX, idade);
  result = soma(a, b);

  printf("O resultado é: %d\n", result);
  printf("%s\n", cidade);
}