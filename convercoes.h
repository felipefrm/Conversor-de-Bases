#ifndef CONVERSAO
#define CONVERSAO

int transformaXchar(char c, char *num, int k);
char transformaXint(char num, int j, char *numX);
int transformaChar(char num);
char transformaInt(int num);
unsigned long long int intBaseXpara10(int k, int baseX, int ponto, char *num, char *str);
double fracBaseXpara10(int k, int baseX, int ponto, char *num, char *str);
int inteiroParaDestino(unsigned long long int *inteira, int b_destino);
int fracaoParaDestino(double *fracionaria, int b_destino);
int recuperaInteiro(double n);
double recuperaFracao(double n);
unsigned long long int inteiroParaBase10(char *num, int b_origem, int ponto, int *num_char);
double fracaoParaBase10(char *num, int b_origem, int ponto, int digitos, int *num_char);

#endif
