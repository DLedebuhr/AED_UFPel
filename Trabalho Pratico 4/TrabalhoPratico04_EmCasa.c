int Comparar(const void* a, const void* b) {

    return (*(int *) a - *(int *) b);

}

void OrdenarTrabalhadores(int* worker, int Tamanho) {
   
    qsort(worker, Tamanho, sizeof(int), Comparar);

}

typedef struct {

    int Difficulty;
    int Profit;

} Auxiliar;

int CompararAuxiliar (const void* a, const void* b) {

    return ((Auxiliar *) a ) -> Difficulty - ((Auxiliar *) b ) -> Difficulty;

}

void Ordenar (int * difficulty, int * profit, int Tamanho) {

    int i;

    Auxiliar * Aux = (Auxiliar *) malloc (Tamanho * sizeof(Auxiliar));

    for (i = 0; i < Tamanho; i++) {

        Aux[i].Difficulty = difficulty[i];
        Aux[i].Profit = profit[i];

    }

    qsort(Aux, Tamanho, sizeof(Auxiliar), CompararAuxiliar);

    for (i = 0; i < Tamanho; i++) {

        difficulty[i] = Aux[i].Difficulty;
        profit[i] = Aux[i].Profit;

    }

    free (Aux);

}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    
    // difficulty - Vetor - Dificuldade
    // difficultySize - Tamanho do vetor

    // profit - Vetor - Lucro do trabalho
    // profitSize - Tamanho do vetor

    // worker - Vetor - Capacidade do trabalhador
    // workerSize - Tamanho do vetor

    // Retornar o lucro maximo

    Ordenar (difficulty, profit, difficultySize);

    OrdenarTrabalhadores (worker, workerSize);

    int i;
    int j = 0;
    int Lucro = 0;
    int MaiorTrabalho = 0;

    for (i = 0; i < workerSize; i++) {

        while (j < difficultySize && worker[i] >= difficulty[j]) { 

            if (profit[j] > MaiorTrabalho) {
        
                MaiorTrabalho = profit[j];
        
            }

            j++;
        
        }
        
        Lucro += MaiorTrabalho;

    }

    return Lucro;

}

