#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 51

int transforma_char(char num);

char transforma_int(int num);

int verifica_valor(char num[], int num_digitos);

int verifica_sinal(char num[]);

int verifica_ponto(char num[], int num_digitos);

int verifica_numero(char num[], int b_origem, int ponto, int num_digitos);

int verifica_origem(int b_origem);

int verifica_destino(int b_destino);

int inteiro_para_baseX(int *inteira, int b_destino);

int fracao_para_baseX(float *fracionaria, int b_destino);

int recupera_inteiro(float n);

float recupera_fracao(float n);

int inteiro_para_base10(char num[], int b_origem, int ponto, int num_char[]);

float fracao_para_base10(char num[], int b_origem, int ponto, int digitos, int num_char[]);


int main(void){

  char num[N], num_convert[N];
  int b_origem, b_destino, num_digitos, inteira, num_char[N], i, k;
  int ponto, tem_sinal, verif_origem=1, verif_destino=1, tem_valor, verif_num; //flags
  float fracionaria, n;

  while (1){        // loop infinito para inserir as entradas e repeti-las caso
                   // não estejam de acordo.
                  // verificação feita por meio de funções com o auxilio de flags.

    setbuf(stdin, NULL);
    scanf("%50s%d%d", num, &b_origem, &b_destino);
    num_digitos = strlen(num);

    tem_valor = verifica_valor(num, num_digitos);
    if (num[0] == '+' && tem_valor == 0 && b_origem == 0 && b_destino == 0)
      break;

    tem_sinal = verifica_sinal(num);
    if (tem_sinal == 0){
      fprintf(stderr, "Insira o sinal antes do valor...\n");
    }

    ponto = verifica_ponto(num, num_digitos);
    if (ponto == 0){
      fprintf(stderr, "Insira o '.' separando a parte inteira da fracão...\n");
    }

    verif_num = verifica_numero(num, b_origem, ponto, num_digitos);
    if (verif_num == 0)
      fprintf(stderr, "Este valor não pertence a base %d...\n", b_origem);

    verif_origem = verifica_origem(b_origem);
    if (verif_origem == 0){
      fprintf(stderr, "Digite novamente a base de origem...\n");
    }

    verif_destino = verifica_destino(b_destino);
    if (verif_destino == 0){
      fprintf(stderr, "Digite novamente a base de destino...\n");
    }

    if(tem_sinal == 1 && verif_origem == 1 && verif_destino == 1){
      if (tem_valor == 1 && ponto != 0 && verif_num == 1){

        for (i=1; i<num_digitos; i++)
          num_char[i] = transforma_char(num[i]);

        inteira = inteiro_para_base10(num, b_origem, ponto, num_char);
        fracionaria = fracao_para_base10(num, b_origem, ponto, num_digitos, num_char);

        if (b_destino == 10){

          if (fracionaria == 0)
            printf("%c%d.\n", num[0], inteira);
          else
            printf("%c%g\n", num[0], inteira + fracionaria);
        }          //"%g" para remover os zeros a direita da fração.

        else {

          for (i = ponto -1;; i--){
            num_convert[i] = inteiro_para_baseX(&inteira, b_destino);
            if (inteira == 0)
              break;
          }
          k = i;    // guarda o valor de i, pois precisará dele futuramente.

          num_convert[ponto] = '.';
          for (i = ponto + 1;; i++){
            num_convert[i] = fracao_para_baseX(&fracionaria, b_destino);
            if (fracionaria == 0)
              break;
          }

          while (1){
            if (num_convert[i] != 0)
              break;
            i--;          // guarda a posição em que termina os 0's a direita
          }

          printf("%c", num[0]);   //imprime o sinal
          for (; k <= i; k++){
            printf("%c", transforma_int(num_convert[k]));
          }
          printf("\n");
        }
      }
    }
  }
}

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

int inteiro_para_baseX(int *inteira, int b_destino){
  int n;
  n = *inteira % b_destino;
  *inteira = *inteira / b_destino;
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

int inteiro_para_base10(char num[], int b_origem, int ponto, int num_char[]){
  int i, soma = 0, expoente = ponto -2;  //desconsidera o PONTO e o SINAL.
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
