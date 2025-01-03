#include <stdio.h>
#include <stdlib.h>

void indiceMaiorNome(char **nomes, int qtdNomes){
  int indiceMaior, qtdLetrasMaior = -1;

  printf("\n\n%s\n\n", nomes[0]);
  
  for(int i = 0; i < qtdNomes; i++){
    int posicaoLetra, qtdLetrasNomeAtual = 0;
    char letra = nomes[i][posicaoLetra];
    qtdLetrasNomeAtual++;
    while(letra != '\0'){
      qtdLetrasNomeAtual++;
    }

    if(qtdLetrasNomeAtual > qtdLetrasMaior){
      qtdLetrasMaior = qtdLetrasNomeAtual;
      indiceMaior = i;
    }
  }

  printf("\n\nO maior nome recebido eh %s, contendo %i letras", nomes[indiceMaior], qtdLetrasMaior);
}

int main(){

  char **nomes = NULL;

  nomes = malloc(sizeof(char *) * 3);

  for(int i = 0; i < 5; i++){
    nomes[i] = malloc(sizeof(char) * 20);
    printf("\nInsira o nome da pessoa 0%d: ", i + 1);
    scanf("%s", nomes[i]);
  }

  indiceMaiorNome(nomes, 3);
  return 0;
} 
