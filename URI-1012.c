/*
    URI 1012
Escreva um programa que leia três valores com ponto flutuante de dupla precisão: A, B e C. Em seguida, calcule e mostre:
a) a área do triângulo retângulo que tem A por base e C por altura.
b) a área do círculo de raio C. (pi = 3.14159)
c) a área do trapézio que tem A e B por bases e C por altura.
d) a área do quadrado que tem lado B.
e) a área do retângulo que tem lados A e B.
Entrada
O arquivo de entrada contém três valores com um dígito após o ponto decimal.

Saída
O arquivo de saída deverá conter 5 linhas de dados. Cada linha corresponde a uma das áreas descritas acima, sempre com mensagem
correspondente e um espaço entre os dois pontos e o valor. O valor calculado deve ser apresentado com 3 dígitos após o ponto decimal.
*/
#include <stdio.h>

 typedef struct entrada
 {
     float a;
     float b;
     float c;
     
 }entrada;
 
float CalcularTriangulo(entrada);
float CalcularCirculo(entrada);
float CalcularTrapezio(entrada);
float CalcularQuadrado(entrada);
float CalcularRetangulo(entrada);

int main() {
    float triangulo = 0,
        circulo = 0,
        trapezio = 0,
        quadrado = 0,
        retangulo = 0;
    entrada dados;
    scanf("%f", &dados.a);
    scanf("%f", &dados.b);
    scanf("%f", &dados.c);
    
    triangulo = CalcularTriangulo(dados);
    circulo = CalcularCirculo(dados);
    trapezio = CalcularTrapezio(dados);
    quadrado = CalcularQuadrado(dados);
    retangulo = CalcularRetangulo(dados);
    printf("TRIANGULO: %0.3f\n", triangulo);
    printf("CIRCULO: %0.3f\n", circulo);
    printf("TRAPEZIO: %0.3f\n", trapezio);
    printf("QUADRADO: %0.3f\n", quadrado);
    printf("RETANGULO: %0.3f\n", retangulo);
 
    return 0;
}

float CalcularTriangulo(entrada dados)
{
    float resultado = 0;
    resultado = (dados.a * dados.c) / 2;
    return resultado;
}

float CalcularCirculo(entrada dados)
{
    float resultado = 0;
    resultado = (dados.c * dados.c) * 3.14159;
    return resultado;
}

float CalcularTrapezio(entrada dados)
{
    float resultado = 0;
    resultado = ((dados.a + dados.b) * dados.c) / 2;
    return resultado;
}

float CalcularQuadrado(entrada dados)
{
    float resultado = 0;
    resultado = dados.b * dados.b;
    return resultado;
}

float CalcularRetangulo(entrada dados)
{
    float resultado = 0;
    resultado = dados.a * dados.b;
    return resultado;
}