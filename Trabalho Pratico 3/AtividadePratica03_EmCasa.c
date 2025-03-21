/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int SomadorSub (struct TreeNode* root, int * Somador, int * Indice) {

    // root = Raiz

    if (root == NULL) {

        return 0; 

    }

    int SomaEsquerda = SomadorSub (root -> left, Somador, Indice);
    int SomaDireita = SomadorSub (root -> right, Somador, Indice);
    int TotalSoma = root -> val + SomaEsquerda + SomaDireita;

    Somador[(*Indice)++] = TotalSoma;

    return TotalSoma;

    //        1 
    //       / \        
    //      2   3
    //     / \ 
    //    4   5

    // Somador = [4, 5, 11, 3, 15]

}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    
    int i;
    int j;

    if (root == NULL) {

        *returnSize = 0;
        return NULL;

    }

    int Somador [10000];
    int Indice = 0;

    SomadorSub (root, Somador, &Indice);

    int Frequencia[10000] = {0};
    int Valores[10000] = {0};
    int Contador = 0;

    for (i = 0; i < Indice; i++) {

        int Encontrado = 0;

        for (j = 0; j < Contador; j++) {

            if (Valores[j] == Somador[i]) {

                Frequencia[j]++;
                Encontrado = 1;
                break;

            }
        }

        if (Encontrado == 0) {

            Valores[Contador] = Somador[i];
            Frequencia[Contador] = 1;
            Contador++;

        }
    }

    // Frequencia = [1, 1, 1, 1, 1]
    // Valores = [4, 5, 11, 3, 15]

    int MaiorFrequencia = 0;

    for (i = 0; i < Contador; i++) {
        
        if (Frequencia[i] > MaiorFrequencia) {

            MaiorFrequencia = Frequencia[i];

        }
    }

    // MaiorFrequencia = 1

    int Cont = 0;

    for (i = 0; i < Contador; i++) {
        
        if (Frequencia[i] == MaiorFrequencia) {

            Cont++;

        }
    }

    // Cont = 5

    int * Resultado;
    int ResultadoIndice = 0;

    Resultado = (int *) malloc (Cont * sizeof(int));

    for (i = 0; i < Contador; i++) {
        
        if (Frequencia[i] == MaiorFrequencia) {

            Resultado[ResultadoIndice++] = Valores[i];

        }
    }

    *returnSize = Cont;

    return Resultado;

    // *returnSize = 5
    // Resultado = [4, 5, 11, 3, 15]
}