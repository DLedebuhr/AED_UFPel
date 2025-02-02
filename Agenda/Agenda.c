// -- Bibliotecas

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -- Constantes

#define TAM_BUSCA 50
#define TAM_NOME 50
#define TAM_IDADE sizeof(int)
#define TAM_EMAIL 100

// // -- Divisão do pBuffer

// // -- Controles

// *((int *) pBuffer)      // ESCOLHA
// *((int *) pBuffer + 1)  // CONTADOR
// *((int *) pBuffer + 2)  // AUXILIAR 1
// *((int *) pBuffer + 3)  // AUXILIAR 2
// *((int *) pBuffer + 4)  // TAM_REGISTROS

// // -- Temporarios 

// ((char *) pBuffer + 5 * sizeof(int))                                        // TEMP_BUSCA
// ((char *) pBuffer + 5 * sizeof(int) + TAM_BUSCA)                            // TEMP_NOME
// ((char *) pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME)                 // TEMP_IDADE
// ((char *) pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE)     // TEMP_EMAIL

// // -- Registros

// ((char *) pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL)     // REGISTROS 

// REGISTROS + sizeof(int) + NOME + IDADE + EMAIL + sizeof(int) + NOME + IDADE + EMAIL...

// --

// [ESCOLHA] [CONTADOR] [AUXILIAR_1] [AUXILIAR_2] [TAM_REGISTROS] [TAM_BUSCA] [TAM_NOME] [TAM_IDADE] [TAM_EMAIL] [TAM_BLOCO][[NOME][IDADE][EMAIL]] [TAM_BLOCO][[NOME][IDADE][EMAIL]]...

// -- Funções

void AdicionarPessoa (void **pBuffer);
void RemoverPessoa (void **pBuffer);
void BuscarPessoa (void *pBuffer);
void ListarTodos (void *pBuffer);

// -- Função Principal

int main () {

    printf("-- Agenda\n\n");

    void * pBuffer = malloc (5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL);

    if (!pBuffer) {

        printf("-- Erro ao alocar memoria para o pBuffer!\n\n");
        exit(1);

    }

    *((int *) pBuffer) = 0;         // Escolha
    *((int *) pBuffer + 1) = 0;     // Contador
    *((int *) pBuffer + 2) = 0;     // Auxiliar de loops
    *((int *) pBuffer + 3) = 0;     // Auxiliar geral
    *((int *) pBuffer + 4) = 0;     // Auxiliar geral
    
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

        printf ("\n");

        switch (*((int *) pBuffer)) {
            
            case 1: 

                AdicionarPessoa (&pBuffer);
                break;

            case 2: 

                RemoverPessoa (&pBuffer);
                break;

            case 3: 

                BuscarPessoa (pBuffer);
                break;

            case 4: 

                ListarTodos (pBuffer);
                break;

            case 5: 

                printf ("-- Programa Encerrado!\n\n");
                break;
        
            default:

                printf ("-- Escolha invalida!\n\n");
                break;

        }
    }

    free (pBuffer);

    pBuffer = NULL;

    return 0;

    // /ᐠ｡ꞈ｡ᐟ\ //

}

void AdicionarPessoa (void **pBuffer) {

    printf ("-- Novo Registro: \n\n");

    do {

        *((int *) *pBuffer + 3) = 0;

        printf (" | Digite o nome para registro: ");

        fgets (((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA), TAM_NOME, stdin);

        ((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA)[strcspn(((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA), "\n")] = '\0';

        if (strlen((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA) == 0) {

            printf ("\n-- Nome Invalido! Tente Novamente...\n\n");
            *((int *) *pBuffer + 3) = 1;

        }

    } while (*((int *) *pBuffer + 3) == 1); 

    // --

    do {

        *((int *) *pBuffer + 3) = 0;

        printf (" | Digite a idade para registro: ");

        scanf ("%d", (int *)((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME));

        getchar ();

        if ((*(int *)((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME)) < 0) {

            printf ("\n-- Idade Invalida! Tente Novamente...\n\n");
            *((int *) *pBuffer + 3) = 1;

        }

    } while (*((int *) *pBuffer + 3) == 1);
    
    // -- 

    do {

        *((int *) *pBuffer + 3) = 0;

        printf (" | Digite o email para registro: ");

        fgets (((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE), TAM_EMAIL, stdin);

        ((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE)[strcspn(((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE), "\n")] = '\0';

        if (strlen((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE) == 0) {

            printf("\n-- Email Invalido! Tente Novamente...\n\n");
            *((int *) *pBuffer + 3) = 1;

        }

    } while (*((int *) *pBuffer + 3) == 1);

    printf("\n");

    // --
    
    (*((int *) *pBuffer + 4)) = (*((int *) *pBuffer + 4)) + sizeof(int) + (strlen((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA) + 1) + sizeof(int) + (strlen((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE) + 1);

    void *novoBuffer = realloc (*pBuffer, (5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL + (*((int *) pBuffer + 4))));

    if (!novoBuffer) {

        printf ("-- Erro ao realocar memoria!\n\n");
        return;

    }

    *pBuffer = novoBuffer;

    // --

    // [ESCOLHA] [CONTADOR] [AUXILIAR_1] [AUXILIAR_2] [TAM_REGISTROS] [TAM_BUSCA] [TAM_NOME] [TAM_IDADE] [TAM_EMAIL] [TAM_BLOCO][[NOME][IDADE][EMAIL]]...

    void * ponteiro = ((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL);

    for ((*((int *) *pBuffer + 2)) = 0; (*((int *) *pBuffer + 2)) < (*((int *) *pBuffer + 1)); (*((int *) *pBuffer + 2))++) {

        ponteiro = (char *) ponteiro + *((int *) ponteiro);

    }

    *((int *) ponteiro) = sizeof(int) + (strlen((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA) + 1) + sizeof(int) + (strlen((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE) + 1); 
    
    ponteiro = (char *) ponteiro + sizeof(int);

    strcpy((char *) ponteiro, (char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA);

    ponteiro = (char *) ponteiro + strlen((char *) ponteiro) + 1;

    *((int *) ponteiro) = *(int *)((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME);
    
    ponteiro = (char *) ponteiro + sizeof(int);

    strcpy((char *) ponteiro, (char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE);

    (*((int *) *pBuffer + 1))++;
    
    printf("-- Registro Adicionado com Sucesso!\n\n");

}

void RemoverPessoa (void **pBuffer) {

    (*((int *) *pBuffer + 3)) = 0;

    if ((*((int *) *pBuffer + 1)) == 0) {

        printf("-- A Agenda esta vazia!\n\n");
        return;

    }
    
    // -- 

    printf(" | Digite o nome para remover na Agenda: ");

    fgets(((char *) *pBuffer + 5 * sizeof(int)), TAM_BUSCA, stdin);

    ((char *) *pBuffer + 5 * sizeof(int))[strcspn(((char *) *pBuffer + 5 * sizeof(int)), "\n")] = '\0';

    // --

    void * ponteiro = ((char *) *pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL);
    
    for ((*((int *) *pBuffer + 2)) = 0; (*((int *) *pBuffer + 2)) < (*((int *) *pBuffer + 1)); (*((int *) *pBuffer + 2))++) {
        
        if (strcmp((char *) ((char *) ponteiro + sizeof(int)), ((char *) *pBuffer + 5 * sizeof(int))) == 0) {

            printf ("\n-- Registro correspondente a [%s] encontrado com sucesso!\n", ((char *) *pBuffer + 5 * sizeof(int)));

            printf("\n Registro [%d]\n\n", *((int *) *pBuffer + 2));

            printf(" | Nome: %s\n", (char *) ((char *) ponteiro + sizeof(int)));

            printf(" | Idade: %d\n", *((int *) ((char *) ponteiro + sizeof(int) + strlen((char *) ((char *) ponteiro + sizeof(int))) + 1)));

            printf(" | Email: %s\n", (char *) ((char *) ponteiro + sizeof(int) + strlen((char *) ((char *) ponteiro + sizeof(int))) + 1 + sizeof(int)));

            (*((int *) *pBuffer + 3)) = 1;

            break;

        }

        ponteiro = (char *) ponteiro + *((int *) ponteiro);

    }

    (*((int *) *pBuffer)) = *((int *) ponteiro);  
    
    printf("\n");

    if (!(*((int *) *pBuffer + 3))) {

        printf("-- Nenhum registro encontrado para a busca [%s]!\n\n", ((char *) *pBuffer + 5 * sizeof(int)));
        return;

    }

    // --

    for ((*((int *) *pBuffer + 3)) = (*((int *) *pBuffer + 2)); (*((int *) *pBuffer + 3)) < (*((int *) *pBuffer + 1) - 1); (*((int *) *pBuffer + 3))++) {
        
        void * proximoPonteiro = ((char *) ponteiro + *((int *) ponteiro));
        
        memcpy((char *) ponteiro, (char *) proximoPonteiro , (*((int *) proximoPonteiro)));

        ponteiro = proximoPonteiro;

    }

    // - [0][1][2][3][4][5]
    // - [0][1][3][3][4][5]
    // - [0][1][3][4][4][5]
    // - [0][1][3][4][5][5]

    (*((int *) *pBuffer + 1))--;  

    (*((int *) *pBuffer + 4)) = (*((int *) *pBuffer + 4)) - (*((int *) *pBuffer));

    void *novoBuffer = realloc (*pBuffer, (5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL + (*((int *) pBuffer + 4))));

    if (novoBuffer == NULL) {

        printf("-- Erro ao realocar memória!\n\n");
        return;

    }

    *pBuffer = novoBuffer;  

    printf("-- Registro removido com sucesso!\n\n");

}

void BuscarPessoa (void *pBuffer) {

    (*((int *) pBuffer + 3)) = 0;

    if ((*((int *) pBuffer + 1)) == 0) {

        printf("-- A Agenda esta vazia!\n\n");
        return;

    }

    // --

    printf(" | Digite o nome para buscar na Agenda: ");

    fgets(((char *) pBuffer + 5 * sizeof(int)), TAM_BUSCA, stdin);
    
    ((char *) pBuffer + 5 * sizeof(int))[strcspn(((char *) pBuffer + 5 * sizeof(int)), "\n")] = '\0'; 

    // --

    void *ponteiro = (char *) pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL;

     for (*((int *) pBuffer + 2) = 0; *((int *) pBuffer + 2) < *((int *) pBuffer + 1); (*((int *) pBuffer + 2))++) {

        if (strcmp((char *) ((char *) ponteiro + sizeof(int)), ((char *) pBuffer + 5 * sizeof(int))) == 0) {

            printf ("\n-- Registro correspondente a [%s] encontrado com sucesso!\n", ((char *) pBuffer + 5 * sizeof(int)));

            printf("\n Registro [%d]\n\n", *((int *) pBuffer + 2));

            printf(" | Nome: %s\n", (char *) ((char *) ponteiro + sizeof(int)));

            printf(" | Idade: %d\n", *((int *) ((char *) ponteiro + sizeof(int) + strlen((char *) ((char *) ponteiro + sizeof(int))) + 1)));

            printf(" | Email: %s\n", (char *) ((char *) ponteiro + sizeof(int) + strlen((char *) ((char *) ponteiro + sizeof(int))) + 1 + sizeof(int)));

            (*((int *) pBuffer + 3)) = 1;

            break;

        }

        ponteiro = (char *) ponteiro + *((int *) ponteiro);

    }

    printf("\n");

    if (!(*((int *) pBuffer + 3))) {

        printf("-- Nenhum registro encontrado para a busca [%s]!\n\n", ((char *) pBuffer + 5 * sizeof(int)));

    }
}

void ListarTodos (void *pBuffer) {

    if ((*((int *) pBuffer + 1)) == 0) {

        printf ("-- A Agenda esta vazia!\n\n");

    } else {

        printf("-- Lista de Registros \n");

        void *ponteiro = (char *) pBuffer + 5 * sizeof(int) + TAM_BUSCA + TAM_NOME + TAM_IDADE + TAM_EMAIL;

        for (*((int *) pBuffer + 2) = 0; *((int *) pBuffer + 2) < *((int *) pBuffer + 1); (*((int *) pBuffer + 2))++) {

            printf("\n Registro [%d]\n\n", *((int *) pBuffer + 2));

            printf(" | Nome: %s\n", (char *) ((char *) ponteiro + sizeof(int)));

            printf(" | Idade: %d\n", *((int *) ((char *) ponteiro + sizeof(int) + strlen((char *) ((char *) ponteiro + sizeof(int))) + 1)));

            printf(" | Email: %s\n", (char *) ((char *) ponteiro + sizeof(int) + strlen((char *) ((char *) ponteiro + sizeof(int))) + 1 + sizeof(int)));

            ponteiro = (char *) ponteiro + *((int *) ponteiro);

        }

        printf("\n");
    
    }
}