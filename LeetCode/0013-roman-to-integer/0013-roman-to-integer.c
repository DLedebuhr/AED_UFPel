int romanToInt(char* s) {
    
    int TAM = strlen(s);

    int numerosConvertidos [TAM];

    char tabelaRomanos [7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int tabelaNumeros [7] = {1, 5, 10, 50, 100, 500, 1000};

    int i, j;

    for (i = 0; i < TAM; i++) {
        
        for (j = 0; j < 7; j++) {

            if (tabelaRomanos[j] == s[i]) {

                numerosConvertidos[i] = tabelaNumeros[j];
                break;

            }
        }
    }

    int resultado = 0;

    for (i = 0; i < TAM - 1; i++) {

        if (numerosConvertidos[i] >= numerosConvertidos[i + 1]) {

            resultado += numerosConvertidos[i];
            
        } else {

            resultado -= numerosConvertidos[i];
            
        }
    }

    resultado += numerosConvertidos[TAM - 1];

    return resultado;

}