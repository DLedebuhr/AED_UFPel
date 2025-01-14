#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct Aluno {

    int registroAcademico;
    char nome [50];

};

struct Pilha {

    struct Aluno alunos [MAX];
    int topo;

};

void reset (struct Pilha *pilha) {

    pilha -> topo = 0; // Topo recebe 0, reiniciando/iniciando a pilha

}

bool Empty (struct Pilha *pilha) {

    return ((pilha -> topo) == 0); // Retorna true se a pilha estiver vazia

}

bool Full (struct Pilha *pilha) {

    return((pilha -> topo) == MAX); // Retorna true se a pilha estiver cheia

}

void PUSH (struct Pilha *pilha, struct Aluno *Novo) {

    if (!Full(pilha)) {

        pilha -> alunos[pilha -> topo] = *Novo;
        pilha -> topo++;

    } else {

        printf("\nA pilha esta cheia!\n");

    }

}

void POP (struct Pilha *pilha) {

    if (Empty(pilha)) {

        printf("\nPilha esta vazia!\n");       

    } else {

        pilha -> topo--;

    }

}

void Listar (struct Pilha *pilha) {
 
    if (Empty(pilha)) {

        printf("\nPilha esta vazia!\n"); 
        return;

    } else {

        printf("\nListando...\n\n");

        for (int i = pilha->topo - 1; i >= 0; i--) {

            printf("- Registro do Aluno: %d\n", pilha->alunos[i].registroAcademico);
            printf("- Aluno: %s\n", pilha->alunos[i].nome);
        
        } 
    }
}

int main () {

    struct Pilha pilha;

    reset(&pilha);

    int escolha = 0;

    do {

        printf("\n--Menu:\n");

        printf("\t1. Adicionar aluno\n");
        printf("\t2. Remover aluno\n");
        printf("\t3. Listar alunos\n");
        printf("\t4. Sair\n");

        printf("-- Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {

            case 1: {

                struct Aluno aluno;

                printf("Informe o Registro Academico do aluno: ");
                scanf("%d", &aluno.registroAcademico);
                
                printf("Informe o nome  do aluno: ");
                scanf("%s", aluno.nome);

                PUSH(&pilha, &aluno);

                break;

            }

            case 2: {

                POP(&pilha);

                break;

            }

            case 3: {

                Listar(&pilha);

                break;

            }

            case 4: {

                printf("Encerrando programa.\n");
                break;
            } 
            
            default:
            
                printf("Opção inválida. Tente novamente.\n");
            
        }

    } while (escolha != 4);

    return 0;

}