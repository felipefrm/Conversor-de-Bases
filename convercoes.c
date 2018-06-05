#include "convercoes.h"
#include <math.h>

int transformaChar(char num){        // FUNÇÕES

  if (num >= 48 && num <= 57)
    num = num - 48;

  switch(num){
    case 'A':
      num = 10;
      break;
    case 'B':
      num = 11;
      break;
    case 'C':
      num = 12;
      break;
    case 'D':
      num = 13;
      break;
    case 'E':
      num = 14;
      break;
    case 'F':
      num = 15;
      break;
  }
  return num;
}

char transformaInt(int num){

  if (num >= 0 && num <= 9)
    num = num + 48;

  switch(num){
    case 10:
      num = 'A';
      break;
    case 11:
      num = 'B';
      break;
    case 12:
      num = 'C';
      break;
    case 13:
      num = 'D';
      break;
    case 14:
      num = 'E';
      break;
    case 15:
      num = 'F';
      break;
  }
  return num;
}

int recuperaInteiro(double n){
    int num = (int)n;
    return num;
}

double recuperaFracao(double n){
    double num;
    num = n - (int)n;
    return num;
}

int inteiroParaBaseX(unsigned long long int *inteira, int b_destino){
  int n;
  unsigned long long int p;
  n = *inteira % b_destino;
  p = *inteira;
  *inteira = p / b_destino;
  return n;
}

int fracaoParaBaseX(double *fracionaria, int b_destino){
  int n;
  double p;
  p = *fracionaria * b_destino;
  n = recuperaInteiro(p);
  *fracionaria = recuperaFracao(p);
  return n;
}

unsigned long long int inteiroParaBase10(char num[], int b_origem, int ponto, int num_char[]){
  int i, expoente = ponto -2;  //desconsidera o PONTO e o SINAL.
  unsigned long long int soma = 0;
  for (i=1; i < ponto; i++){
    soma += num_char[i] * pow(b_origem, expoente);
    expoente--;
  }
  return soma;
}

double fracaoParaBase10(char num[], int b_origem, int ponto, int digitos, int num_char[]){
  int i, expoente = -1;
  double soma=0;
  for (i = ponto+1; i < digitos; i++){
    soma += num_char[i] * pow(b_origem, expoente);
    expoente --;
  }
  return soma;
}
