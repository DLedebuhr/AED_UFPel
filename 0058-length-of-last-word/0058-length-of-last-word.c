int lengthOfLastWord(char* s) {
    
    int i;
    int test = 0;
    int cont = 0;

    for (i = strlen(s) - 1; i >= 0; i--) {

        if (s[i] == ' ') {

            if (test) {

                break;

            }

        } else {

            cont++;
            test = 1;

        }
    }

    return cont;

}