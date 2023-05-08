#include<iostream>
#include<cmath>
#include<array>


using namespace std;

double Soma(array<int,2> ilim, array<int,2> jlim){
    double result = 0;

    for(int i = ilim[0]; i <= ilim[1]; i++){
        for(int j = jlim[0]; j <= jlim[1]; j++){
            result += cos(pow(i,2) + sqrt(j));
        }
    }
    return result;
}

int main(){
    double result = Soma({0,100},{5,300});
    cout << "resultado da soma: " << result << std::endl;
    
    return 0;
}