double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {

    double vetorClasses [classesSize][2];
    double comparar;

    for (int i = 0; i < classesSize; i++) {

        vetorClasses [i][0] = classes [i][0];
        vetorClasses [i][1] = classes [i][1];

    }

    while (extraStudents > 0) {

        int classeComExtra = 0;
        double maior = -1.0;

        for (int i = 0; i < classesSize; i++) {

            comparar = ((vetorClasses [i][0] + 1)  / (vetorClasses [i][1] + 1)) - (vetorClasses [i][0] / vetorClasses [i][1]);

            if (comparar > maior) {

                maior = comparar;    
                classeComExtra = i; 

            }
        }

        vetorClasses [classeComExtra][0] += 1;
        vetorClasses [classeComExtra][1] += 1;

        extraStudents -= 1;
        
    }  
    
    double taxaAprovacao = 0.0;

    for (int i = 0; i < classesSize; i++) {

        taxaAprovacao += vetorClasses [i][0]  / vetorClasses [i][1];
        
    }

    return taxaAprovacao / classesSize;

}