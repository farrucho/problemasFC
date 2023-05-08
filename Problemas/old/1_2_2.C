#include<iostream>

int** fintv(int n, int m){
    int* row;
    int** matriz;
    matriz = new int*[n];

    for(int i = 0; i < n; i++){
        matriz[i] = new int[m];
    }

    /*
    matriz = [
        [1,1,1,1],
        [1,1,1,1],
        [1,1,1,1],
        ]
    row = [1,1,1,1]


    int **matriz = new int*[3]
    */
   return matriz;
}


int main(){
    int **a = fintv(100,50);

    for(int i = 0;i < 100; i++){
        for(int j = 0; j < 50;j++){
            a[i][j] = i+j+2;
        }
    }

    for(int i = 0;i < 100; i++){
        for(int j = 0; j < 50;j++){
            std::cout << a[i][j] << std::endl;
        }
    }

    return 0;
}