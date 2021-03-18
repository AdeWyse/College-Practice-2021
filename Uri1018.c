/*https://www.urionlinejudge.com.br/judge/en/problems/view/1018
In this problem you have to read an integer value and calculate the smallest possible
number of banknotes in which the value may be decomposed. The possible banknotes are 100, 50, 20,
10, 5, 2 e 1. Print the read value and the list of banknotes.

Input
The input file contains an integer value N (0 < N < 1000000).

Output
Print the read number and the minimum quantity of each necessary banknotes in Portuguese
language, as the given example. Do not forget to print the end of line after each line,
otherwise you will receive “Presentation Error”.*/

#include <stdio.h>

int main() {
    int valor, resto, notas100, notas50, notas20, notas10, notas5, notas2, notas1;
    scanf("%d", &valor);
    notas100 = valor/100;
    resto = valor%100;
    notas50 = resto/50;
    resto = resto%50;
    notas20 = resto/20;
    resto = resto%20;
    notas10 = resto/10;
    resto = resto%10;
    notas5 = resto/5;
    resto = resto%5;
    notas2 = resto/2;
    resto = resto%2;
    notas1 = resto;


    printf("%d\n", valor);
    printf( "%d nota (s) de R$ 100,00\n", notas100);
    printf( "%d nota (s) de R$ 50,00\n", notas50);
    printf( "%d nota (s) de R$ 20,00\n", notas20);
    printf( "%d nota (s) de R$ 10,00\n", notas10);
    printf( "%d nota (s) de R$ 5,00\n", notas5);
    printf( "%d nota (s) de R$ 2,00\n", notas2);
    printf( "%d nota (s) de R$ 1,00\n", notas1);

    return 0;
}
