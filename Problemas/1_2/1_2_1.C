#include<iostream>
using namespace std;

int* fintv(int n);
double* fdoublev(int n);

int main()
{
    int *a = fintv(100);
    double *b = fdoublev(100);
    
    cout << a << endl;
    cout << b << endl;

    // assign values to array 
    for(int i = 0; i < 100; i++){
        *(a+i) = i+1;// loop em todos os pointers e dar valor
    }

    for(int i = 0; i < 100; i++){
        cout << *(a+i) << " | " << a+i << endl;
    }

    return 0;
}

int* fintv(int n){
    int* ptr = new int[n];
    return ptr;
}

double* fdoublev(int n){
    double* ptr = new double[n];
    return ptr;
}