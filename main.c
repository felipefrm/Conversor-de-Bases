#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 51

int transforma_char(char num){

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

int recupera_inteiro(float n){
  int num = (int)n;
  return num;
}

float recupera_fracao(float n){
  float num;
  num = n - (int)n;
  return num;
}

int main(void){

  char num[N], num_convert[N];
  int b_atual, b_convert, num_digitos, i, k;
  int expoente, inteira, ponto=0, flag1, flag2, flag3, flag4;
  float fracionaria, soma = 0, n;

  while (1){

    printf("\nValor - Base Origem (2, 8, 10 ou 16) - Base Destino (2, 8, 10 ou 16)\n");
    printf(">>> ");
    setbuf(stdin, NULL);
    scanf("%50s%d%d", num, &b_atual, &b_convert);

    flag1 = 0;
    if (num[0] != '+' && num[0] != '-'){
      printf("Por favor, insira o sinal antes do valor...\n");
      flag1 = 1;
    }

    num_digitos = strlen(num);
    flag2 = 1;
    for (i=1; i < num_digitos; i++){
      if (num[i] == '.'){
        ponto = i;
        flag2 = 0;
        break;           // loop infinito para inserir as entradas e repeti-las
      }                 // caso não esteja de acordo.
    }                  // verificação feita com o auxilio de flags.

    if (flag2 == 1)
      printf("Por favor, insira o '.' separando a parte inteira da fracionária...\n");

    flag3 = 0;
    if (b_atual != 2 && b_atual != 8 && b_atual != 10 && b_atual != 16){
      printf("Digite novamente a base de origem...\n");
      flag3 = 1;
    }

    flag4 =0;
    if (b_convert != 2 && b_convert != 8 && b_convert != 10 && b_convert != 16){
      printf("Digite novamente a base de destino...\n");
      flag4 = 1;
    }

    if (flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0)
      break;
  }

  expoente = ponto -2;              //desconsidera o PONTO e o SINAL.
  for (i=1; i < ponto; i++){
    soma += transforma_char(num[i]) * pow(b_atual, expoente);
    expoente--;
  }
  inteira = soma;


  soma = 0;
  expoente = -1;
  for (i = ponto + 1; i < num_digitos; i++){
    soma += transforma_char(num[i]) * pow(b_atual, expoente);
    expoente --;
  }
  fracionaria = soma;


  if (b_convert == 10)
    printf("%c%g\n", num[0], inteira + fracionaria);

  else {

    for (i = ponto -1;; i--){
      num_convert[i] = inteira % b_convert;
      inteira = inteira / b_convert;
      if (inteira == 0){
        break;
      }
    }
    k = i;

    num_convert[ponto] = '.';
    for (i = ponto +1; fracionaria > 0; i++){
      n = fracionaria * b_convert;
      num_convert[i] = recupera_inteiro(n);
      fracionaria = recupera_fracao(n);
    }

    printf("%c", num[0]);   //imprime o sinal
    for (k; k <= i; k++){
      printf("%c", transforma_int(num_convert[k]));
    }
    printf("\n");
  }
}
