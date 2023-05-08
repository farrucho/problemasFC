int *fintv(int n){
    int *v; // NAO TEM MEMORIA ALOCADA é uma local variable
    v = new int[n]; // alocar memoria permanentemente
    /*int *v = new int[n]*/
    return v;
    /* NO FINAL DO PROGRAMA VAI CONTINUAR LA A MEMORIA, ENTAO TEMOS
    QUE FAZER
    delete ptr; -> int * ptr
    delete [] ptr; -> int ptr[5]*/
}
