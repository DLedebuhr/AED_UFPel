// 6. Elaborar um programa que leia dois valores inteiros (A e B). 
// Em seguida faca uma funcao que retorne a soma do dobro dos dois numeros lidos. 
// A funcao devera armazenar o dobro de A na propria variavel A e o dobro de B na propria variavel B. 

#include <stdio.h>

int DobrarValores (int *tempA, int *tempB);

int main () {

    int valorA;
    int valorB;
    int Retorno;

    printf("\nDigite o valor de A: ");
    scanf("%d", &valorA);

    printf("Digite o valor de B: ");
    scanf("%d", &valorB);

    Retorno = DobrarValores (&valorA, &valorB);

    printf("\nResultados: \n\n");

    printf("Dobro de A: %d\n", valorA);

    printf("Dobro de B: %d\n", valorB);

    printf("Soma do dobro: %d\n\n", Retorno);

    return 0;

}

int DobrarValores (int *tempA, int *tempB) {

    *tempA = *tempA * 2;

    *tempB = *tempB * 2;

    return (*tempA + *tempB);

}