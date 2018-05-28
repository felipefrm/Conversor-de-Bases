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
  int b_atual, b_convert, num_digitos, expoente, inteira, i, j, k;
  int ponto, sinal, verif_atual, verif_bconvert, valor0, char_base;
  float fracionaria, n, soma = 0;
  
  while (1){

    sinal = ponto = verif_atual = verif_bconvert = valor0 = char_base = 0;
    setbuf(stdin, NULL);
    scanf("%50s%d%d", num, &b_atual, &b_convert);


    for (i=1; i<strlen(num); i++)         //i=0 é o sinal.
      if (num[i] != '0'){
        valor0 = 1;
      }

    if (num[0] == '+' && valor0 == 0 && b_atual == 0 && b_convert == 0)
      break;

    if (num[0] != '+' && num[0] != '-'){
      fprintf(stderr, "Por favor, insira o sinal antes do valor...\n");
      sinal = 1;
    }

    num_digitos = strlen(num);
    for (i=1; i < num_digitos; i++){
      if (num[i] == '.'){
        ponto = i;
        break;      // loop infinito para inserir as entradas e repeti-las caso
      }            // não estejam de acordo.
    }             // verificação feita com o auxilio de flags.

    if (ponto == 0)
      fprintf(stderr, "Por favor, insira o '.' separando a parte inteira da fracionária...\n");

    if (b_atual == 2){
      for (i=1; i<ponto; i++){
        if (num[i] < 48 || num[i] > 49){
          char_base = 1;
          break;
        }
      }
      for (i=ponto+1; i<num_digitos; i++){
        if (num[i] < 48 || num[i] > 49){
          char_base = 1;
          break;
        }
      }
    }
    else if (b_atual == 8){
      for (i=1; i<ponto; i++){
        if (num[i] < 48 || num[i] > 55){
          char_base = 1;
          break;
        }
      }
      for (i=ponto+1; i<num_digitos; i++){
        if (num[i] < 48 || num[i] > 55){
          char_base = 1;
          break;
        }
      }
    }
    else if (b_atual == 10){
      for (i=1; i<ponto; i++){
        if (num[i] < 48 || num[i] > 57){
          char_base = 1;
          break;
        }
      }
      for (i=ponto+1; i<num_digitos; i++){
        if (num[i] < 48 || num[i] > 57){
          char_base = 1;
          break;
        }
      }
    }
    else if (b_atual == 16){
      for (i=1; i<ponto; i++){
        if ((num[i] < 48 || num[i] > 57) && (num[i] < 'A' || num[i] > 'F')){
          char_base = 1;
          break;
        }
      }
      for (i=ponto+1; i<num_digitos; i++){
        if ((num[i] < 48 || num[i] > 57) && (num[i] < 'A' || num[i] > 'F')){
          char_base = 1;
          break;
        }
      }
    }

    if (char_base == 1)
      fprintf(stderr, "Este valor não pertence a base %d...\n", b_atual);

    if (b_atual != 2 && b_atual != 8 && b_atual != 10 && b_atual != 16){
      fprintf(stderr, "Digite novamente a base de origem...\n");
      verif_atual = 1;
    }

    if (b_convert != 2 && b_convert != 8 && b_convert != 10 && b_convert != 16){
      fprintf(stderr, "Digite novamente a base de destino...\n");
      verif_bconvert = 1;
    }

    if (sinal == 0 && verif_atual == 0 && verif_bconvert == 0 && char_base == 0 && valor0 == 1 && ponto != 0){

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
      

      if (b_convert == 10){
        if (fracionaria == 0)
          printf("%c%d.\n", num[0], inteira);
        else
          printf("%c%g\n", num[0], inteira + fracionaria);
      }          //"%g" para remover os zeros a direita, caso tenha fração.

      else {

        for (i = ponto -1;; i--){
          num_convert[i] = inteira % b_convert;
          inteira = inteira / b_convert;
          if (inteira == 0)
            break;
        }
        k = i;

        num_convert[ponto] = '.';
        for (i = ponto +1; fracionaria > 0; i++){
          n = fracionaria * b_convert;
          num_convert[i] = recupera_inteiro(n);
          fracionaria = recupera_fracao(n);
        }

        for (j=i;; j--)
          if (num_convert[j] != 0)
            break;        // guarda a posição em que termina os 0's a direita

        printf("%c", num[0]);   //imprime o sinal
        for (k; k <= j; k++){
          printf("%c", transforma_int(num_convert[k]));
        }
        printf("\n");
      }
    }
  }
}
