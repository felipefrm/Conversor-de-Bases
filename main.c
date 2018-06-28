#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convercoes.h"
#include "verificacoes.h"

#define N 51

int main(void){

  char num[N], num_convert[N], numX[N];                 // Variavies necessárias
  int b_origem, b_destino, num_digitos, num_char[N], i, j, k, baseX;
  int ponto, tem_sinal, verif_origem, verif_destino, tem_valor, verif_num;
  double fracionaria;                                                //flags
  unsigned long long int inteira;

  FILE *arq_out;
  arq_out = fopen("arquivo_saida", "w");
  if (arq_out == NULL){
    fprintf(stderr, "Erro na abertura do arquivo.\n");
    exit(1);
  }

  FILE *arq_bX;
  arq_bX = fopen("arquivo_baseX", "r");
  if (arq_bX == NULL){
    fprintf(stderr, "Erro na abertura do arquivo.\n");
    exit(1);
  }
  for (j=0, baseX=0;; j++){
    *(numX+j) = fgetc(arq_bX);
    if (numX[j] == EOF)
      break;
    if (numX[j] == '\n')
      baseX++;
  }
  fclose(arq_bX);


  while (1){        // loop infinito para inserir as entradas e repeti-las apos
                   // cada conversão
                  // verificações de entrada feita por meio de funções com o auxilio de flags.

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

    verif_num = verificaNumero(num, numX, j, b_origem, ponto, num_digitos);
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

        if (b_origem == -1){
          inteira = intBaseXpara10(j, baseX, ponto, numX, num);
          fracionaria = fracBaseXpara10(j, baseX, ponto, numX, num);
        }

        else {

        for (i=1; i<num_digitos; i++)
          num_char[i] = transformaChar(num[i]);

        inteira = inteiroParaBase10(num, b_origem, ponto, num_char);
        fracionaria = fracaoParaBase10(num, b_origem, ponto, num_digitos, num_char);
        }



        if (b_destino == 10){

          if (fracionaria == 0)
            fprintf(arq_out, "%c%llu.\n", num[0], inteira);
          else
            fprintf(arq_out, "%c%g\n", num[0], inteira + fracionaria);
        }          //"%g" para remover os zeros a direita da fração.

        else {

          for (k = ponto -1;; k--){
            if (b_destino == -1)
              num_convert[k] = inteiroParaDestino(&inteira, baseX);
            else
              num_convert[k] = inteiroParaDestino(&inteira, b_destino);
            if (inteira == 0)
              break;
          }

          num_convert[ponto] = '.';
          for (i = ponto + 1;; i++){
            if (b_destino == -1)
              num_convert[i] = fracaoParaDestino(&fracionaria, baseX);
            else
              num_convert[i] = fracaoParaDestino(&fracionaria, b_destino);
            if (fracionaria == 0)
              break;
          }

          while (1){
            if (num_convert[i] != 0)
              break;
            i--;          // guarda a posição em que termina os 0's a direita
          }

          fputc(num[0], arq_out);   //imprime o sinal
          for (; k <= i; k++){
            if (b_destino == -1)
              fputc(transformaXint(num_convert[k], j, numX), arq_out);
            else
              fputc(transformaInt(num_convert[k]), arq_out);
          }
          fputc('\n', arq_out);
        }
      }
    }
  }
  fclose(arq_out);
}
