// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados
// descomplicada em lingugem C (André Backes)"

#ifndef _FILA
#define _FILA

typedef struct descritor FilaInt;

// funções para alocar e desalocar memória
FilaInt *criar_filaInt();
int liberar_filaInt(FilaInt *fi);

// função para obter informação da fila
int tamanho_filaInt(FilaInt *fi);

// funções para enfileirar e desenfileirar elementos da fila
int enfileirarInt(FilaInt *fi, int dado);
int desenfileirarInt(FilaInt *fi);

// função para consultar elemento no início da fila
int consultar_inicio_filaInt(FilaInt *fi, int *dado);

int imprimir_filaInt(FilaInt *li);

#endif
