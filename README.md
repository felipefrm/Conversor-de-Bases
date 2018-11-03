# Conversor de Bases

Conversor de Bases em C que realiza a conversão de números reais entre as bases binária, octal, decimal, hexadecimal e uma base *X* previamente criada pelo usuário em um arquivo de texto.

### Inicialização

1. Clone o repositório em um diretório específico.
```
$ git clone https://github.com/felipefrm/Conversor-de-Bases.git
$ cd cd/Conversor-de-Bases/
```

2. Compile o programa com o makefile.
```
& make
```

3. Execute-o sempre explicitando o arquivo da *base X* (mesmo que não fará nenhuma converso envolvendo-a) e o arquivo de saída onde sairá o resultado das conversões.
```
& ./conversor <nome do arquivo da base X> <nome do arquivo de saída>
```

### Formato de Entrada e Saída

O programa receberá como argumento o nome do arquivo ao ser executado. Além disso, ele deverá ler a entrada da entrada padrão (stdin) e gravar a saı́da em no arquivo especificado no segundo argumento do programa. Cada linha da **entrada é composta por uma tripla (N, B, T)** onde N é um número representado por uma sequência de dı́gitos do conjunto {{0-9} ∪ {A-F} ∪
{.,+,-}}, B é a base numérica de N, e por fim T é a base alvo para a qual deseja-se converter N.

Cada número N sempre começa com um sinal e sempre possui um ponto, mesmo quando não existe parte fracionária. O tamanho de N é, no máximo, 50 (|N | ≤ 50), incluindo o sinal e o ponto. Além disso, o número N não possui 0’s desnecessários (à esquerda antes do ponto ou à direita após o ponto). As bases B e T podem assumir os seguintes valores: 2 (binário), 8 (octal), 10 (decimal), 16 (hexadecimal), -1 (base X) e 0 (marcador especial para indicar o final da entrada). A **entrada** sempre **termina** com a **tripla (+0,0,0)** e, somente nesse caso, B e T terão valores 0’s.

### Exemplo

- Seja o arquivo que contém a base X com nome “arquivo_baseX” com o seguinte conteúdo:

```
A
H
C
D
```

- Executando o programa:

```
./tp arquivo_baseX saida
```

- Exemplo de Entrada (via stdin):

```
+AB.A 16 10
-101. 2 16
-32.5 10 8
-10. 10 10
+111.001 2 8
+HHA.D -1 10
-A.CD -1 10
+101.1 2 -1
+0 0 0
```

- Conteúdo no arquivo “saida”:

```
+171.625
-5.
-40.4
-10.
+7.1
+20.75
-0.6875
+HH.C
```

Algortimo desenvolvido por **Felipe Melo**.
