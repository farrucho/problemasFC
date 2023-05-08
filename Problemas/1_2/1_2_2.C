#include<iostream>
using namespace std;

int** fintv(int n, int m);
double*** fdoublev(int n, int m);


int main()
{
    int **a = fintv(100,50);
    // return matrix of integers (100 x 50 x 20) set to 5
    double ***b = fdoublev(100, 50, 20);
    double ***c = fdoublev(100, 50); // default 3rd parameter


    for(int i = 0;i < 100; i++){
        for(int j = 0; j < 50;j++){
            cout << a[i][j] << endl;
        }
    }
    

    delete[] a;
    delete[] b;
    return 0;
}

int** fintv(int n, int m){
    int** ptrMatriz = new int*[n];
    /*
    M = [ ptr0 
          ...
          ...   -> n linhas
          
          ptrn]
    
    */

    for(int i = 0; i < n; i++){
        *(ptrMatriz+i) = new int[m];
    }

    // assign values to 1
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            *(*(ptrMatriz+i) + j) = 1;
            // aceder ao ponteiro da linha, somar j
        }
    }

    return ptrMatriz;
}

double*** fdoublev(int n, int m, int k = 1){
    double*** ptrMatriz = new double**[n];
    /*
    M = [
            [
                [[], []], [[], []]
            ],
            [
                [[], []], [[], []]
            ],
            [
                [[], []], [[], []]
            ],
        ]
    */

    for(int i = 0; i < n; i++){
        *(ptrMatriz + i) = new double*[m];;
        for(int j = 0; j < m; j++){
            *(*(ptrMatriz + i) + j) = new double[k];
        }
    }

    // assign values 5
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for(int p=0; p<k; p++) {
                *(*(*(ptrMatriz + i)+j)+k) = 5;
            }
        }
    }

    return ptrMatriz;
}