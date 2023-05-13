#include <vector>
#include <iostream>

using namespace std;

#include "ColourFreq.h"

// Frequência absoluta 
void f_abs (vector<vector<int>> V, int N, vector<int>& vecFreqAbs) {
    vecFreqAbs.resize(N+1);
    for(int i = 0; i<V.size(); i++) { // fazer com mapsss??!!!!
        for(int j = 0; j<V[i].size(); j++) {
            vecFreqAbs[V[i][j]] += 1;
        }
    }
}

// Imprimir este vetor na main do final 

// Frequência Relativa: 
void f_rel(vector<int> V, int col, int row, vector<double>& vecFreqRel) {
    double Npixel = col*row; // numero de pixeis totais
    vecFreqRel.resize(V.size(), 0.); // Reshape do vector passado por referencia para o tamanho do vector V

    // Cálculo da frequencia relativa e sua atribuição às posicoes do vetor de freq. relativa
    for(int j = 0; j < V.size(); j++){
        vecFreqRel[j] = ((double) V[j] /Npixel)*100;
    }
}

// Imprimir este resultado também (Imprimir com printf %2 -> 2 casas decimais)