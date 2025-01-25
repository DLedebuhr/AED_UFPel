// -- Bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -- Constantes

#define TAMANHO_NOME 100 
#define TAMANHO_EMAIL 100
#define TAMANHO_BUSCA 100
#define TAMANHO_BLOCO (TAMANHO_NOME + sizeof(int) + TAMANHO_EMAIL)

// -- Divisões do pBuffer

// *((int *) pBuffer)                                                                                   // ESCOLHA
// *((int *) pBuffer + 1)                                                                               // CONTADOR
// *((int *) pBuffer + 2)                                                                               // PRIMEIRA "CAIXINHA" AUXILIAR
// *((int *) pBuffer + 3)                                                                               // SEGUNDA "CAIXINHA" AUXILIAR
// ((char *) pBuffer + 4 * sizeof(int))                                                                 // PALAVRA PARA BUSCA
// ((char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA)                                                 // REGISTROS COMEÇAM APARTIR DAQUI
// ((char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 1) * TAMANHO_BLOCO)       // BLOCOS

// -- Funções

void adicionarPessoa(void **pBuffer);
void removerPessoa(void **pBuffer);
void buscarPessoa(void *pBuffer);
void listarTodos(void *pBuffer);

// -- Função Principal

int main() {

    void *pBuffer = malloc (4 * sizeof(int) + TAMANHO_BUSCA);

    if (!pBuffer) {

        printf ("Erro ao alocar memoria!\n");
        return -1;

    }

    *((int *) pBuffer) = 0;         // Escolha
    *((int *) pBuffer + 1) = 0;     // Contador
    *((int *) pBuffer + 2) = 0;     // Auxiliar de loops
    *((int *) pBuffer + 3) = 0;     // Auxiliar geral

    while (*((int *) pBuffer) != 5) {

        printf ("-- Menu:\n\n");

        printf ("\t (1) Adicionar Pessoa\n");
        printf ("\t (2) Remover Pessoa\n");
        printf ("\t (3) Buscar Pessoa\n");
        printf ("\t (4) Listar Todos\n");
        printf ("\t (5) Sair\n\n");

        printf ("-- Escolher: ");
        scanf ("%d", (int *) pBuffer);

        getchar ();

        printf("\n");

        switch (*((int *) pBuffer)) {
            
            case 1: 

                adicionarPessoa (&pBuffer);
                break;

            case 2: 

                removerPessoa (&pBuffer);
                break;

            case 3: 

                buscarPessoa (pBuffer);
                break;

            case 4: 

                listarTodos (pBuffer);
                break;

            case 5: 

                printf ("Programa Encerrado!\n\n");
                break;
        
            default:

                printf ("Escolha invalida!\n\n");
                break;

        }
    }

    free (pBuffer);

    return 0;

    // /ᐠ｡ꞈ｡ᐟ\ //

}

void adicionarPessoa (void **pBuffer) {

    void *novoBuffer = realloc (*pBuffer, 4 * sizeof(int) + TAMANHO_BUSCA + ((*((int *) *pBuffer + 1) + 1) * TAMANHO_BLOCO));
    
    if (!novoBuffer) {
        
        printf ("Erro ao alocar memoria!\n\n");
        return;
    
    }

    *pBuffer = novoBuffer;

    printf ("-- Novo Registro: \n\n");

    do {

        *((int *) pBuffer + 3) = 0;

        printf (" | Digite o nome para registro: ");

        fgets ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO), TAMANHO_NOME, stdin);
        
        ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO))
        [strcspn((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO), "\n")] = '\0';

        if (strlen(((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO))) == 0) {

            printf("\n-- Nome Invalido! Tente Novamente...\n\n");
            *((int *) pBuffer + 3) = 1;

        }

    } while (*((int *) pBuffer + 3) == 1);

    // --

    do {

        *((int *) pBuffer + 3) = 0;

        printf (" | Digite a idade para registro: ");

        scanf ("%d", (int *) ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO) + TAMANHO_NOME));
        
        getchar ();
        
        if ((*(int *) ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO) + TAMANHO_NOME)) < 0) {

            printf ("\n-- Idade Invalida! Tente Novamente...\n\n");
            *((int *) pBuffer + 3) = 1;

        }

    } while (*((int *) pBuffer + 3) == 1);
    
    // -- 

    do {

        *((int *) pBuffer + 3) = 0;

        printf(" | Digite o email para registro: ");

        fgets((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int), TAMANHO_EMAIL, stdin);

        ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int))
        [strcspn((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int), "\n")] = '\0';

        if (strlen((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int)) == 0) {

            printf("\n-- Email Invalido! Tente Novamente...\n\n");
            *((int *) pBuffer + 3) = 1;

        }

    } while (*((int *) pBuffer + 3) == 1);

    (*((int *) *pBuffer + 1))++;

    printf("\n");

}

void removerPessoa(void **pBuffer) {

    (*((int *) *pBuffer + 3)) = 0;

    if ((*((int *) *pBuffer + 1)) == 0) {

        printf ("-- A Agenda esta vazia!\n\n");
        return;

    }

    printf (" | Digite o nome para remover na Agenda: ");

    fgets (((char *) *pBuffer + 4 * sizeof(int)), TAMANHO_BUSCA, stdin);
    
    ((char *) *pBuffer + 4 * sizeof(int))[strcspn(((char *) *pBuffer + 4 * sizeof(int)), "\n")] = '\0';

    for (*((int *) *pBuffer + 2) = 0; *((int *) *pBuffer + 2) < *((int *) *pBuffer + 1); (*((int *) *pBuffer + 2))++) {

        if (strcmp(((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 2) * TAMANHO_BLOCO)), ((char *) *pBuffer + 4 * sizeof(int))) == 0) {

            printf ("\n-- Registro correspondente a [%s] encontrado com sucesso!\n", ((char *) *pBuffer + 4 * sizeof(int)));

            printf ("\nRegistro [%d]\n\n", *((int *) *pBuffer + 2));

            printf (" | Nome: %s\n", (char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 2) * TAMANHO_BLOCO));
            printf (" | Idade: %d\n", *((int *) ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 2) * TAMANHO_BLOCO) + TAMANHO_NOME)));
            printf (" | Email: %s\n", (char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 2) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int));

            (*((int *) *pBuffer + 3)) = 1;

            break;

        }

    } printf ("\n");

    if (!(*((int *) *pBuffer + 3))) {

        printf ("-- Nenhum registro encontrado para a busca [%s]!\n\n", ((char *) *pBuffer + 4 * sizeof(int)));
        return;

    }

    for ((*((int *) *pBuffer + 3)) = (*((int *) *pBuffer + 2)); (*((int *) *pBuffer + 3)) < (*((int *) *pBuffer + 1) - 1); (*((int *) *pBuffer + 3))++) {

        memcpy (((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + ((*((int *) *pBuffer + 3)) * TAMANHO_BLOCO)), ((char *) *pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + ((*((int *) *pBuffer + 3) + 1) * TAMANHO_BLOCO)), TAMANHO_BLOCO);

    }

    (*((int *) *pBuffer + 1))--;

    void *novoBuffer = realloc (*pBuffer, 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) *pBuffer + 1) * TAMANHO_BLOCO));
    
    if (!novoBuffer && (*((int *) *pBuffer + 1)) > 0) { 
        
        printf ("Erro ao alocar memoria!\n\n");
        return;

    }

    *pBuffer = novoBuffer;

    printf ("-- Registro removido com sucesso!\n\n");

}

void buscarPessoa (void *pBuffer) {

    (*((int *) pBuffer + 3)) = 0;

    if ((*((int *) pBuffer + 1)) == 0) {

        printf ("-- A Agenda esta vazia!\n\n");
        return;

    }

    printf (" | Digite o nome para buscar na Agenda: ");

    fgets (((char *) pBuffer + 4 * sizeof(int)), TAMANHO_BUSCA, stdin);
    
    ((char *) pBuffer + 4 * sizeof(int))[strcspn(((char *) pBuffer + 4 * sizeof(int)), "\n")] = '\0';

    for (*((int *) pBuffer + 2) = 0; *((int *) pBuffer + 2) < *((int *) pBuffer + 1); (*((int *) pBuffer + 2))++) {

        if (strcmp(((char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO)), ((char *) pBuffer + 4 * sizeof(int))) == 0) {

            printf ("\n-- Registro correspondente a [%s] encontrado com sucesso!\n\n", ((char *) pBuffer + 4 * sizeof(int)));

            printf ("Registro [%d]\n\n", *((int *) pBuffer + 2));

            printf (" | Nome: %s\n", (char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO));
            printf (" | Idade: %d\n", *((int *) ((char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO) + TAMANHO_NOME)));
            printf (" | Email: %s\n", (char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int));

            (*((int *) pBuffer + 3)) = 1;

            break;

        }

    } printf ("\n");

    if (!(*((int *) pBuffer + 3))) {

        printf ("-- Nenhum registro encontrado para a busca [%s]!\n\n", ((char *) pBuffer + 4 * sizeof(int)));
        return;

    }
}

void listarTodos (void *pBuffer) {

    if ((*((int *) pBuffer + 1)) == 0) {

        printf ("-- A Agenda esta vazia!\n\n");

    } else {

        printf("-- Listando...\n\n");

        for (*((int *) pBuffer + 2) = 0; *((int *) pBuffer + 2) < *((int *) pBuffer + 1); (*((int *) pBuffer + 2))++) {

            printf("Registro [%d]\n\n", *((int *) pBuffer + 2));

            printf(" | Nome: %s\n", (char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO));
            printf(" | Idade: %d\n", *((int *) ((char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO) + TAMANHO_NOME)));
            printf(" | Email: %s\n", (char *) pBuffer + 4 * sizeof(int) + TAMANHO_BUSCA + (*((int *) pBuffer + 2) * TAMANHO_BLOCO) + TAMANHO_NOME + sizeof(int));
        
        }

        printf("\n");

    }
}
