// Dienifer Bierhals Ledebuhr - 23103810

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Algoritmo de Dijkstra

#define MAX_VERTICES 20

void Inicializar ( int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int Estimativa [MAX_VERTICES], int Percorrido [MAX_VERTICES], int Predecessor [MAX_VERTICES], int QuantidadeVertices);
void LerArestas (int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices);
void Dijkstra ( int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int Estimativa [MAX_VERTICES], int Percorrido [MAX_VERTICES], int Predecessor [MAX_VERTICES], int QuantidadeVertices, int Origem, int Destino); 
void ImprimirCaminho(int Destino, int Predecessor[]);

// Algoritmo de Kruskal

#define MAX_ARESTAS (MAX_VERTICES * (MAX_VERTICES - 1) / 2)

typedef struct {

    int VerticeOrigem;
    int VerticeDestino;
    int Peso;

} ArestaAGM;

int GrupoVertices[MAX_VERTICES];

void DFS (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int Visitados[MAX_VERTICES], int VerticeAtual, int QuantidadeVertices);
int GrafoConexo (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices);
int CompararArestas (const void * A, const void * B);
int EncontrarGrupo (int Vertice);
void Kruskal (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices);
int VerificaArvore (int ArestasAdicionadas, int QuantidadeVertices);

int main () {

    int MatrizArestas [MAX_VERTICES][MAX_VERTICES];     // Matriz de adjacência
    int Estimativa [MAX_VERTICES];                      // Menor distância conhecida apartir da origem
    int Percorrido [MAX_VERTICES];                      // Controla quais vértices já foram processados
    int Predecessor [MAX_VERTICES];                     // Armazena o vértice anterior no caminho mínimo
    
    int QuantidadeVertices = 0;
    int Origem = 0;
    int Destino = 0;
    int Escolha = 0;
    int Valido = 0;
    int ValidoV = 0;
    int ValidoX = 0;

    int i = 0;
    int j = 0;

    printf("\n-- Algoritmo de Dijkstra\n");

    do {

        Escolha = 0;

        printf("\n-- Menu:\n");

        printf("\n\t| ( 1 ) Algoritmo de Dijkstra");
        printf("\n\t| ( 2 ) Algoritmo de Dijkstra - Exemplo");
        printf("\n\t| ( 3 ) Algoritmo de Kruskal");
        printf("\n\t| ( 4 ) Algoritmo de Kruskal - Exemplos");
        printf("\n\t| ( 5 ) Sair");

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
            
                    if (Origem < 0 || Origem >= QuantidadeVertices || Destino < 0 || Destino >= QuantidadeVertices || Origem == Destino) {
                        
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

                break;

            case 2:

                QuantidadeVertices = 7;

                Inicializar(MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices);
                
                MatrizArestas[0][1] = 2;    MatrizArestas[1][0] = 2;
                MatrizArestas[0][2] = 6;    MatrizArestas[2][0] = 6;
                MatrizArestas[1][3] = 5;    MatrizArestas[3][1] = 5;
                MatrizArestas[2][3] = 8;    MatrizArestas[3][2] = 8;
                MatrizArestas[3][5] = 15;   MatrizArestas[5][3] = 15;
                MatrizArestas[3][4] = 10;   MatrizArestas[4][3] = 10;
                MatrizArestas[4][6] = 2;    MatrizArestas[6][4] = 2;
                MatrizArestas[5][6] = 6;    MatrizArestas[6][5] = 6;
                MatrizArestas[5][4] = 2;    MatrizArestas[4][5] = 2;
                                
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
                             
                break;

            case 3:
                
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

                printf("\n- Matriz de Arestas:\n\n");

                for (i = 0; i < QuantidadeVertices; i++) {

                    printf("\t");

                    for (j = 0; j < QuantidadeVertices; j++) {

                        printf("[%02d] ", MatrizArestas[i][j]);

                    }

                    printf("\n");

                }

                Kruskal (MatrizArestas, QuantidadeVertices);

                break;    

            case 4:

                do {

                    ValidoX = 0;

                    printf("\n-- Escolha um dos Exemplos:\n");

                    printf("\n\t| ( 1 ) Grafo Valido");
                    printf("\n\t| ( 2 ) Grafo n Conexo");
                    printf("\n\t| ( 3 ) Voltar pro Menu Principal");

                    printf("\n\n-- Escolha: ");
                    scanf("%d", &ValidoX);

                    switch (ValidoX) {

                        case 1:
                            
                            QuantidadeVertices = 5;

                            Inicializar(MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices);
                            
                            MatrizArestas[0][1] = 2;    MatrizArestas[1][0] = 2;
                            MatrizArestas[0][3] = 6;    MatrizArestas[3][0] = 6;
                            MatrizArestas[1][2] = 3;    MatrizArestas[2][1] = 3;
                            MatrizArestas[1][3] = 8;    MatrizArestas[3][1] = 8;
                            MatrizArestas[2][4] = 7;    MatrizArestas[4][2] = 7;
                            MatrizArestas[3][4] = 9;    MatrizArestas[4][3] = 9;
                            
                            printf("\n- Exemplo pre-carregado:\n\n");

                            for (i = 0; i < QuantidadeVertices; i++) {

                                printf("\t");

                                for (j = 0; j < QuantidadeVertices; j++) {

                                    printf("[%02d] ", MatrizArestas[i][j]);

                                }

                                printf("\n");

                            }  

                            Kruskal(MatrizArestas, QuantidadeVertices);    
                                        
                            break;

                        case 2:

                            QuantidadeVertices = 5;

                            Inicializar(MatrizArestas, Estimativa, Percorrido, Predecessor, QuantidadeVertices);
                            
                            MatrizArestas[0][1] = 2;    MatrizArestas[1][0] = 2;
                            MatrizArestas[1][2] = 3;    MatrizArestas[2][1] = 3;
                            MatrizArestas[3][4] = 5;    MatrizArestas[4][3] = 5;
                            
                            printf("\n- Exemplo pre-carregado:\n\n");

                            for (i = 0; i < QuantidadeVertices; i++) {

                                printf("\t");

                                for (j = 0; j < QuantidadeVertices; j++) {

                                    printf("[%02d] ", MatrizArestas[i][j]);

                                }

                                printf("\n");

                            }  

                            Kruskal(MatrizArestas, QuantidadeVertices);    
                                        
                            break;

                        case 3:

                            printf("\n-- Voltando para o Menu Principal!\n");

                            break;

                        default:

                            printf("\n-- Escolha invalida! Tente Novamente...\n");

                        }

                } while (ValidoX != 3);

                break;
                
            case 5:

                printf("\n-- Encerrando Programa!\n");
                break;

            default:

                printf("\n-- Escolha invalida! Tente Novamente...\n");

        }

    } while (Escolha != 5);

    return 0;

    // /ᐠ｡ꞈ｡ᐟ\ //

}

void Inicializar (int MatrizArestas [MAX_VERTICES][MAX_VERTICES], int Estimativa [MAX_VERTICES], int Percorrido [MAX_VERTICES], int Predecessor [MAX_VERTICES], int QuantidadeVertices) {

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
        MatrizArestas[Destino][Origem] = Peso;

    }
}

void Dijkstra (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int Estimativa[MAX_VERTICES], int Percorrido[MAX_VERTICES], int Predecessor[MAX_VERTICES], int QuantidadeVertices, int Origem, int Destino) {
    
    if (QuantidadeVertices == 0) {

        printf("\n-- Erro: Grafo vazio (sem vertices)!\n");
        return;

    }

    Estimativa[Origem] = 0;
    int i = 0;
    
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

    printf("\n-- Resultados: \n\n");

    printf("\tVertice   |   Peso   |   Caminho\n\n"); 

    for (i = 0; i < QuantidadeVertices; i++) {

        printf("\t   %d      ", i);

        if (Estimativa[i] == INT_MAX) {

            printf("|    xx    |   N Avaliado\n");

        } else {

            printf("|    %02d    |   ", Estimativa[i]);

            ImprimirCaminho(i, Predecessor);

            printf("\n");

            }
    }

    if (Estimativa[Destino] == INT_MAX) {

        printf("\n-- Aviso: Nao existe caminho do vertice %d para %d!\n", Origem, Destino);

    } else {

        printf("\n- Caminho Final: \n\n\t");

        ImprimirCaminho(Destino, Predecessor);
        
        printf("\n");

    }
}

void ImprimirCaminho(int Destino, int Predecessor[]) {

    if (Destino == -1) {
        
        return;
    
    }

    ImprimirCaminho(Predecessor[Destino], Predecessor);
    
    printf("-> %d ", Destino);
  
}

// Algoritmo de Kruskal

void DFS (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int Percorridos[MAX_VERTICES], int VerticeAtual, int QuantidadeVertices) {

    Percorridos[VerticeAtual] = 1;
    
    int i = 0;

    for (i = 0; i < QuantidadeVertices; i++) {

        if (MatrizArestas[VerticeAtual][i] > 0 && !Percorridos[i]) {

            DFS (MatrizArestas, Percorridos, i, QuantidadeVertices);

        }
    }
}

int GrafoConexo (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices) {

    int Percorridos[MAX_VERTICES] = {0};

    DFS (MatrizArestas, Percorridos, 0, QuantidadeVertices);
    
    for (int i = 0; i < QuantidadeVertices; i++) {

        if (!Percorridos[i]) {

            return 0; 

        }
    }
    
    return 1; 

}

int CompararArestas (const void * ArestaA, const void * ArestaB) {

    ArestaAGM * A = (ArestaAGM *) ArestaA;
    ArestaAGM * B = (ArestaAGM *) ArestaB;

    return A -> Peso - B -> Peso;

}

int EncontrarGrupo (int Vertice) {

    while (GrupoVertices[Vertice] != Vertice) {

        Vertice = GrupoVertices[Vertice];

    }

    return Vertice;

}

int VerificaArvore (int ArestasAdicionadas, int QuantidadeVertice) {

    return (ArestasAdicionadas == QuantidadeVertice - 1);

}

void Kruskal (int MatrizArestas[MAX_VERTICES][MAX_VERTICES], int QuantidadeVertices) {

    if (QuantidadeVertices == 0) {

        printf("\n-- Erro: Grafo vazio (zero vertices)!\n");

        return;

    }

    if (QuantidadeVertices == 1) {

        printf("\n-- Aviso: Grafo unitario! AGM vazia (sem arestas).\n");

        return;

    }

    if (!GrafoConexo(MatrizArestas, QuantidadeVertices)) {

        printf("\n-- Erro: O algoritmo de Kruskal requer um grafo conexo!\n");

        return;

    }

    ArestaAGM Arestas[MAX_ARESTAS];

    int QuantidadeArestas = 0;
    int TotalPeso = 0;

    int VerticeOrigem = 0;
    int VerticeDestino = 0;

    int i = 0;

    for (VerticeOrigem = 0; VerticeOrigem < QuantidadeVertices; VerticeOrigem++) {

        for (VerticeDestino = VerticeOrigem + 1; VerticeDestino < QuantidadeVertices; VerticeDestino++) {

            if (MatrizArestas[VerticeOrigem][VerticeDestino] > 0) {

                Arestas[QuantidadeArestas].VerticeOrigem = VerticeOrigem;

                Arestas[QuantidadeArestas].VerticeDestino = VerticeDestino;

                Arestas[QuantidadeArestas].Peso = MatrizArestas[VerticeOrigem][VerticeDestino];

                QuantidadeArestas++;

            }
        }
    }

    qsort (Arestas, QuantidadeArestas, sizeof(ArestaAGM), CompararArestas);
    
    for (i = 0; i < QuantidadeVertices; i++) {
        
        GrupoVertices[i] = i;
        
    }
    
    printf("\n-- Arestas na Arvore Geradora Minima:\n\n");
    
    printf("\tOrigem    |    Destino    |    Peso\n\n");
    
    int ArestasAdicionadas = 0;

    for (i = 0; i < QuantidadeArestas && ArestasAdicionadas < QuantidadeVertices - 1; i++) {

        int GrupoOrigem = EncontrarGrupo (Arestas[i].VerticeOrigem);

        int GrupoDestino = EncontrarGrupo (Arestas[i].VerticeDestino);

        if (GrupoOrigem != GrupoDestino) {

            printf("\t   %d      |       %d       |     %02d\n", Arestas[i].VerticeOrigem, Arestas[i].VerticeDestino, Arestas[i].Peso);

            TotalPeso += Arestas[i].Peso;

            GrupoVertices[GrupoDestino] = GrupoOrigem;

            ArestasAdicionadas++;

        }
    }

    if (VerificaArvore(ArestasAdicionadas, QuantidadeVertices)) {

        printf("\n\n- Resultado valido!\n");

        printf("\n- Peso total da AGM: %d\n", TotalPeso);

    } else {

        printf("\n\n- Resultado invalido!\n");

    }

}