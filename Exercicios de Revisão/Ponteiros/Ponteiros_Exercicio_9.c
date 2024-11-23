// 9. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
// Imprima o endereco de cada posicao dessa matriz.

#include <stdio.h>

int main () {

    float matriz [3][3];
    int i, j;

    printf("\nMatriz de Enderecos: \n\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {

            printf("[%p] ", &matriz[i][j]);
    
        }

        printf("\n");
    
    }

    printf("\n");

    return 0;

}