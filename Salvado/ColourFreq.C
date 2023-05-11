#include "ColourFreq.h"
#include <vector>
#include <iostream>

using namespace std;

// Frequência absoluta 
vector<int> f_abs (vector<vector<int>> V, int N)
{
    vector <int> ColourFreq(N+1);
    fill(ColourFreq.begin(), ColourFreq.end(), 0);
    for(int i = 0; i<V.size(); i++)
    {
        for(int j = 0; j<V[i].size(); j++)
        {
            int idx;
            idx = V[i][j];
            ColourFreq[idx] += 1;
        }
    }
    return ColourFreq;
}

// Imprimir este vetor na main do final 

// Frequência Relativa

vector <double> f_rel(vector<int> V)
{
    int sum = 0;
    for (int i = 0; i < V.size(); i++)
    {
        sum += V[i];
    }

    vector <double> V_fr;
    double elem = 0;

    for(int j = 0; j < V.size(); j++){
        elem = (double) V[j]/sum*100;
        V_fr.push_back(elem);
    }
    return V_fr;

}

// Imprimir este resultado também (Imprimir com printf %2 -> 2 casas decimais)
