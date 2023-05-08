#include<iostream>
#include"fintv.h"
//#include"fdoublev.h"

int main(){
    int *a = fintv(100);
    //double *a = fdoublev(100);

    for(int i = 0; i < 100; i++){
        a[i] = i+1;
    }
    
    for(int i = 0; i < 100; i++){
        std::cout << a[i] << std::endl;
    }

    return 0;
}

int raise(int x){
    if(x == 1){
        return 1; 
    }
    return raise(x-1) + 1 + 2*(x-1);
}