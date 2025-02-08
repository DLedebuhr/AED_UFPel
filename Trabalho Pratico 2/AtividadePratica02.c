double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {
 double heap[classesSize][2];
 // {[}[1, 2]]
    // 1 -> passaram
    // 2 total alunos

    // extra -> adiciona na pior classe

    // media aporvação = alunos qu epassaram / total -> por classe

    // aprovação media = soma das taxas de aprovação / num de classes
    
     // é um aluno pra cada turma, ou todos pra uma turma só?

    double temp [classesSize][2];

    for (int i = 0; i < classesSize; i++) {

        temp[i][0] = classes[i][0];
        temp[i][1] = classes[i][1];

    }

    double mediaturma = 0.0;
    double mediaturmaextra = 0.0;
    double comparar[classesSize];

    while (extraStudents > 0) {

    int classecomextra = 0;
    double menor = -1.0;

    for (int i = 0; i < classesSize; i++) {

        mediaturma = temp[i][0] / temp[i][1];
        mediaturmaextra = (temp[i][0] + 1)  / (temp[i][1] + 1);
        comparar[i] = mediaturmaextra - mediaturma;

    }

     for (int i = 0; i < classesSize; i++) {

        if (comparar[i] > menor) {

            menor = comparar[i];    
            classecomextra = i; 

        }
     }

     extraStudents -= 1;

    temp[classecomextra][0] = temp[classecomextra][0] + 1;
    temp[classecomextra][1] = temp[classecomextra][1] + 1;
    
    }


    // int classecomextra = 0;
    // double menor = -1.0;

    // for (int i = 0; i < classesSize; i++) {

    //     mediaturma = temp[i][0] / temp[i][1];
    //     mediaturmaextra = (temp[i][0] + extraStudents)  / (temp[i][1] + extraStudents);
    //     comparar[i] = mediaturmaextra - mediaturma;

    // }

    //  for (int i = 0; i < classesSize; i++) {

    //     if (comparar[i] > menor) {

    //         menor = comparar[i];    
    //         classecomextra = i; 

    //     }
    //  }

    // temp[classecomextra][0] = temp[classecomextra][0] + extraStudents1;
    // temp[classecomextra][1] = temp[classecomextra][1] + extraStudents;
    
    
    double mediat = 0.0;

    for (int i = 0; i < classesSize; i++) {

        mediat += temp[i][0]  / temp[i][1];
        
    }



    return mediat / classesSize;
}