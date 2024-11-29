// 1. Crie um programa que:
// (a) Aloque dinamicamente um array de 5 numeros inteiros,
// (b) Peca para o usuario digitar os 5 numeros no espaco alocado,
// (c) Mostre na tela os 5 numeros,
// (d) Libere a memoria alocada. 

#include <stdio.h>
#include <stdlib.h>

int main () {

    int *ponteiro;
    int i;

    ponteiro = (int *) malloc (5 * sizeof(int));

    printf("\nInforme 5 numeros: \n\n");

    for (i = 0; i < 5; i++) {

        printf("[%d] Numero: ", i);
        scanf("%d", &ponteiro[i]);

    }

    printf("\nVetor:");

    for (i = 0; i < 5; i++) {

        printf(" [%d]", ponteiro[i]);

    }

    printf("\n\n");
    
    free(ponteiro);

    return 0;

}