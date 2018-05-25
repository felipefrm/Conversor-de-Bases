#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 51

int transforma_char(char num){

  if (num >= 48 && num <= 57)
    num = num - 48;
  if (num >= 'A' && num <= 'F'){
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
  }
  return num;
}

char transforma_int(int num){

  if (num >= 0 && num <= 9)
    num = num + 48;
  if (num >= 10 && num <= 15){
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
  }
  return num;
}

int main(void){

  char num[N], num_convert[N], nome_base[12];
  int b_atual, b_convert, num_digitos, i, j;
  int soma = 0, expoente, decimal, quociente;
  printf("Valor a ser convertido: ");
  setbuf(stdin, NULL);
  fgets(num, sizeof (num), stdin);
  num[strcspn(num, "\n")] = 0;
  num_digitos = strlen(num);

  do {
    printf("\nBase atual:\n[2]  BINÁRIO\n[8]  OCTAL\n[10] DECIMAL\n[16] HEXADECIMAL\n");
    printf(">>> ");
    scanf("%d", &b_atual);
  }
    while (b_atual != 2 && b_atual != 8 && b_atual != 10 && b_atual != 16);

  do {
    printf("\nBase futura:\n[2]  BINÁRIO\n[8]  OCTAL\n[10] DECIMAL\n[16] HEXADECIMAL\n");
    printf(">>> ");
    scanf("%d", &b_convert);
    }
    while (b_convert != 2 && b_convert != 8 && b_convert != 10 && b_convert != 16);


    expoente = num_digitos -1;
    for (i=0; i < num_digitos; i++){
      soma += transforma_char(num[i]) * pow(b_atual, expoente);
      expoente--;
    }
    decimal = soma;
  
  if (b_convert == 10)
    printf("Numero convertido para base 10: %d\n", decimal);

  else {

    quociente = decimal;
    for (i=0;; i++){
      num_convert[i] = quociente % b_convert;
      quociente = quociente / b_convert;
      if (quociente == 0){
        break;
      }
    }

    /*switch (b_convert) {
      case 2:
        nome_base[] = "bínaria";
        break;
      case 8:
        nome_base[] = "octal";
        break;
      case 16:
        nome_base[] = "hexadecimal";
        break;
    }*/
    printf("Número convertido para a base %d: ", b_convert);
    for (i; i>=0; i--){
      printf("%c", transforma_int(num_convert[i]));
    }
      printf("\n");
  }
}
