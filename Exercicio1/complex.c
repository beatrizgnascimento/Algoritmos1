#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

struct Complex
{
  float real;
  float imag;
};

//função pra criar o número complexo
Complex* complexNew(float real, float imag)
{
  Complex* num = (Complex*)malloc(sizeof(Complex));

  if(num != NULL)
  {
    num->real = real;
    num->imag = imag;
  }
  return num;
}

//função liberar número complexo
void complexFree(Complex* num)
{
  free(num);
}

//função para retornar os componentes do número complexo
int complexGet(Complex* num, float* real, float* imag)
{
  if(num == NULL)
  {
    return 0;
  }
  *real = num->real;
  *imag = num->imag;

  return 1;
}

//função para atribuir elementos do número complexo
int complexSet(Complex* num, float real, float imag)
{
  if(num == NULL)
  {
    return 0;
  }

  num->real = real;
  num-> imag = imag;

  return 1;
}

//função para imprimir
void complexPrint(Complex* num)
{
  printf("%.2f %.2f", num->real, num->imag);
}

//função para somar dois números complexos
Complex* complexAdd(Complex* n1, Complex* n2)
{
  Complex *result = (Complex*)malloc(sizeof(Complex));
  if(result != NULL)
  {
    result->real = n1->real + n2->real;
    result->imag = n1->imag + n2->imag;
  }
  return result;
}

//subtrai dois números complexos
Complex* complexSubtract(Complex* n1, Complex* n2)
{
  Complex *result = (Complex*)malloc(sizeof(Complex));
  if(result != NULL)
  {
    result->real = n1->real - n2->real;
    result->imag = n1->imag - n2->imag;
  }
  return result;
}

//multiplica dois números complexos
Complex* complexMultiply(Complex* n1, Complex* n2)
{
  Complex *result = (Complex*)malloc(sizeof(Complex));
  if(result != NULL)
  {
    result->real = n1->real * n2->real - n1->imag * n2->imag;
    result->imag = n1->real * n2->imag + n1->imag * n2->real;
  }
  return result;
}

//divide dois números complexos
Complex* complexDivide(Complex* n1, Complex* n2)
{
  Complex *result = (Complex*)malloc(sizeof(Complex));
  if(result != NULL)
  {
    float denominator = n2->real * n2->real + n2->imag * n2->imag;
    result->real = (n1->real * n2->real + n1->imag * n2->imag) / denominator;
    result->imag = (n1->real * n2->imag - n1->imag * n2->real) / denominator;
  }
  return result;
}
