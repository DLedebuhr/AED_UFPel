// 11. Crie um programa que contenha um array contendo 5 elementos inteiros. 
// Leia esse array do teclado e imprima o endereco das posicoes contendo valores pares.

#include <stdio.h>

int main () {

    int array [5];
    int i;

    printf("\nDigite 5 elementos: \n\n");

    for (i = 0; i < 5; i++) {

        printf("[%d] | Elemento: ", i);
        scanf("%d", &array[i]);

    }

    printf("\nEnderecos das posicoes contendo elementos pares:\n\n");

    for (i = 0; i < 5; i++) {

        if ((array[i] % 2) == 0) {

            printf("Elemento: %d | Endereco: %p\n", array[i], &array[i]);

        }
    }

    printf("\n");

    return 0;

}