---
marp: true
title: Apresentação ED - Tomorrow
theme: default
paginate: true
---

<!-- markdownlint-disable MD025 MD033 MD003 MD024 -->

<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

<!-- header: "Universidade Federal da Bahia - Tomorrow" -->

<style>
footer {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 20px 20px 20px;
}

footer img {
  margin-left: 20px;
}

header {
  text-align: left;
  padding-left: 20px;
}
</style>

# Estrutura de Dados

## UFBA - Tomorrow

<b>Mauricio Souza Menezes</b>

---

## Visão Geral

Esta apresentação tem como objetivo apresentar o trabalho final desenvolvido no curso de capacitação em Estrutura de Dados.

A linguagem de programação utilizada foi o C.

---

## Objetivo e Descrição

O objetivo do trabalho é desenvolver um sistema de gerenciamento de estoque utilizando uma **Árvore Binária**.

Cada produto armazenado na árvore deve conter as seguintes informações:

- Nome
- Categoria
- Preço
- Quantidade em estoque
- Ponteiros para os filhos esquerdo e direito

---

## Funcionalidades

O sistema deve ser capaz de:

- Inserir um novo produto ordenando por nome (Implementado)
- Remover um produto (Não implementado)
- Buscar um produto pelo nome (Implementado)
- Valor total do estoque (Implementado)

---

## Implementação

---

## Estruturas Principais

```c
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
```

---

## Inserir Produto

### strcmp - Função que compara duas strings

1. Retorna 0 se as strings são iguais
2. Retorna um número negativo se a primeira string for menor que a segunda
3. Retorna um número positivo se a primeira string for maior que a segunda

---

## Inserir Produto

```c
if (arvore->raiz == NULL) {
arvore->raiz = produto;
}
```

---

## Inserir Produto

```c
else {
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

```

---

## Buscar Produto

```c
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
```

---

## Valor Total do Estoque

```c
float preco_total = 0;
  no* atual = raiz;

  while (atual != NULL) {
    return (atual->preco * atual->qtd_estoque) +
           calcula_preco_total(atual->esquerda) +
           calcula_preco_total(atual->direita);
  }

  return preco_total;
```

---

## Fim

Obrigado!
