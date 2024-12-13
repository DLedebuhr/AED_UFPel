bool isPalindrome(int x) {
    
    if (x < 0) {

        return false;

    }

    double original = x;
    double reverso = 0;
    int digito;

    while (x != 0) {

        digito = x % 10;
        
        reverso = ((reverso * 10) + digito);

        x = x / 10;

    }

    return (original == reverso);

}