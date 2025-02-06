bool isValid(char* s) {

    char pilha [strlen(s)];

    int topo = 0;

    for (int i = 0; s[i] != 0; i++) {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{' ) {

            pilha[topo++] = s[i];

        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}' ) {

            if (topo == 0) {

                return false;

            }

            if ((s[i] == ')' && pilha[topo - 1] == '(') || 
                (s[i] == ']' && pilha[topo - 1] == '[') || 
                (s[i] == '}' && pilha[topo - 1] == '{'))  {

                topo--;

            } else {

                return false;

            }
        }
    }

    return topo == 0;

}