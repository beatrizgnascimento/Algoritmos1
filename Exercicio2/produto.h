#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto produto;

produto *criar_produto(int codigo, char nome[30], float preco, int qtd);
void liberar_produto(produto *prdt);
void imprimir_produto(produto *prdt);

void set_produto_codigo(produto *prdt, int codigo);
int get_produto_codigo(produto *prdt);

void set_produto_nome(produto *prdt, char *nome);
char *get_produto_nome(produto *prdt);

void set_produto_preco(produto *prdt, float preco);
float get_produto_preco(produto *prdt);

void set_produto_quantidade(produto *prdt, int qtd);
int get_produto_quantidade(produto *prdt);

#endif