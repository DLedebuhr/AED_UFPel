// 3. Escreva um programa que contenha duas variaveis inteiras. 
// Leia essas variaveis do teclado. 
// Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.

#include <stdio.h>

int main () {

    int variavelA;
    int variavelB;

    printf("\nDigite o valor da variavel A: ");
    scanf("%d", &variavelA);

    printf("Digite o valor da variavel B: ");
    scanf("%d", &variavelB);

    printf("\nResultados: \n\n");

    if (&variavelA > &variavelB) {

        printf("Endereco de A > Endereco de B\n\n");
        printf("Conteudo de A: %d\n\n", variavelA);

    } else {

        printf("Endereco de A < Endereco de B\n\n");
        printf("Conteudo de B: %d\n\n", variavelB);

    }

    return 0;

}