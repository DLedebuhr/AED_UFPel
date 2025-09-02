// Dienifer Bierhals Ledebuhr - 23103810
// Grafos Direcionados

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 20

void Inicializar ( int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int Estimativa [MAX_VERTICES], int Percorrido [MAX_VERTICES], int Predecessor [MAX_VERTICES], int QuantidadeVertices);
void LerArestas (int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices);
void Dijkstra ( int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int Estimativa [MAX_VERTICES], int Percorrido [MAX_VERTICES], int Predecessor [MAX_VERTICES], int QuantidadeVertices, int Origem, int Destino); 
void ImprimirCaminho(int Destino, int Predecessor[]);

int main () {

    int MatrizArestas [MAX_VERTICES][MAX_VERTICES];    // Matriz de adjacência
    int Estimativa [MAX_VERTICES];                      // Menor distância conhecida apartir da origem
    int Percorrido [MAX_VERTICES];                      // Controla quais vértices já foram processados
    int Predecessor [MAX_VERTICES];                     // Armazena o vértice anterior no caminho mínimo
    
    int QuantidadeVertices = 0;
    int Origem = 0;
    int Destino = 0;
    int Escolha = 0;
    int Valido = 0;
    int ValidoV = 0;

    int i = 0;
    int j = 0;

    printf("\n-- Algoritmo de Dijkstra\n");

    do {

        printf("\n-- Menu:\n");

        printf("\n\t| ( 1 ) Algoritmo de Dijkstra");
        printf("\n\t| ( 2 ) Algoritmo de Dijkstra - Exemplo");
        printf("\n\t| ( 3 ) Sair");

        printf("\n\n-- Escolha: ");
        scanf("%d", &Escolha);

        switch (Escolha) {

            case 1:

                do { 

                    ValidoV = 0;

                    printf("\n- Quantidade de vertices (MAX = %d): ", MAX_VERTICES);
                    scanf("%d", &QuantidadeVertices);
                    
                    if (QuantidadeVertices <= 0 || QuantidadeVertices > MAX_VERTICES) {
                        
                        printf("\n- Quantidade de vertices invalida!\n");

                        ValidoV = 1;
                        
                    }

                } while (ValidoV == 1);

                Inicializar (MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices);

                LerArestas (MatrizArestas, QuantidadeVertices);

                printf("\n- Pontos para executar o Dijkstra:\n");

                do {
                    
                    Valido = 0;
                    
                    printf("\n- Vertice de Origem: ");
                    scanf("%d", &Origem);
    
                    printf("\n- Vertice de Destino: ");
                    scanf("%d", &Destino);
            
                    if (Origem < 0 || Origem >= QuantidadeVertices || Destino < 0 || Destino >= QuantidadeVertices) {
                        
                        printf("Pontos invalidos! Tente Novamente.\n");
                        Valido = 1;
                        
                    } 

                } while (Valido == 1);

                printf("\n- Matriz de Arestas:\n\n");

                for (i = 0; i < QuantidadeVertices; i++) {

                    printf("\t");

                    for (j = 0; j < QuantidadeVertices; j++) {

                        printf("[%02d] ", MatrizArestas[i][j]);

                    }

                    printf("\n");

                }

                Dijkstra (MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices, Origem, Destino);

                printf("\n-- Resultados: \n\n");

                printf("     Vertice\t|   Distancia\t|   Caminho\t\n\n");

                for (i = 0; i < QuantidadeVertices; i++) {

                    printf("\t%d\t", i);

                    if (Estimativa[i] == INT_MAX) {

                        printf("|\tINF\t|  Indisponivel\n");

                    } else {

                        printf("|\t%02d\t|  ", Estimativa[i]);

                        ImprimirCaminho(i, Predecessor);

                        printf("\n");

                    }
                }

                break;

            case 2:

                QuantidadeVertices = 7;

                Inicializar(MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices);
                
                MatrizArestas[0][1] = 2;
                MatrizArestas[0][2] = 6;
                MatrizArestas[1][3] = 5;
                MatrizArestas[2][3] = 8;
                MatrizArestas[3][5] = 15;
                MatrizArestas[3][4] = 10;
                MatrizArestas[4][6] = 2;
                MatrizArestas[5][6] = 6;
                MatrizArestas[5][4] = 2;
                
                printf("\n- Exemplo pre-carregado:\n\n");

                for (i = 0; i < QuantidadeVertices; i++) {

                    printf("\t");

                    for (j = 0; j < QuantidadeVertices; j++) {

                        printf("[%02d] ", MatrizArestas[i][j]);

                    }

                    printf("\n");

                }
                
                printf("\n- Pontos para executar o Dijkstra:\n");

                do {
                    
                    Valido = 0;
                    
                    printf("\n- Vertice de Origem: ");
                    scanf("%d", &Origem);
    
                    printf("\n- Vertice de Destino: ");
                    scanf("%d", &Destino);
            
                    if (Origem < 0 || Origem >= QuantidadeVertices || Destino < 0 || Destino >= QuantidadeVertices) {
                        
                        printf("Pontos invalidos! Tente Novamente.\n");
                        Valido = 1;
                        
                    } 

                } while (Valido == 1);       

                Dijkstra(MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices, Origem, Destino);

                printf("\n-- Resultados: \n\n");

                printf("     Vertice\t|   Distancia\t|   Caminho\t\n\n");

                for (i = 0; i < QuantidadeVertices; i++) {

                    printf("\t%d\t", i);

                    if (Estimativa[i] == INT_MAX) {

                        printf("|\tINF\t|  Indisponivel\n");

                    } else {

                        printf("|\t%02d\t|  ", Estimativa[i]);

                        ImprimirCaminho(i, Predecessor);

                        printf("\n");

                    }
                }

                break;

            case 3:

                printf("\n-- Encerrando Programa!\n");
                break;

            default:

                printf("\n-- Escolha invalida! Tente Novamente...\n");

        }

    } while (Escolha != 3);

    return 0;

    // /ᐠ｡ꞈ｡ᐟ\ //

}

void Inicializar ( int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int Estimativa [MAX_VERTICES], int Percorrido [MAX_VERTICES], int Predecessor [MAX_VERTICES], int QuantidadeVertices) {

    int i = 0;
    int j = 0;

    for (i = 0; i < QuantidadeVertices; i++) {

        Estimativa [i] = INT_MAX;  // Distância inicial 
        Percorrido [i] = 0;       // Nenhum vértice processado
        Predecessor [i] = -1;    // -1 indica nenhum predecessor
    
    }

    for (i = 0; i < QuantidadeVertices; i++) {
        for (j = 0; j < QuantidadeVertices; j++) {

            MatrizArestas[i][j] = -1; // -1 indica ausência de aresta

        }
    }
}

void LerArestas (int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices) {

    int QuantidadeArestas = 0;
    int Origem = 0;
    int Destino = 0;
    int Peso = 0;
    int Valido = 0;
    int ValidoV = 0;
    int i = 0;

    do {

        ValidoV = 0;

        printf("\n- Quantidade de Arestas: ");
        scanf("%d", &QuantidadeArestas);

        if (QuantidadeArestas < 0) {

            printf("\n- Quantidade de Arestas invalida!\n");

            ValidoV = 1;

        }

    } while (ValidoV == 1);

    printf("\n- Formato: Origem - Destino - Peso\n\n");

    for (i = 0; i < QuantidadeArestas; i++) {

        do {

            Valido = 0;

            printf("- Aresta [%d]: ", i);
            scanf("%d %d %d", &Origem, &Destino, &Peso);
            
            if (Origem < 0 || Origem >= QuantidadeVertices || Destino < 0 || Destino >= QuantidadeVertices) {
                
                printf("\n- Vertice invalido! Tente Novamente.\n\n");

                Valido = 1;
                
            } 

            if (Peso < 0) {

                printf("\n- Peso negativo nao permitido! Usando valor absoluto.\n\n");

                Peso = abs(Peso);

            }

        } while (Valido == 1);
        
        MatrizArestas[Origem][Destino] = Peso;

    }
}

void Dijkstra (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int Estimativa[MAX_VERTICES], int Percorrido[MAX_VERTICES], int Predecessor[MAX_VERTICES], int QuantidadeVertices, int Origem, int Destino) {
    
    Estimativa[Origem] = 0;
    
    while (1) { // Loop infinito que só termina quando explicitamente interrompido
        
        int VerticeAtual = -1; 
        int i = 0;
        int MenorEstimativa = INT_MAX;

        for (i = 0; i < QuantidadeVertices; i++) {

            if (!Percorrido[i] && Estimativa[i] < MenorEstimativa) { // Procura pelo vértice não visitado (!Percorrido[i]) com a menor estimativa de distância (Estimativa[i] < MenorEstimativa)

                MenorEstimativa = Estimativa[i]; // Atualiza a menor estimativa

                VerticeAtual = i; // VerticeAtual recebe o índice desse vértice

            }
        }
        
        if (VerticeAtual == -1 || VerticeAtual == Destino) { // Não há mais vértices para processar (Temp == -1) ou chegamos ao vértice destino (Temp == Destino)
            
            break;
        }

        Percorrido[VerticeAtual] = 1; // Marca o vértice atual como Percorrido
         
        for (i = 0; i < QuantidadeVertices; i++) {
            
            if (MatrizArestas[VerticeAtual][i] != -1) { // Para cada vizinho do vértice atual
                
                int NovaDistancia = Estimativa[VerticeAtual] + MatrizArestas[VerticeAtual][i]; // Calcula uma nova distância: Distância até VerticeAtual + Peso da aresta
                
                if (NovaDistancia < Estimativa[i]) { // Se essa nova distância for menor que a estimativa atual:
                    
                    Estimativa[i] = NovaDistancia; // Atualiza a estimativa de distância
                    
                    Predecessor[i] = VerticeAtual; // Registra que o melhor caminho para i vem através de VerticeAtual

                }
            }
        }
    }
}

void ImprimirCaminho(int Destino, int Predecessor[]) {

    if (Destino == -1) {
        
        return;
    
    }
    
    ImprimirCaminho(Predecessor[Destino], Predecessor);

    printf("%d ", Destino);

}