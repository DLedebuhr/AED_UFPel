#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100

typedef struct Caixa{

    char nome [TAM];
    int idade;
    char email [TAM];
    struct Caixa * Proximo;

} Caixa;

typedef struct {

    Caixa * Topo;

} Pilha;

void Inicializar (Pilha * PILHA) {

    PILHA -> Topo = NULL;

}

void AdicionarPessoa (Pilha * PILHA, char n[TAM], int i, char e[TAM], int * Cont) {

    Caixa * Nova = (Caixa *) malloc (sizeof(Caixa));

    if (Nova == NULL) {

        printf("-- Erro ao alocar memoria!\n\n");
        return;

    }

    strcpy(Nova -> nome, n);
    Nova -> idade = i;
    strcpy(Nova -> email, e);

    Nova -> Proximo = PILHA -> Topo; 
    PILHA -> Topo = Nova;

    printf("-- Registro Adicionado com Sucesso!\n\n");

    (*Cont)++;

}

void RemoverPessoa (Pilha * PILHA, int * Cont) {

    if (PILHA -> Topo == NULL) {

        printf("-- A pilha esta vazia!\n\n");
        return;

    }

    Caixa * Removido = PILHA -> Topo;

    PILHA -> Topo = Removido -> Proximo;

    free (Removido);

    printf("-- Registro Removido com Sucesso!\n\n");

    (*Cont)--;

}

void Listar (Pilha * PILHA, int *Cont) {

    if (PILHA -> Topo == NULL) {

        printf("-- A pilha esta vazia!\n\n");
        return;

    }

    Caixa * Atual = PILHA -> Topo;

    printf("-- Agenda:\n\n");
  
    int i = *Cont;

    while (Atual != NULL) {

        i--;
        
        printf(" | Registro [%d]: \n", i);
        printf(" | Nome: %s\n", Atual -> nome);
        printf(" | Idade: %d\n", Atual -> idade);
        printf(" | Email: %s\n\n", Atual -> email);

        Atual = Atual -> Proximo;
    
    }

}

void Liberar (Pilha * PILHA, int * Cont) {

    while (PILHA -> Topo != NULL) {

        Caixa * Removido = PILHA -> Topo;

        PILHA -> Topo = Removido -> Proximo;

        free (Removido);

    }

    if (PILHA -> Topo == NULL) {

        printf("-- A pilha esta vazia!\n\n");
        return;

    }

    (*Cont) = 0;

}

int main () {

    Pilha PILHA;

    Inicializar(&PILHA);

    int Cont = 0;

    AdicionarPessoa(&PILHA, "D", 1, "DD", &Cont);
    AdicionarPessoa(&PILHA, "E", 1, "EE", &Cont);
    AdicionarPessoa(&PILHA, "F", 1, "FF", &Cont);

    Listar(&PILHA, &Cont);

    RemoverPessoa(&PILHA, &Cont);

    Listar(&PILHA, &Cont);

    AdicionarPessoa(&PILHA, "G", 1, "GG", &Cont);

    Listar(&PILHA, &Cont);

    Liberar(&PILHA, &Cont);

    Listar(&PILHA, &Cont);

    return 0;
    
}