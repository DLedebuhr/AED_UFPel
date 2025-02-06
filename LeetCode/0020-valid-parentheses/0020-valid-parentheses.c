bool isValid(char* s) {

    char pilha [strlen(s)];

    int topo = -1;

    for (int i = 0; s[i] != 0; i++) {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{' ) {

            pilha[++topo] = s[i];

        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}' ) {

            if (topo == -1) {

                return false;

            } else if ( (s[i] == ')' && pilha[topo] == '(') || 
                        (s[i] == ']' && pilha[topo] == '[') || 
                        (s[i] == '}' && pilha[topo] == '{'))  {

                topo--;

            } else {

                return false;

            }
        }
    }

    return topo == -1;

}