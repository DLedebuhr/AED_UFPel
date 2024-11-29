// 12. Faca um programa que leia tres valores inteiros e chame uma funcao que receba estes 
// 3 valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel, 
// o segundo menor valor na variavel do meio, e o maior valor na ultima variavel. 
// A funcao deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. 
// Exibir os valores ordenados na tela.

#include <stdio.h>
#include <stdlib.h>

int OrdenarValores (int *valor1, int *valor2, int *valor3);

int main () {

    int valor1;
    int valor2;
    int valor3;
    int retorno = 0;

    printf("\nDigite o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);

    printf("Digite o terceiro valor: ");
    scanf("%d", &valor3);

    retorno = OrdenarValores (&valor1, &valor2, &valor3);

    if (retorno == 1) {

        printf("\nOs valores sao iguais.\n\n");

    } else {

        printf("\nValores ordenados: %d, %d, %d\n\n", valor1, valor2, valor3);

    }

    return 0;

}

int OrdenarValores (int *valor1, int *valor2, int *valor3) {

    int temp;
    int retorno;

    if ((*valor1 == *valor2) && (*valor1 == *valor3)) {

        retorno = 1;

    } else {

        if (*valor1 > *valor2) {

            temp = *valor1;
            *valor1 = *valor2;
            *valor2 = temp;

        }

        if (*valor1 > *valor3) {
        
            temp = *valor1;
            *valor1 = *valor3;
            *valor3 = temp;

        }

        if (*valor2 > *valor3) {
            
            temp = *valor2;
            *valor2 = *valor3;
            *valor3 = temp;

        }

        retorno = 0;

    }

    return (retorno);

}