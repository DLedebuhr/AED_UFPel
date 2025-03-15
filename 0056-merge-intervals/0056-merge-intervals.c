// * Return an array of arrays of size *returnSize.
// * The sizes of the arrays are returned as *returnColumnSizes array.
// * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 

// Retorna um array de arrays de tamanho *returnSize.
// Os tamanhos dos arrays são retornados como array *returnColumnSizes.
// Nota: Tanto o array retornado quanto o array *columnSizes devem ser alocados incorretamente, suponha que o chamador chame free().

//int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    
    // intervals -> Matriz recebida
    // intervalsSize -> Quantidade de elementos na matriz
    // intervalsColSize -> Quantidade de colunas

    // returnSize -> Retorna a quantidade de elementos na matriz
    // returnColumnSizes -> Retorna a quantidade de colunas na matriz
    
int compare(const void* a, const void* b) {

    int* intervaloA = *(int**)a;

    int* intervaloB = *(int**)b;

    return intervaloA[0] - intervaloB[0];

}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** resultado = (int**)malloc(intervalsSize * sizeof(int*));

    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int cont = 0;

    for (int i = 0; i < intervalsSize; i++) {

        if (cont == 0 || intervals[i][0] > resultado[cont - 1][1]) {
          
            resultado[cont] = (int*)malloc(2 * sizeof(int));

            resultado[cont][0] = intervals[i][0];

            resultado[cont][1] = intervals[i][1];

            (*returnColumnSizes)[cont] = 2;

            cont++;

        } else {

            if (intervals[i][1] > resultado[cont - 1][1]) {

                resultado[cont - 1][1] = intervals[i][1];

            }
        }
    }

    *returnSize = cont;

    return resultado;

}


