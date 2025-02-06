#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100

typedef struct Caixa {
    
    char nome[TAM];
    int idade;
    char email[TAM];

    struct Caixa *Proximo;

} Caixa;

typedef struct {

    Caixa *Frente;
    Caixa *Atras;

} Fila;

void Inicializar (Fila *FILA) {

    FILA -> Frente = NULL;
    FILA -> Atras = NULL;

}

void AdicionarPessoa (Fila *FILA, char n[TAM], int i, char e[TAM]) {

    Caixa *Nova = (Caixa *) malloc (sizeof(Caixa));

    if (Nova == NULL) {

        printf("Erro ao alocar memoria!\n\n");
        return;
        
    }

    strcpy (Nova -> nome, n);
    Nova -> idade = i;
    strcpy (Nova -> email, e);

    Nova -> Proximo = NULL;

    if (FILA -> Atras == NULL) {

        FILA -> Frente = Nova;
        FILA -> Atras = Nova;

    } else {

        FILA -> Atras -> Proximo = Nova;
        FILA -> Atras = Nova;

    }

    printf("-- Registro Adicionado com Sucesso!\n\n");

}

void RemoverPessoa (Fila *FILA) {

    if (FILA -> Frente == NULL) {

        printf("-- A Fila esta vazia!\n\n");
        return;

    }

    Caixa *Remover = FILA -> Frente;

    FILA -> Frente = FILA -> Frente -> Proximo;

    if (FILA -> Frente == NULL) {

        FILA -> Atras = NULL;

    }

    free (Remover);

    printf("-- Registro Removido com Sucesso!\n\n");

}

void Listar (Fila *FILA) {

    if (FILA -> Frente == NULL) {

        printf("-- A Fila esta vazia!\n\n");
        return;

    }

    Caixa *Atual = FILA -> Frente;

    int i = 1;  

    printf("-- Agenda:\n\n");
    
    while (Atual != NULL) {

        printf(" | Registro [%d]: \n", i);
        printf(" | Nome: %s\n", Atual -> nome);
        printf(" | Idade: %d\n", Atual -> idade);
        printf(" | Email: %s\n\n", Atual -> email);

        Atual = Atual -> Proximo;
        i++;

    }
}

void Liberar (Fila *FILA) {

    while (FILA -> Frente != NULL) {

        Caixa *Remover = FILA -> Frente;

        FILA -> Frente = FILA -> Frente -> Proximo;

        free(Remover);

    }

    FILA -> Atras = NULL;

    printf("-- Todos os registros foram removidos.\n\n");

}

int main() {

    Fila FILA;

    Inicializar(&FILA);

    AdicionarPessoa(&FILA, "D", 1, "DD");
    AdicionarPessoa(&FILA, "E", 1, "EE");
    AdicionarPessoa(&FILA, "F", 1, "FF");

    Listar(&FILA);

    RemoverPessoa(&FILA);

    Listar(&FILA);

    AdicionarPessoa(&FILA, "G", 1, "GG");

    Listar(&FILA);

    Liberar(&FILA);

    Listar(&FILA);

    return 0;

}
