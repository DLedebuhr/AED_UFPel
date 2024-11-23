// 8. Crie um programa que contenha um array de float contendo 10 elementos.
// Imprima o endereco de cada posicao desse array.

#include <stdio.h>

int main () {

    float array [10];
    int i;

    printf("\n");
    
    for (i = 0; i < 10; i++) {

        printf("Indice [%d] - Endereco [%p]\n", i, &array[i]);
    
    }

    printf("\n");

    return 0;

}