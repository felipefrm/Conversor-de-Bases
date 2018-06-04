#include "convercoes.h"
#include <math.h>

int transforma_char(char num){        // FUNÇÕES

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

char transforma_int(int num){

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

int verifica_valor(char num[], int num_digitos){
  int tem_valor = 0;
  for (int i=1; i<num_digitos; i++){    //i=0 é o sinal.
    if(num[i] != '0'){
      tem_valor = 1;
    }
  }
  return tem_valor;
}

int verifica_sinal(char num[]){
  int tem_sinal = 1;
  if (num[0] != '+' && num[0] != '-'){
    tem_sinal = 0;
  }
  return tem_sinal;
}

int verifica_ponto(char num[], int num_digitos){
  int ponto = 0;
  for (int i=1; i < num_digitos; i++){
    if (num[i] == '.'){
      ponto = i;
      return ponto;
    }
  }
  return ponto;
}

int verifica_numero(char num[], int b_origem, int ponto, int num_digitos){

  int i, verif_num = 1;
  if (b_origem == 2){
    for (i=1; i<ponto; i++){
      if (num[i] < 48 || num[i] > 49){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if (num[i] < 48 || num[i] > 49){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == 8){
    for (i=1; i<ponto; i++){
      if (num[i] < 48 || num[i] > 55){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if (num[i] < 48 || num[i] > 55){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == 10){
    for (i=1; i<ponto; i++){
      if (num[i] < 48 || num[i] > 57){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if (num[i] < 48 || num[i] > 57){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == 16){
    for (i=1; i<ponto; i++){
      if ((num[i] < 48 || num[i] > 57) && (num[i] < 'A' || num[i] > 'F')){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if ((num[i] < 48 || num[i] > 57) && (num[i] < 'A' || num[i] > 'F')){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  return verif_num;
}

int verifica_origem(int b_origem){
  int verif_origem = 1;
  if (b_origem != 2 && b_origem != 8 && b_origem != 10 && b_origem != 16){
    verif_origem = 0;
  }
  return verif_origem;
}

int verifica_destino(int b_destino){
  int verif_destino = 1;
  if (b_destino != 2 && b_destino != 8 && b_destino != 10 && b_destino != 16){
    verif_destino = 0;
  }
  return verif_destino;
}

int recupera_inteiro(float n){
    int num = (int)n;
    return num;
}

float recupera_fracao(float n){
    float num;
    num = n - (int)n;
    return num;
}

int inteiro_para_baseX(unsigned long long int *inteira, int b_destino){
  int n;
  unsigned long long int p;
  n = *inteira % b_destino;
  p = *inteira;
  *inteira = p / b_destino;
  return n;
}

int fracao_para_baseX(float *fracionaria, int b_destino){
  int n;
  float p;
  p = *fracionaria * b_destino;
  n = recupera_inteiro(p);
  *fracionaria = recupera_fracao(p);
  return n;
}

unsigned long long int inteiro_para_base10(char num[], int b_origem, int ponto, int num_char[]){
  int i, expoente = ponto -2;  //desconsidera o PONTO e o SINAL.
  unsigned long long int soma = 0;
  for (i=1; i < ponto; i++){
    soma += num_char[i] * pow(b_origem, expoente);
    expoente--;
  }
  return soma;
}

float fracao_para_base10(char num[], int b_origem, int ponto, int digitos, int num_char[]){
  int i, expoente = -1;
  float soma=0;
  for (i = ponto+1; i < digitos; i++){
    soma += num_char[i] * pow(b_origem, expoente);
    expoente --;
  }
  return soma;
}
