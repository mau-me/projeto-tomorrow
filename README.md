# Projeto Tomorrow

## Índice

- [Projeto Tomorrow](#projeto-tomorrow)
  - [Índice](#índice)
  - [Sobre](#sobre)
  - [Estrutura do Projeto](#estrutura-do-projeto)
    - [Usando](#usando)
  - [Atividades](#atividades)

## Sobre

Repositório para armazenar os códigos e atividades realizados no projeto Tomorrow da UFBA (Universidade Federal da Bahia).

## Estrutura do Projeto

Para facilitar a organização do projeto, foi criado uma branch para cada atividade. As branches são nomeadas de acordo com a atividade que será realizada.

### Usando

Para clonar somente uma branch específica, utilize o comando abaixo:

```bash
git clone --single-branch --branch <branchname> <remote-repo>

```

Para versionar uma nova atividade, crie uma branch com o parâmetro --orphan, que cria uma branch sem histórico de commits.

```bash
git checkout --orphan <branchname>
```

Para enviar a branch para o repositório remoto, utilize o comando abaixo:

```bash
git push origin <branchname>
```

## Atividades

- [Curso de Capacitação em Estruturas de Dados](https://github.com/mau-me/projeto-tomorrow/tree/estruturas-de-dados)
