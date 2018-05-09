#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int num[9];
  int i, j, quant=0, somatorio=0, indice;
  printf("Digite o valor binario desejado para conversão: (digite qualquer valor diferente de 0 e 1 para parar.");
  for (i=0; i<9;i++){
      scanf("%d", &num[i]);
      if (num[i] == 0 || num[i] == 1){
        quant++;
      }
      else
        break;
  }
  indice = quant -1;
  for (indice; indice >=0; indice--){
      somatorio += num[indice]*(pow(2,indice));
  }
  printf("Quantd numeros: %d\n", quant);
  printf("%d\n", somatorio);
}
