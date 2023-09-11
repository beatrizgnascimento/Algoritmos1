#include "produto.h"
#include "string.h"
#include <stdlib.h>

#define NAME_LEN 64

struct produto {
  int codigo;
  char nome[NAME_LEN];
  float preco;
  int qtd;
};

produto* criar_produto(int codigo, char nome[NAME_LEN], float preco, int qtd)
{
  produto* prdt = (produto*)malloc(sizeof(produto));
  if(prdt == NULL)
  {
    return NULL;
  }
  prdt->codigo = codigo;
  strcpy(prdt->nome, nome);
  prdt->preco = preco;
  prdt->qtd = qtd;
  return prdt;
}
void liberar_produto(produto* prdt)
{
  if(prdt == NULL)
  {
    return;
  }
  free(prdt);
}

void imprimir_produto(produto* prdt)
{
  
  printf("\nCódigo: %d\n", get_produto_codigo(prdt));
  printf("Nome: %s\n", get_produto_nome(prdt));
  printf("Preço: %.2f\n", get_produto_preco(prdt));
  printf("Quantidade: %d\n", get_produto_quantidade(prdt));
  printf("\n");
}

void set_produto_codigo(produto* prdt, int codigo)
{
  if(prdt == NULL)
  {
    return;
  }
  prdt->codigo = codigo;
}
int get_produto_codigo(produto* prdt)
{
  if(prdt == NULL)
  {
    return -1;
  }
  return prdt->codigo;
}

void set_produto_nome(produto* prdt, char* nome)
{
  if(prdt == NULL)
  {
    return;
  }
  strcpy(prdt->nome, nome);
}
char* get_produto_nome(produto* prdt)
{ 
  if(prdt == NULL)
  {
    return NULL;
  }
  return prdt->nome;
}

void set_produto_preco(produto* prdt, float preco)
{
  if(prdt == NULL)
  {
    return;
  }
  prdt->preco = preco;
}
float get_produto_preco(produto* prdt)
{
  if(prdt == NULL)
  {
    return -1;
  }
  return prdt->preco;
}

void set_produto_quantidade(produto* prdt, int qtd)
{
  if(prdt == NULL)
  {
    return;
  }
  prdt->qtd = qtd;
}
int get_produto_quantidade(produto* prdt)
{
  if(prdt == NULL)
  {
    return -1;
  }
  return prdt->qtd;
}