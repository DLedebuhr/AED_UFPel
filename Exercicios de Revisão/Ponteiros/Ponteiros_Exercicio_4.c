// 4. Faca um programa que leia 2 valores inteiros 
// e chame uma funcao que receba estas 2 variaveis e troque o seu conteudo, ou seja, 
// esta funcao e chamada passando duas variaveis A e B por exemplo e, 
// apos a execucao da funcao, A conter a o valor de B e B tera o valor de A.

#include <stdio.h>

void TrocarValores (int *tempA, int *tempB);

int main () {

    int valorA;
    int valorB;

    printf("\nDigite o valor de A: ");
    scanf("%d", &valorA);

    printf("Digite o valor de B: ");
    scanf("%d", &valorB);

    TrocarValores (&valorA, &valorB);

    printf("\nDepois da troca:\n\n");

    printf("valor A: %d\n", valorA);

    printf("valor B: %d\n\n", valorB);

    return 0;

}

void TrocarValores (int *tempA, int *tempB) {

    int temp = *tempA;
    
    *tempA = *tempB;

    *tempB = temp;

}