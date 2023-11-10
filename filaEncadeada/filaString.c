// TAD para Fila Dinâmica Encadeada baseado no livro "Estrutura de dados
// descomplicada em lingugem C (André Backes)"

#ifndef _FILASTR
#define _FILASTR

typedef struct descritor FilaStr;

// funções para alocar e desalocar memória
FilaStr *criar_filaStr();
int liberar_filaStr(FilaStr *fi);

// função para obter informação da fila
int tamanho_filaStr(FilaStr *fi);

// funções para enfileirar e desenfileirar elementos da fila
int enfileirarStr(FilaStr *fi, char *dado1);
char* desenfileirarStr(FilaStr *fi);

// função para consultar elemento no início da fila
int consultar_inicio_filaStr(FilaStr *fi, char *dado);
int imprimir_filaStr(FilaStr *li);

#endif
