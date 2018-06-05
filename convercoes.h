#ifndef CONVERSAO
#define CONVERSAO

int transformaChar(char num);
char transformaInt(int num);
int inteiroParaBaseX(unsigned long long int *inteira, int b_destino);
int fracaoParaBaseX(double *fracionaria, int b_destino);
int recuperaInteiro(double n);
double recupera_fracao(double n);
unsigned long long int inteiroParaBase10(char num[], int b_origem, int ponto, int num_char[]);
double fracaoParaBase10(char num[], int b_origem, int ponto, int digitos, int num_char[]);

#endif
