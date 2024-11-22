// 1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. 
// Associe as variaveis aos ponteiros (use &). 
// Modifique os valores de cada variavel usando os ponteiros. 
// Imprima os valores das variaveis antes e apos a modificacao.

#include <stdio.h>

int main () {

    int inteiro = 1;
    float real = 1.5;
    char caractere = 'D';

    int * ponteiroInt = &inteiro;
    float * ponteiroFloat = &real;
    char * ponteiroChar = &caractere;

    printf("\nAntes: \n\n");

    printf("Inteiro: %d \n", *ponteiroInt);
    printf("Real: %.1f \n", *ponteiroFloat);
    printf("Char: %c \n\n", *ponteiroChar);

    *ponteiroInt = 5;
    *ponteiroFloat = 5.5;
    *ponteiroChar = 'Y';

    printf("Depois: \n\n");

    printf("Inteiro: %d \n", *ponteiroInt);
    printf("Real: %.1f \n", *ponteiroFloat);
    printf("Char: %c \n\n", *ponteiroChar);

    return 0;

}