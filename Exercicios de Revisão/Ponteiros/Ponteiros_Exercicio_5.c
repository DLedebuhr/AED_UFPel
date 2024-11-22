// 5. Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes 2 valores de entrada 
// e retorne o maior valor na primeira variavel e o menor valor na segunda variavel. 
// Escreva o conteudo das 2 variaveis na tela.

#include <stdio.h>

void CompararValores (int *tempA, int *tempB);

int main () {

    int valorA;
    int valorB;

    printf("\nDigite o valor de A: ");
    scanf("%d", &valorA);

    printf("Digite o valor de B: ");
    scanf("%d", &valorB);

    CompararValores (&valorA, &valorB);

    printf("\nResultado:\n\n");

    printf("Maior valor: %d\n", valorA);

    printf("Menor valor: %d\n\n", valorB);

    printf("O maior valor foi armazenado em A e o menor em B.\n\n");

    return 0;

}

void CompararValores (int *tempA, int *tempB) {

    if (*tempA < *tempB) {

        int temp = *tempA;
        *tempA = *tempB;
        *tempB = temp;

    }

}