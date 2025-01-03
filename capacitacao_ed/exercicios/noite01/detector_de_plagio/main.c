#include <stdlib.h>
#include <stdio.h>

#define QTD_PALAVRAS 2

typedef struct Letra
{
  char l;
  struct Letra *prox;
} letra;

typedef struct Sequencia
{
  struct Letra *head;
  int tam_seq;
} sequencia;

int detecta_plagio(sequencia *palavras)
{

  int controle = 0;
  int posicao_plagio = 0;

  if (palavras[0].tam_seq > palavras[1].tam_seq)
  {
    return -1;
  }

  letra *letra_palavra_01 = palavras[0].head;
  letra *letra_palavra_02 = palavras[1].head;

  while (letra_palavra_02 != NULL)
  {
    if (letra_palavra_02 != NULL && letra_palavra_02->l != letra_palavra_01->l)
    {
      letra_palavra_02 = letra_palavra_02->prox;
      posicao_plagio++;
      if (letra_palavra_02 == NULL || letra_palavra_02->prox == NULL)
      {
        return -1;
      }
    }
    else
    {
      controle = 1;
      letra *letra_palavra_01_temp = letra_palavra_01;

      int posicao_temp = posicao_plagio;
      while (letra_palavra_01_temp != NULL)
      {
        if (letra_palavra_01_temp->prox == NULL)
        {
          return posicao_temp;
        }

        if (letra_palavra_02 == NULL)
        {
          return -1;
        }

        controle = letra_palavra_02->l == letra_palavra_01_temp->l ? 1 : 0;

        if (controle == 0)
        {
          break;
        }

        letra_palavra_02 = letra_palavra_02->prox;
        posicao_plagio++;

        letra_palavra_01_temp = letra_palavra_01_temp->prox;
      }

      letra_palavra_01_temp = letra_palavra_01;
    }
  }

  return -1;
}

int main()
{

  sequencia *seqs;
  seqs = (sequencia *)malloc(sizeof(sequencia) * QTD_PALAVRAS);

  for (int i = 0; i < QTD_PALAVRAS; i++)
  {

    seqs[i].head = (letra *)malloc(sizeof(letra));
    seqs[i].tam_seq = 0;

    letra *letra_temp = (letra *)malloc(sizeof(letra));
    letra_temp->l = getchar();
    letra_temp->prox = NULL;

    seqs[i].head = letra_temp;

    while (letra_temp->l != ' ' && letra_temp->l != '\n')
    {
      seqs[i].tam_seq++;
      letra *temp = (letra *)malloc(sizeof(letra));
      temp->l = getchar();
      temp->prox = NULL;
      letra_temp->prox = temp;
      letra_temp = temp;
    }
  }

  int posicao_plagio = detecta_plagio(seqs);

  if (posicao_plagio < 0)
  {
    printf("Nenhum plagio detectado!\n");
  }
  else
  {
    printf("Plagio encontrado na posicao %i!\n", posicao_plagio);
  }
}
