/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    *returnSize = numRows; // tamanho da matriz
    
    *returnColumnSizes = ( int * ) malloc ( numRows * sizeof(int) ); // e cada espaço da lista tem n colunos

    int** matriz = ( int** ) malloc ( numRows * sizeof(int*) ); // [][] cria a matriz

    for (int i = 0; i < numRows; i++) { // linhas 
        
        (*returnColumnSizes)[i] = i + 1; // tamanho da coluna atual

        // i = 0  ->    1
        // i = 1  ->    2
        // i = 2  ->    3...

        //   []
        //  [][]
        // [][][]...
        
        matriz[i] = (int*) malloc ((i + 1) * sizeof(int)); // linha atual 
        
        for (int j = 0; j <= i; j++) { // colunas

            if (j == 0 || j == i) { 
            
                matriz[i][j] = 1; //bordas

                // j = 0 -> topo da coluna 1x1, logo matriz[0][0] = 1;
            
            } else {
            
                matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j]; 

                // matriz [2][2] = matriz[1][1] + matriz[1][2] == 2;
                                
                                // matriz [1][1] = 1 linha e 0 coluna = 1
                                // matriz [1][2] = 1 linha e 1 coluna = 1
            
            }
        }
    }

    return matriz;
}