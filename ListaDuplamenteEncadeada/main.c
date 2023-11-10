/*************************************************************
# Lista Duplamente Encadeada

### Autores:
2023007113 Beatriz Guimarães do Nascimento
2023001577 João Henrique Flauzino
2023006887 Giovanna Xavier Silverio

https://repl.it/@HenriqueCastro1/Lista-Duplamente-Encadeada
***************************************************************/

#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Lista *li = alocarLista();
  if (li == NULL) {
    printf("Erro na alocação de lista");
    exit(0);
  }
  int opcao, res, codigo;
  Celula *cel;
  float preco;
  char validade[11], nome[256];


  do {
    printf("\n\n################# SISTEMA DE ESTOQUE #################");
    printf("\n 0 - Sair");
    printf("\n 1 - Inserir Produto");
    printf("\n 2 - Remover Produto por Código");
    printf("\n 3 - Imprimir Estoque");
    printf("\n 4 - Imprimir Produto por Código");
    printf("\n 5 - Abrir menu de produto");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {

    case 0:
      liberarLista(li);
      printf("\nFinalizando...\n\n");
      return 0;
      break;
    case 1:

      printf("Digite o nome do produto: ");
      scanf(" %255[^\n]", nome);

      printf("Digite o codigo do produto: ");
      scanf("%d", &codigo);

      printf("Digite o preco: ");
      scanf("%f", &preco);

      printf("Digite a validade do produto: ");
      scanf(" %10[^\n]", validade);

      res = inserirOrdemLista(li, nome, codigo, preco, validade);

      if (res == 1)
        printf("\nInsercao realizada com sucesso!");
      else
        printf("\nFalha na insercao!");

      break;
    case 2:
      printf("Digite o codigo do produto: \n");
      scanf("%d", &codigo);
      res = removerEspecifico(li, codigo);

      if (res == 1)
        printf("\nRemocao realizada com sucesso!");
      else
        printf("\nFalha na remocao, elemento nao encontrado!");

      break;
    case 3:
      imprimirLista(li);
      break;
    case 4:
      printf("Digite o codigo do produto: \n");
      scanf("%d", &codigo);
      res = buscaCelulaDado(li, codigo);

      if (res == 0)
        printf("\nElemento nao encontrado!");

      break;
    case 5:
      cel = primeiraCelula(li);
      while (opcao != 0) {
        printCelula(cel);
        printf("\n 0 - Sair | 3 - Remover Produto");
        printf("\n << Produto anterior: 2 | Próximo Produto: 1 >>");
        printf("\n\nOpção: ");

        scanf("%d", &opcao);
        switch (opcao) {
        case 0:
          
          break;
        case 1:
          if (proxCelula(cel) != NULL) {
            cel = proxCelula(cel);
          } else {
            printf("Último produto!");
          }
          break;

        case 2:
          if (antCelula(cel) != NULL) {
            cel = antCelula(cel);
          }else {
            printf("Primeiro produto!");
          }
            break;

        case 3:
            cel = removerCelula(cel, li);
            break;

        default:
          printf("\nOpção invalida!");
          break;
        }
      }
      opcao = 5;
      break;

    default:
      printf("\nOpcao invalida!");
      break;
    }
  } while (1 == 1);

  liberarLista(li);

  return 0;
}
