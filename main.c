#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "convercoes.h"
#include "verificacoes.h"

#define N 51

int main(void){

  char num[N], num_convert[N];                         // Variavies necessárias
  int b_origem, b_destino, num_digitos, num_char[N], i, k;
  int ponto, tem_sinal, verif_origem, verif_destino, tem_valor, verif_num;
  double fracionaria;                                                //flags
  unsigned long long int inteira;

  while (1){        // loop infinito para inserir as entradas e repeti-las caso
                   // não estejam de acordo.
                  // verificação feita por meio de funções com o auxilio de flags.

    setbuf(stdin, NULL);
    scanf("%s%d%d", num, &b_origem, &b_destino);
    num_digitos = strlen(num);

    tem_valor = verificaValor(num, num_digitos);
    if (num[0] == '+' && tem_valor == 0 && b_origem == 0 && b_destino == 0)
      break;

    if (num_digitos > 50)
      fprintf(stderr, "Insira um valor com menos de 50 dígitos...\n");

    tem_sinal = verificaSinal(num);
    if (tem_sinal == 0){
      fprintf(stderr, "Insira o sinal antes do valor...\n");
    }

    ponto = verificaPonto(num, num_digitos);
    if (ponto == 0){
      fprintf(stderr, "Insira o '.' separando a parte inteira da fração...\n");
    }

    verif_num = verificaNumero(num, b_origem, ponto, num_digitos);
    if (verif_num == 0)
      fprintf(stderr, "Este valor não pertence a base %d...\n", b_origem);

    verif_origem = verificaOrigem(b_origem);
    if (verif_origem == 0){
      fprintf(stderr, "Digite novamente a base de origem...\n");
    }

    verif_destino = verificaDestino(b_destino);
    if (verif_destino == 0){
      fprintf(stderr, "Digite novamente a base de destino...\n");
    }

    if(tem_sinal == 1 && verif_origem == 1 && verif_destino == 1){
      if (tem_valor == 1 && ponto != 0 && verif_num == 1 && num_digitos <= 50){

        for (i=1; i<num_digitos; i++)
          num_char[i] = transformaChar(num[i]);

        inteira = inteiroParaBase10(num, b_origem, ponto, num_char);
        fracionaria = fracaoParaBase10(num, b_origem, ponto, num_digitos, num_char);

        if (b_destino == 10){

          if (fracionaria == 0)
            printf("%c%llu.\n", num[0], inteira);
          else
            printf("%c%g\n", num[0], inteira + fracionaria);
        }          //"%g" para remover os zeros a direita da fração.

        else {

          for (i = ponto -1;; i--){
            num_convert[i] = inteiroParaBaseX(&inteira, b_destino);
            if (inteira == 0)
              break;
          }
          k = i;    // guarda o valor de i, pois precisará dele futuramente.

          num_convert[ponto] = '.';
          for (i = ponto + 1;; i++){
            num_convert[i] = fracaoParaBaseX(&fracionaria, b_destino);
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
            printf("%c", transformaInt(num_convert[k]));
          }
          printf("\n");
        }
      }
    }
  }
}
