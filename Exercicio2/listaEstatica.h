#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include "produto.h"

typedef struct lista Lista;
//typedef struct produto produto;

Lista *criar_lista();
int liberar_lista(Lista **li);

//informações da lista
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);
int tamanho_lista(Lista *li);

//busca
int buscar_min_preco(Lista *li, produto **min_produto, float *preco, int *pos);
int buscar_pos(Lista *li, produto **resultado, int idx);
int buscar_produto_codigo(Lista *li, produto **resultado, int codigo, int *pos);

//inserção
int inserir_lista_final(Lista *li, produto *p);
int inserir_lista_inicio(Lista* li, produto *p);
int inserir_lista_meio(Lista* li, produto *p, int pos);

//remoção
int remover_ultimos_n(Lista *li, int n);
int remover_lista_final(Lista *li);
int remover_lista_inicio(Lista *li);
int remover_lista_meio(Lista *li, int pos);

int troca_elementos(Lista *li, int pos1, int pos2);

int imprimir_recursivo(Lista *li, int idx);

#endif