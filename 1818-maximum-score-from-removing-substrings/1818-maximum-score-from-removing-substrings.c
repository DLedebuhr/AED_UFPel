int removerSubstrings (char * s, char primeiro, char segundo, int xouy) {

    char pilha[strlen(s) + 1];
    int topo = 0;
    int pontos = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        pilha[topo++] = s[i];
          
        if (topo > 1 && pilha[topo - 2] == primeiro && pilha[topo - 1] == segundo) {
   
            topo = topo - 2;
            pontos++;

        } 
    }

    pilha[topo] = '\0';
    strcpy(s, pilha);
    
    return pontos * xouy;

}

int maximumGain(char* s, int x, int y) {
    
    int total = 0;

    if (x > y) {

        total += removerSubstrings (s, 'a', 'b', x);
        total += removerSubstrings (s, 'b', 'a', y);

    } else {

        total += removerSubstrings (s, 'b', 'a', y);
        total += removerSubstrings (s, 'a', 'b', x);

    }

    return total;

}
