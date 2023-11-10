#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct celula {
  struct celula *ant;
  produto *valor;
  struct celula *prox;
};

struct produto {
  int codigo;
  char nome[256];
  float preco;
  char validade[11];
};

produto *criarProduto(char nome[], int codigo, float preco, char validade[]) {
  produto *prod = malloc(sizeof(produto));
  if (prod == NULL) {
    return NULL;
  }
  prod->codigo = codigo;
  strcpy(prod->nome, nome);
  prod->preco = preco;
  strcpy(prod->validade, validade);

  return prod;
}

Celula *alocarCelula() {
  Celula *no = (Celula *)malloc(sizeof(Celula));

  return no;
}

Lista *alocarLista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));

  if (li != NULL)
    *li = NULL;

  return li;
}

int liberarLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  Celula *no;
  while (*li != NULL) // percorre os nos liberando o ultimo repetidamente
  {
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li); // libera a cabeca da lista

  return 1;
}

int inserirInicioLista(Lista *li, char nome[], int codigo, float preco,
                       char validade[]) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  produto *dado = criarProduto(nome, codigo, preco, validade);
  Celula *no = alocarCelula();

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  if (*li == NULL) // se lista vazia, insere no comeco
  {
    no->valor = dado;
    no->prox = no->ant = NULL;
    *li = no;
  } else // senão, cabeca aponta para novo no, novo no aponta para proximo no
  {
    no->valor = dado;
    no->ant = NULL;
    no->prox = *li;
    (*li)->ant = no;
    *li = no;
  }

  return 1;
}

int inserirFinalLista(Lista *li, char nome[], int codigo, float preco,
                      char validade[]) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  produto *dado = criarProduto(nome, codigo, preco, validade);
  Celula *no = alocarCelula();

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  if ((*li) == NULL) // se lista vazia, insere no inicio
  {
    no->valor = dado;
    no->prox = no->ant = NULL;
    *li = no;
  } else // se cheia, insere no final
  {
    Celula *aux;
    aux = *li;

    while (aux->prox != NULL) // percorre a lista ate o final
      aux = aux->prox;

    no->valor = dado;
    no->ant = aux;
    no->prox = NULL;
    aux->prox = no;
  }

  return 1;
}

int inserirOrdemLista(Lista *li, char nome[], int codigo, float preco,
                      char validade[]) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  produto *dado = criarProduto(nome, codigo, preco, validade);

  Celula *no = alocarCelula();

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  no->valor = dado;

  if ((*li) == NULL) // se lista vazia, insere no inicio
  {
    no->prox = NULL;
    no->ant = NULL;
    *li = no;
  } else // senao
  {
    Celula *anterior, *atual;
    atual = *li;

    while (atual != NULL && strcmp(atual->valor->nome, dado->nome) < 0) {
      anterior = atual;
      atual = atual->prox;
    }

    if (atual == (*li)) {
      no->ant = NULL;
      (*li)->ant = no;
      no->prox = (*li);
      *li = no;
    } else {
      no->prox = anterior->prox;
      no->ant = anterior;
      anterior->prox = no;
      if (atual != NULL) {
        atual->ant = no;
      }
    }
  }

  return 1;
}

int removerInicioLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL)
    return 0;

  Celula *atual;
  atual = *li;
  *li = atual->prox;

  if (atual->prox != NULL)
    atual->prox->ant = NULL;

  free(atual);

  return 1;
}

int removerFinalLista(Lista *li) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL)
    return 0;

  Celula *atual;
  atual = *li;

  while (atual->prox != NULL)
    atual = atual->prox;

  if (atual->ant == NULL)
    *li = atual->prox;
  else
    atual->ant->prox = NULL;

  free(atual);

  return 1;
}

int removerEspecifico(Lista *li, int codigo) {
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL)
    return 0;

  Celula *atual;
  atual = *li;

  while (atual != NULL && atual->valor->codigo != codigo)
    atual = atual->prox;

  if (atual == NULL)
    return 0;

  if (atual->ant == NULL)
    *li = atual->prox;
  else
    atual->ant->prox = atual->prox;

  if (atual->prox != NULL)
    atual->prox->ant = atual->ant;

  free(atual);
  return 1;
}

int buscaCelulaPosicao(Lista *li) {
  int pos;
  printf("\nPosição do elemento a ser buscado: ");
  scanf("%d", &pos);

  if (li == NULL || (*li) == NULL || pos <= 0)
    return 0;

  Celula *no = *li;
  int i = 1;

  while (no != NULL && i < pos) {
    no = no->prox;
    i++;
  }

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  printf("\nElemento da %dª posição: %d", pos, no->valor);

  return 1;
}

int buscaCelulaDado(Lista *li, int codigo) {
  if (li == NULL || (*li) == NULL)
    return 0;

  Celula *no = *li;
  int i = 1;

  if (no == NULL) // verifica se no foi criado corretamente
    return 0;

  while (no != NULL && no->valor->codigo != codigo) {
    no = no->prox;
    i++;
  }

  printf("\n---------------------------");
  printf("\nProduto: %s\nPreço: %f\nValidade: %s\n", no->valor->nome,
         no->valor->preco, no->valor->validade);
  printf("\n---------------------------");

  return 1;
}

int imprimirLista(Lista *li) {
  if (li == NULL || (*li) == NULL) {
    printf("\nLista não encontrada!");
    return 0;
  }

  printf("\nLISTA: ");

  Celula *aux = (*li);

  while (aux != NULL) {
    printf("\n---------------------------");
    printf("\nNome: %s", aux->valor->nome);
    printf("\nCodigo: %d ", aux->valor->codigo);
    printf("\nPreco: %.2f", aux->valor->preco);
    printf("\nValidade: %s", aux->valor->validade);
    printf("\n---------------------------");
    aux = aux->prox;
  }

  return 1;
}

Celula* primeiraCelula(Lista *li)
{
  return *li;
}

Celula* proxCelula(Celula *cel)
{
  return cel->prox;
}

Celula* antCelula(Celula *cel)
{
  return cel->ant;
}

int printCelula(Celula *celula)
{
    printf("\n---------------------------");
    printf("\nNome: %s", celula->valor->nome);
    printf("\nCodigo: %d ", celula->valor->codigo);
    printf("\nPreco: %.2f", celula->valor->preco);
    printf("\nValidade: %s", celula->valor->validade);
    printf("\n---------------------------");
}

Celula* removerCelula(Celula *celula, Lista *li)
{
  Celula *ret;
  if (celula == NULL)
    return 0;
  ret = celula->prox;
  if(ret == NULL)
  {
    ret = celula->ant;
  }
  
  if (celula->ant == NULL)
    *li = celula->prox;
  else
    celula->ant->prox = celula->prox;
    celula->prox->ant= celula->ant;

  if (celula->prox != NULL)
    celula->prox->ant = celula->ant;

  free(celula);
  return ret;
}
