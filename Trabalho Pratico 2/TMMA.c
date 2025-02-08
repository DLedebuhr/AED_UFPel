#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int aprovados;         
    int totalEstudantes;    
    double ganho;           

} Classe;

double CalcularGanho(int aprovados, int totalEstudantes) {

    return ((double)(aprovados + 1) / (totalEstudantes + 1)) - ((double)aprovados / totalEstudantes);

}

void Reorganizar(Classe *heap, int tamanho, int i) {

    int maior = i;           
    int esquerda = 2 * i + 1; 
    int direita = 2 * i + 2;  

    if (esquerda < tamanho && heap[esquerda].ganho > heap[maior].ganho) {

        maior = esquerda;

    }

    if (direita < tamanho && heap[direita].ganho > heap[maior].ganho) {

        maior = direita;

    }

    if (maior != i) {

        Classe temp = heap[i];
        heap[i] = heap[maior];
        heap[maior] = temp;

        Reorganizar(heap, tamanho, maior);

    }
}

void ConstruirHeap(Classe *heap, int tamanho) {

    for (int i = tamanho / 2 - 1; i >= 0; i--) {

        Reorganizar(heap, tamanho, i);

    }
}

Classe ExtrairMaior(Classe *heap, int *tamanho) {

    Classe maximo = heap[0];     

    heap[0] = heap[(*tamanho) - 1]; 

    (*tamanho)--;                   

    Reorganizar(heap, *tamanho, 0); 

    return maximo;

}

void InserirHeap(Classe *heap, int *tamanho, Classe novaClasse) {

    (*tamanho)++;      

    int i = (*tamanho) - 1;         

    heap[i] = novaClasse;           

    while (i > 0 && heap[(i - 1) / 2].ganho < heap[i].ganho) {

        Classe temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;

    }
}

double maxAverageRatio(int **classes, int classesSize, int *classesColSize, int extraStudents) {

    Classe *heap = (Classe *)malloc(classesSize * sizeof(Classe));

    int heapSize = classesSize;

    for (int i = 0; i < classesSize; i++) {

        heap[i].aprovados = classes[i][0];
        heap[i].totalEstudantes = classes[i][1];
        heap[i].ganho = CalcularGanho(heap[i].aprovados, heap[i].totalEstudantes);

    }

    ConstruirHeap(heap, heapSize);

    while (extraStudents > 0) {
        
        Classe top = ExtrairMaior(heap, &heapSize);

        top.aprovados += 1;

        top.totalEstudantes += 1;

        top.ganho = CalcularGanho(top.aprovados, top.totalEstudantes);

        InserirHeap(heap, &heapSize, top);

        extraStudents--;

    }
    
    double taxaMedia = 0.0;

    for (int i = 0; i < heapSize; i++) {

        taxaMedia += (double)heap[i].aprovados / heap[i].totalEstudantes;

    }

    free(heap);

    return taxaMedia / classesSize;
    
}