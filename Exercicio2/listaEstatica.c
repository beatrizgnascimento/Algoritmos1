#include "listaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct lista {
  int qtd;
  produto* dados[MAX];
};

// cria uma nova lista
Lista *criar_lista() {
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL) {
    li->qtd = 0;
  }
  return li;
}

int liberar_lista(Lista **li) {
  if (*li == NULL) {
    return 0;
  }

  free(*li);
  *li = NULL;

  return 1;
}

// verifica se a lista está vazia
int lista_vazia(Lista *li) {
  if (li == NULL) {
    return -1;
  }
  if (li->qtd == 0) {
    return 1;
  }
  return 0;
}

// verific se a lista está cheia
int lista_cheia(Lista *li) {
  if (li == NULL) {
    return -1;
  }
  if (li->qtd == MAX) {
    return 1;
  }
  return 0;
}

int tamanho_lista(Lista *li){
  if(li == NULL)
  {
    return -1;
  }
  else{
    return li->qtd;
  }
}

int buscar_min_preco(Lista *li, produto **min_produto, float *preco, int *pos) {
  if (li == NULL || lista_vazia(li)) {
    return 0;
  }

  *min_produto = li->dados[0]; // supondo que o primeiro elemento seja o mínimo inicial

  for (int i = 0; i < li->qtd; i++) {
    if (get_produto_preco(li->dados[i]) < get_produto_preco(*min_produto)) {
      *min_produto = li->dados[i];
      *pos = i;
      *preco = get_produto_preco(*min_produto);
    }
  }
  
  return 1;
}

int buscar_pos(Lista *li, produto **resultado, int idx)
{
  if(li == NULL || idx >= li->qtd) return 0;
  *resultado = li->dados[idx];
  return 1;
}

int buscar_produto_codigo(Lista *li, produto **resultado, int codigo, int *pos)
{
  if(li == NULL || pos >= li->qtd) return 0;
  int i;
  for(i = 0; i < li->qtd; i++)
  {
    if(get_produto_codigo(li->dados[i]) == codigo)
    {
      *resultado = li->dados[i];
      *pos = i;
      return 1;
    }
  }
  return 0;
}

int inserir_lista_final(Lista *li, produto *p) {
  if (li == NULL || lista_cheia(li)) {
    return 0;
  }
  li->dados[li->qtd] = p;
  li->qtd++;
  return 1;
}

int inserir_lista_inicio(Lista* li, produto *p){
  if (li == NULL || lista_cheia(li)) {
    return 0;
  }
  int i;
  for(i = li->qtd-1; i >= 0; i--)
  {
    li->dados[i+1] = li->dados[i];    
  }
  li->dados[0] = p;
  li->qtd++;
  return 1;
}

int inserir_lista_meio(Lista* li, produto *p, int pos){
  if (li == NULL || lista_cheia(li)) {
    return 0;
  }
  int i;
  for(i = li->qtd-1; i >= pos; i--)
  {
    li->dados[i+1] = li->dados[i];    
  }
  li->dados[pos] = p;
  li->qtd++;
  return 1;
}

int remover_ultimos_n(Lista *li, int n) {
  if (li == NULL || n <= 0) {
    return 0;
  }
  if (n >= li->qtd) {
    li->qtd = 0;
  } else {
    li->qtd -= n;
  }

  for (int i = 0; i < li->qtd; i++) {
    li->dados[i] = li->dados[i + n];
  }
  return 1;
}

int remover_lista_final(Lista *li) {
  if (li == NULL || lista_vazia(li)) {
    return 0;
  }
  li->qtd--;
  return 1;
}

int remover_lista_inicio(Lista* li){
  if (li == NULL || lista_vazia(li)) {
    return 0;
  }
  int i;
  for(i = 0; i < li->qtd-1; i++)
  {
    li->dados[i] = li->dados[i+1];    
  }
  li->qtd--;
  return 1;
}

int remover_lista_meio(Lista* li, int pos){
  if (li == NULL || lista_vazia(li)) {
    return 0;
  }
  int i;
  for(i = pos; i < li->qtd; i++)
  {
    li->dados[i] = li->dados[i+1];    
  }
  li->qtd--;
  return 1;
}

int troca_elementos(Lista *li, int pos1, int pos2) {
  if (li == NULL || lista_vazia(li) || pos1 < 0 || pos2 < 0 ||
      pos1 >= li->qtd || pos2 >= li->qtd) {
    return 0;
  }

  produto *temp = li->dados[pos1]; // armazena temporariamente
  li->dados[pos1] = li->dados[pos2];
  li->dados[pos2] = temp;

  return 1;
}

int imprimir_recursivo(Lista *li, int idx) {
  if(li == NULL) return 0; 
  if (idx < 0 || idx >= li->qtd) {
    return 1;
  }
  printf("Produto #%d:\n", idx);
  imprimir_produto(li->dados[idx]);
  return imprimir_recursivo(li, idx+1);
}