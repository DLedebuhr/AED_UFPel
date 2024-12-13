char* longestCommonPrefix(char** strs, int strsSize) {
    
    if (strsSize == 0) {

        return "";

    } else if (strsSize == 1) {

        return strs[0]; // Só tem uma palavra, logo o resultado só pode ser ela mesma

    }

    char * ref = strs[0];

    int tamanho = 0;

    int i, j;

    for (i = 0; ref[i] != '\0'; i++) {

        for (j = 1; j < strsSize; j++) {

            if (strs[j][i] == '\0' || strs[j][i] != ref[i]) {

                ref[i] = '\0'; // Termina o prefixo comum
                return ref;

            }
        }

        tamanho++;

    }

    return ref;
    
}