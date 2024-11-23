// 7. Crie um programa que contenha uma funcao que permita passar por parametro dois numeros inteiros A e B. 
// A funcao devera calcular a soma entre estes dois numeros e armazenar o resultado na variavel A. 
// Esta funcao nao devera possuir retorno, mas devera modificar o valor do primeiro parametro. 
// Imprima os valores de A e B na funcao principal.

#include <stdio.h>

void CalcularSoma (int *numA, int *numB);

int main () {

    int valorA;
    int valorB;

    printf("\nDigite o valor de A: ");
    scanf("%d", &valorA);

    printf("Digite o valor de B: ");
    scanf("%d", &valorB);

    CalcularSoma (&valorA, &valorB);

    printf("\nDepois da Funcao:\n\n");

    printf("valor A: %d\n", valorA);

    printf("valor B: %d\n\n", valorB);

    return 0;

}

void CalcularSoma (int *numA, int *numB) {

    *numA = *numA + *numB;

}