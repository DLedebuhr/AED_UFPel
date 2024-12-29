int removeDuplicates(int* nums, int numsSize) {
    
    int cont = 1;
    int i, j = 1;

    // int * aux = (int*) malloc(1 * sizeof(int));

    for (i = 1; i < numsSize; i++) {
        
        if (nums[i] == nums[i - 1]) {

            continue;

        } else {

            cont++; 

            //aux = (int*) realloc (aux, cont * sizeof(int));

            //aux[j] = nums[i];
            
            nums[j] = nums[i];
            
            j++;

        }
    }

    // for (i = 1; i < cont; i++) {
        
        // nums[i] = aux[i];

    // }

    // free(aux);
    
    return (cont);

}