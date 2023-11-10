#ifndef _MODULO
#define _MODULO

typedef struct produto produto;
typedef struct celula Celula;
typedef Celula *Lista;

//  gerenciamento
//produto* criarProduto(char nome[], int codigo, float preco, char validade[]);
Lista *alocarLista(void);
Celula *alocarCelula(void);
int liberarLista(Lista *li);

//  insercao
int inserirInicioLista(Lista *li, char nome[], int codigo, float preco, char validade[]);
int inserirFinalLista(Lista *li, char nome[], int codigo, float preco, char validade[]);
int inserirOrdemLista(Lista *li, char nome[], int codigo, float preco, char validade[]);

//  remocao
int removerInicioLista(Lista *li);
int removerFinalLista(Lista *li);
int removerEspecifico(Lista *li, int codigo);

//  consulta
int buscaCelulaPosicao(Lista *li);
int buscaCelulaDado(Lista *li, int codigo); //ja vai imprimir o produto

Celula* primeiraCelula(Lista *li);
Celula* proxCelula(Celula *cel);
Celula* antCelula(Celula *cel);
int printCelula(Celula *celula);
Celula* removerCelula(Celula *celula, Lista *li);

//  imprimir lista
int imprimirLista(Lista *li);

#endif
