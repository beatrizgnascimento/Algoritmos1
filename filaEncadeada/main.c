//Beatriz Nascimento 2023007113
//João Henrique Flauzino 2023001577 
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// bibliotecas do projeto
#include "filaInt.h"
#include "filaString.h"

// funcao principal
int main(void) {

  int pref = 0;
  int n, i;
  int dado;
  int count = 0;
  int escolha = 0;
  int modo = 0;
  int countN = 0, countX = 0;
  char atendimento;
  char cliente;

  FilaInt *SE = criar_filaInt();
  FilaStr *XP = criar_filaStr();
  FilaStr *XC = criar_filaStr();
  FilaStr *NP = criar_filaStr();
  FilaStr *NC = criar_filaStr();

  printf("Digite o limite diário de atendimentos: ");
  scanf("%d", &n);
  for(i = 0; i <= n; i++)
  {
    enfileirarInt(SE, i);
  }

  srand(time(NULL));

  if (XP == NULL || XC == NULL || NP == NULL || NC == NULL) {
    return 0;
  }

  char senha[5];
  char* senhaChamada;

  do{
    printf("O que deseja fazer?\n  01 - Adicionar Senha\n  02 - Chamar fila\n  00 - Sair\nEscolha: ");
    scanf("%d", &escolha);
    if(escolha == 1)
    {
      if(tamanho_filaInt(SE) == 0)
      {
        printf("Limite excedido de senhas por hoje!!\n\n");
        continue;
      }
      int num_senha = desenfileirarInt(SE);

      senha[0] = '0';
      senha[1] = '0';
      senha[2] = (num_senha / 10) + '0';
      senha[3] = (num_senha % 10) + '0';
      senha[4] = '\0';

      printf("\n\nMenu de opções");
      printf("\nDefina o tipo de atendimento ");
      printf("\n(X) - Caixa\n(N) - Negocial");
      printf("\nOpção: ");
      scanf(" %c", &atendimento);
      printf("\nDigite o tipo de cliente: ");
      printf("\n(P) - Preferencial\n(C) - Convencional");
      printf("\nOpção: ");
      scanf(" %c", &cliente);
  
      atendimento = toupper(atendimento);
      cliente = toupper(cliente);
      
      senha[0] = atendimento;
      senha[1] = cliente;

      if (atendimento == 'X') {
        if (cliente == 'P') {
          enfileirarStr(XP, senha);
        } else {
          enfileirarStr(XC, senha);
        }
      } else if (atendimento == 'N') {
        if (cliente == 'P') {
          enfileirarStr(NP, senha);
        } else {
          enfileirarStr(NC, senha);
        }
      }

      printf("\nFila correspondente apos a adição da senha %s: \n", senha);
      if (atendimento == 'X') {
        if (cliente == 'P') {
          imprimir_filaStr(XP);
        } else {
          imprimir_filaStr(XC);
        }
      } else if (atendimento == 'N') {
        if (cliente == 'P') {
          imprimir_filaStr(NP);
        } else {
          imprimir_filaStr(NC);
        }
      }
    }
    else if(escolha == 2)
    {
      if(tamanho_filaStr(XP) == 0 && tamanho_filaStr(XC) == 0 && tamanho_filaStr(NP) == 0 && tamanho_filaStr(NC) == 0)
      {
        printf("Não há ninguém a ser chamado!!\n\n");
        continue;
      }
      if(count < 2 && (tamanho_filaStr(XP) > 0 || tamanho_filaStr(NP) > 0))
      {
        //atendimento preferencial
        modo = rand() % 2;
        if(tamanho_filaStr(XP) == 0) modo = 1;
        if(tamanho_filaStr(NP) == 0) modo = 0;
        if(modo == 0) //X
        {
          senhaChamada = desenfileirarStr(XP);
          printf("\nSenha chamada: %s\n", senhaChamada);
          countX++;
        }
        if(modo == 1) //N
        {
          senhaChamada = desenfileirarStr(NP);
          printf("\nSenha chamada: %s\n", senhaChamada);
          countN++;
        }
        count++;
      }
      else if(tamanho_filaStr(XC) > 0 || tamanho_filaStr(NC) > 0){
        count = 0;
        //atendimento comum
        modo = rand() % 2;
        if(tamanho_filaStr(XC) == 0) modo = 1;
        if(tamanho_filaStr(NC) == 0) modo = 0;
        if(modo == 0) //X
        {
          senhaChamada = desenfileirarStr(XC);
          printf("\nSenha chamada: %s\n", senhaChamada);
          countX++;
        }
        if(modo == 1) //N
        {
          senhaChamada = desenfileirarStr(NC);
          printf("\nSenha chamada: %s\n", senhaChamada);
          countN++;
        }
        count++;
      }
    }
  }
  while(escolha != 0);

  if(tamanho_filaStr(XP) > 0 || tamanho_filaStr(XC) > 0 || tamanho_filaStr(NP) > 0 || tamanho_filaStr(NC) > 0)
  {
    printf("Há filas que não foram totalmente chamadas. Deseja chamar o restante? (Sim = 1 | Não = 0)\n");
    scanf("%d",&escolha);
    while(tamanho_filaStr(XP) > 0 || tamanho_filaStr(XC) > 0 || tamanho_filaStr(NP) > 0 || tamanho_filaStr(NC) > 0)
      {
        if(count < 2 && (tamanho_filaStr(XP) > 0 || tamanho_filaStr(NP) > 0))
        {
          //atendimento preferencial
          modo = rand() % 2;
          if(tamanho_filaStr(XP) == 0) modo = 1;
          if(tamanho_filaStr(NP) == 0) modo = 0;
          if(modo == 0) //X
          {
            senhaChamada = desenfileirarStr(XP);
            printf("\nSenha chamada: %s\n", senhaChamada);
            countX++;
          }
          if(modo == 1) //N
          {
            senhaChamada = desenfileirarStr(NP);
            printf("\nSenha chamada: %s\n", senhaChamada);
            countN++;
          }
          count++;
        }
        else if(tamanho_filaStr(XC) > 0 || tamanho_filaStr(NC) > 0){
          //atendimento comum
          modo = rand() % 2;
          count = 0;
          if(tamanho_filaStr(XC) == 0) modo = 1;
          if(tamanho_filaStr(NC) == 0) modo = 0;
          if(modo == 0) //X
          {
            senhaChamada = desenfileirarStr(XC);
            printf("\nSenha chamada: %s\n", senhaChamada);
            countX++;
          }
          if(modo == 1) //N
          {
            senhaChamada = desenfileirarStr(NC);
            printf("\nSenha chamada: %s\n", senhaChamada);
            countN++;
          }
          count++;
        }
      }
  }
  if(tamanho_filaInt(SE) > 0)
  {
    printf("\nSenhas restantes : %d\n", tamanho_filaInt(SE));
  }

  printf("\n\nAtendimentos do caixa: %d\n", countX);
  printf("Atendimentos do negocial: %d\n", countN);
  
  liberar_filaInt(SE);
  liberar_filaStr(XP);
  liberar_filaStr(XC);
  liberar_filaStr(NP);
  liberar_filaStr(NC);

  return 0;
}
