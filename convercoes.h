#ifndef CONVERSAO
#define CONVERSAO

int transforma_char(char num);
char transforma_int(int num);
int verifica_valor(char num[], int num_digitos);
int verifica_sinal(char num[]);
int verifica_ponto(char num[], int num_digitos);
int verifica_numero(char num[], int b_origem, int ponto, int num_digitos);
int verifica_origem(int b_origem);
int verifica_destino(int b_destino);
int inteiro_para_baseX(unsigned long long int *inteira, int b_destino);
int fracao_para_baseX(float *fracionaria, int b_destino);
int recupera_inteiro(float n);
float recupera_fracao(float n);
int inteiro_para_base10(char num[], int b_origem, int ponto, int num_char[]);
float fracao_para_base10(char num[], int b_origem, int ponto, int digitos, int num_char[]);

#endif
