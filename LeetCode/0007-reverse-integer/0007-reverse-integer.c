int reverse(int x){

    int Reverso = 0;

    while (x != 0) {

        if (Reverso > INT_MAX / 10 || Reverso < INT_MIN / 10) {

            return 0;  

        }
   
        Reverso = Reverso * 10 + x % 10;

        x = x / 10;

    }

    return Reverso;

}