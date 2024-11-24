// 10. Crie um programa que contenha um array de inteiros contendo 5 elementos.
// Utilizando apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido

#include <stdio.h>

int main () {

    int array [5];
    int *ponteiro = array;
    int i;

    printf("\nDigite 5 valores\n\n");

    for (i = 0; i < 5; i++) {

        printf("[%d] | Elemento: ", i);
        scanf("%d", (ponteiro + i));

    }

    printf("\nResultados: \n\n");

    for (i = 0; i < 5; i++) {

        printf("Elemento - [%d] | Dobro - [%d]\n", *(ponteiro + i), (*(ponteiro + i) * 2));
        
    }

    printf("\n");

    return 0;

}