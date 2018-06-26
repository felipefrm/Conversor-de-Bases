#include "verificacoes.h"

int verificaValor(char *num, int num_digitos){
  int tem_valor = 0;
  for (int i=1; i<num_digitos; i++){    //i=0 é o sinal.
    if(*(num+i) != '0'){
      tem_valor = 1;
    }
  }
  return tem_valor;
}

int verificaSinal(char *num){
  int tem_sinal = 1;
  if (*(num+0) != '+' && *(num+0) != '-'){
    tem_sinal = 0;
  }
  return tem_sinal;
}

int verificaPonto(char *num, int num_digitos){
  int ponto = 0;
  for (int i=1; i < num_digitos; i++){
    if (*(num+i) == '.'){
      ponto = i;
      return ponto;
    }
  }
  return ponto;
}

int verificaNumero(char *num, char *numX, int j, int b_origem, int ponto, int num_digitos){
  int i, k, verif_num = 1;
  if (b_origem == 2){
    for (i=1; i<ponto; i++){
      if (*(num+i) < 48 || *(num+i) > 49){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if (*(num+i) < 48 || *(num+i) > 49){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == 8){
    for (i=1; i<ponto; i++){
      if (*(num+i) < 48 || *(num+i) > 55){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if (*(num+i) < 48 || *(num+i) > 55){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == 10){
    for (i=1; i<ponto; i++){
      if (*(num+i) < 48 || *(num+i) > 57){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if (*(num+i) < 48 || *(num+i) > 57){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == 16){
    for (i=1; i<ponto; i++){
      if ((*(num+i) < 48 || *(num+i) > 57) && (*(num+i) < 'A' || *(num+i) > 'F')){
        verif_num = 0;
        return verif_num;
      }
    }
    for (i=ponto+1; i<num_digitos; i++){
      if ((*(num+i) < 48 || *(num+i) > 57) && (*(num+i) < 'A' || *(num+i) > 'F')){
        verif_num = 0;
        return verif_num;
      }
    }
  }
  else if (b_origem == -1){
    verif_num = 0;
    for (i=1; i<ponto; i++){
      for (k=0; k<j; k+=2){
        if (*(num+i) == *(numX+k)){
          verif_num = 1;
          break;
        }
      }
      if (verif_num == 0)
        return verif_num;
    }
    verif_num = 0;
    for (i=ponto+1; i<num_digitos; i++){
      for (k=0; k<j; k+=2){
        if (*(num+i) == *(numX+k)){
          verif_num = 1;
          break;
        }
      }
      if (verif_num == 0)
        return verif_num;
    }
  }
  return verif_num;
}

int verificaOrigem(int b_origem){
  int verif_origem = 1;
  if (b_origem != 2 && b_origem != 8 && b_origem != 10 && b_origem != 16 && b_origem != -1){
    verif_origem = 0;
  }
  return verif_origem;
}

int verificaDestino(int b_destino){
  int verif_destino = 1;
  if (b_destino != 2 && b_destino != 8 && b_destino != 10 && b_destino != 16 && b_destino != -1){
    verif_destino = 0;
  }
  return verif_destino;
}
