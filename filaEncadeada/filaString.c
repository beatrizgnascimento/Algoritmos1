// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados
// descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filaString.h"

// criando elemento
struct elemento {
  char dado[5];
  struct elemento *prox;
};

// typedef do elemento
typedef struct elemento Elemento;

// criando nó descritor
struct descritor {
  Elemento *inicio;
  Elemento *fim;
  int quant;
};

// função para alocar memória do tipo Fila
FilaStr *criar_filaStr() {
  FilaStr *fi = (FilaStr *)malloc(sizeof(FilaStr));

  if (fi != NULL) {
    fi->inicio = NULL;
    fi->fim = NULL;
    fi->quant = 0;
  }
  return fi;
}

// função para liberar memória
int liberar_filaStr(FilaStr *fi) {

  if (fi == NULL) {
    return 0;
  }

  Elemento *atual;

  // percorre a fila a partir do início removendo os elementos
  while (fi->inicio != NULL) {
    atual = fi->inicio;

    fi->inicio = fi->inicio->prox;
    fi->quant--;

    free(atual);
  }

  free(fi);

  return 1;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elementoStr() { return (Elemento *)malloc(sizeof(Elemento)); }

// função para inserir elemento no final da fila
int enfileirarStr(FilaStr *fi, char *dado1) {
  if (fi == NULL) {
    return 0;
  }

  // cria um elemento novo
  Elemento *no;
  no = criar_elementoStr();

  if (no == NULL) {
    return 0;
  }

  // atribui valores ao elemento novo
  strcpy(no->dado, dado1);
  no->prox = NULL;

  // se a fila estiver vazia, insere no início da fila
  if (fi->inicio == NULL) {
    fi->inicio = no;

    // senão insere elemento no final da fila
  } else {
    (fi->fim)->prox = no;
  }

  fi->fim = no;
  fi->quant++;

  return 1;
}

// função para remover elemento do início da fila
char* desenfileirarStr(FilaStr *fi) {
  if (fi == NULL) {
    return NULL;
  }

  // fila vazia, não remove nada
  if (fi->inicio == NULL) {
    return NULL;
  }

  // remove elemento do início da fila
  Elemento *no;
  no = fi->inicio;
  char* valor = (char*)malloc(5);
  if(valor != NULL)
  {
    strcpy(valor, no->dado);
  }

  fi->inicio = fi->inicio->prox;
  fi->quant--;

  // libera Elemento no
  free(no);

  // se a fila ficou vazia
  if (fi->inicio == NULL) {
    fi->fim = NULL;
  }

  return valor;
}

// função para consultar o primeiro elemento
int consultar_inicio_filaStr(FilaStr *fi, char *dado) {
  // verifica se a fila foi criada corretamente e se não está vazia
  if (fi == NULL || fi->inicio == NULL) {
    return 0;
  }

  // copia o dado do início da fila
  strcpy(dado, fi->inicio->dado);

  return 1;
}

// função que devolve o tamanho da fila
int tamanho_filaStr(FilaStr *fi) {
  if (fi == NULL) {
    return -1;
  }
  return fi->quant;
}

int imprimir_filaStr(FilaStr *fi) {
  if (fi == NULL)
    return 0;
  if (fi->quant == 0)
    return 0;
  Elemento *no = fi->inicio;
  while (no != NULL) {
    printf("%s\n", no->dado);
    no = no->prox;
  }
  return 1;
}
