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

// Achar a soma de todas as subarvores -> pega raiz e conta pra baixo
// Ver qual soma é mais frequente
// Caso tenha a mesma quantidade de frequancias pra mais de uma soma de subarvore, retorna todas elas

int SomadorSub (struct TreeNode* root, int * Somador, int * Indice) {

    // root = Raiz

    if (root == NULL) {

        return 0; 
    }

    int SomaEsquerda = 0;
    int SomaDireita = 0;
    int TotalSoma = 0;

    SomaEsquerda = SomadorSub (root -> left, Somador, Indice);
    SomaDireita = SomadorSub (root -> right, Somador, Indice);

    TotalSoma = root -> val + SomaEsquerda + SomaDireita;

    Somador[(*Indice)++] = TotalSoma;

    return TotalSoma;

}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    
    if (root == NULL) {

        return NULL;

    }

    // int Somador [1000];
    
    int * Somador;

    Somador = (int *) malloc (1000 * sizeof(int));

    int Indice = 0;

    SomadorSub (root, Somador, &Indice);

    int i;
    int MaiorSoma = 0;
    int MenorSoma = 0;

    for (i = 0; i < Indice; i++) {

        if (Somador[i] > MaiorSoma) {

            MaiorSoma = Somador[i];

        }

        if (Somador[i] < MenorSoma) {

            MenorSoma = Somador[i];
            
        }

    }

    int TamanhoVetor;

    TamanhoVetor = MaiorSoma - MenorSoma;

    int * Frequencia;

    Frequencia = (int *) malloc (TamanhoVetor * sizeof(int));
    //int Frequencia[1000] = {0};
    int MaiorFrequencia = 0;

    // Esquema de contar caracteres de string, EXCETO QUE EXISTEM NUMEROS NEGATIVOS AAAAAAAAAA
    
    for (i = 0; i < Indice; i++) {

        Frequencia[Somador[i]]++; 
        
        if (Frequencia[Somador[i]] > MaiorFrequencia) {

            MaiorFrequencia = Frequencia[Somador[i]];

        }
    }

    int Cont = 0;

    for (i = 0; i < 1000; i++) {
        
        if (Frequencia[i] == MaiorFrequencia) {

            Cont++;
        }
    }

    int * Resultado;
    int ResultadoIndice = 0;

    Resultado = (int *) malloc (Cont * sizeof(int));

    for (i = 0; i < 1000; i++) {
        
        if (Frequencia[i] == MaiorFrequencia) {

            Resultado[ResultadoIndice++] = i;

        }
    }

    *returnSize = Cont;

    return Resultado;

}