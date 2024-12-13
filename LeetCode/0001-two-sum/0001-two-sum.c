int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int i, j;
    int *resultado = malloc (sizeof(int) * 2);

    if (resultado == NULL) {

        printf("Erro ao alocar memoria para o Resultado!\n");

        *returnSize = 0;

        return NULL;

    }
    
    for(i = 0; i < numsSize; i++) {

        for (j = i + 1; j < numsSize; j++) {
            
            if (nums[i] + nums[j] == target){

                resultado[0] = i;
                resultado[1] = j;
                
                *returnSize = 2;

                return (resultado);

            }
        }
    }

    free (resultado);

    *returnSize = 0;
    
    return NULL;
    
}