// 2. Escreva um programa que contenha duas variaveis inteiras.
// Compare seus enderecos e exiba o maior endereco.

#include <stdio.h>

int main () {

    int variavelA;
    int variavelB;

    if (&variavelA > &variavelB) {

        printf("\nMaior Endereco: Variavel A\n\n");
        printf("Endereco de A: %p\n", &variavelA);
        printf("Endereco de B: %p\n\n", &variavelB);

    } else {

        printf("\nMaior Endereco: Variavel B\n\n");
        printf("Endereco de A: %p\n", &variavelA);
        printf("Endereco de B: %p\n\n", &variavelB);

    }

    return 0;

}