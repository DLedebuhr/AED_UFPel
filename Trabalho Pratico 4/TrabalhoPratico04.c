void Ordenar (int* difficulty, int* profit, int Tamanho) {
    
    for (int i = 0; i < Tamanho - 1; i++) {
        
        for (int j = i + 1; j < Tamanho; j++) {
            
            if (difficulty[i] > difficulty[j]) {
                
                int tempD = difficulty[i];
                difficulty[i] = difficulty[j];
                difficulty[j] = tempD;

                int tempP = profit[i];
                profit[i] = profit[j];
                profit[j] = tempP;
            
            }
        }
    }
}

void OrdenarTrabalhadores (int * worker, int Tamanho) {

    for (int i = 0; i < Tamanho - 1; i++) {

        for (int j = i + 1; j < Tamanho; j++) {
        
            if (worker[i] > worker[j]) {
        
                int temp = worker[i];
                worker[i] = worker[j];
                worker[j] = temp;
        
            }
        }
    }

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

    int Lucro = 0;
    int MaiorTrabalho = 0;
    int i;
    int j;

    for (i = 0; i < workerSize; i++) {
        
        for (j = 0; j < difficultySize && worker[i] >= difficulty[j]; j++) { 

            if (profit[j] > MaiorTrabalho) {
        
                MaiorTrabalho = profit[j];
        
            }
        
        }
        
        Lucro += MaiorTrabalho;
    }

    return Lucro;
}

