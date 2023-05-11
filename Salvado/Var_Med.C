#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// Função que me dá o total de elementos para não repetir código 

int total(vector<vector<int>> V)
{
    int total = 0;
    for (int i = 0; i < V.size(); i++)
    {
        for(int j= 0; j < V[i].size(); j++)
        {
            total +=1;
        }
    }

}

// Função que me dá a soma total dos elementos do vetor para não repetir código 

int soma (vector<vector<int>> V)
{
    int sum = 0;
     for (int i = 0; i < V.size(); i++)
    {
        for(int j= 0; j < V[i].size(); j++)
        {
            sum += V[i][j];
        }
    }
}
// Média 

double Media(vector<vector<int>> V)
{
    double Med = soma(V)/total(V); 
    return Med;
}

// Variância 

double Var(vector<vector<int>> V)
{
    double med = Media(V);
    int tot = total(V);
    int sum = soma(V);
    double Variancia = (1 / (tot -1)) * pow((sum-med),2);

    return Variancia;
}


// IMPRIMIR VALOR DE MÉDIA E DESVIO PADRÃO NO ECRÃ