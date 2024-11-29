// 2. Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao dinamica de memoria. 
// Em seguida, leia do usuario seus valores e imprima o vetor lido

#include <stdio.h>
#include <stdlib.h>

int main () {

    int tamanho = 0;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *ponteiro;
    int i;

    ponteiro = (int *) malloc (tamanho * sizeof(int));

    printf("\nDigite %d numeros: \n\n", tamanho);

    for (i = 0; i < tamanho; i++) {

        printf("[%d] Numero: ", i);
        scanf("%d", &ponteiro[i]);

    }

    printf("\nVetor:");

    for (i = 0; i < tamanho; i++) {

        printf(" [%d]", ponteiro[i]);

    }

    printf("\n\n");

    free(ponteiro);

    return 0;

}