#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

#include "Var_Med.h"

// ?? Verificar se existe forma mais eficiente utilizando o vetor de freq absolutas ??

// Média 
double Media(vector<vector<int>> mx) { // verificar se é mais eficiente passar por referencia
    int sum = 0;
    for (int i = 0; i < mx.size(); i++) {
        for(int j= 0; j < mx[0].size(); j++) {
            sum += mx[i][j];
        }
    }
    
    return (double)sum / (double)(mx.size()*mx[0].size());
}

// Variância 
double Var(vector<vector<int>> mx) {
    double med = Media(mx); // melhorar eficiencia disto t???? 2 loops desnecessario 
    //passar iptional argument na func media? ou calcular diretamente
    // a media neste loop, sem chamar a funcao
    double var = 0.;
    for (int i = 0; i < mx.size(); i++) {
        for(int j= 0; j < mx[0].size(); j++) {
            var += ((double) mx[i][j] - med)*((double) mx[i][j] - med);
        }
    }
    return var / (double)(mx.size()*mx[0].size() -1);
}


// IMPRIMIR VALOR DE MÉDIA E DESVIO PADRÃO NO ECRÃ