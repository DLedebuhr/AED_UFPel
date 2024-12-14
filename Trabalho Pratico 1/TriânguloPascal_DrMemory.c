#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    *returnSize = numRows; 
    
    *returnColumnSizes = ( int * ) malloc ( numRows * sizeof(int) ); 

    int** matriz = ( int** ) malloc ( numRows * sizeof(int*) ); 

    for (int i = 0; i < numRows; i++) { 
        
        (*returnColumnSizes)[i] = i + 1; 

        matriz[i] = ( int* ) malloc ( ( i + 1 ) * sizeof(int) );  
        
        for (int j = 0; j <= i; j++) { 

            if (j == 0 || j == i) { 
            
                matriz[i][j] = 1; 

            } else {
            
                matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j]; 
            
            }
        }
    }

    return matriz;
    
}

int main() {

    int numRows = 5;
    int returnSize;
    int* returnColumnSizes;

    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {

        for (int j = 0; j < returnColumnSizes[i]; j++) {

            printf("%d ", triangle[i][j]);

        }

        printf("\n");

    }

    
    for (int i = 0; i < returnSize; i++) {

        free(triangle[i]);

    }

    free(triangle);
    free(returnColumnSizes);

    return 0;
    
}
