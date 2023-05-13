#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "ReadImage.h"
#include "ColourFreq.h"


int main(){
    vector<vector <int>> mxOrig;
    try{
        mxOrig = ReadImage("glassware_noisy.ascii.pgm");
    }catch(...){
        cout << "Erro ao abrir ficheiro";
        return -1;
    }
    // Trocar pelo numero das cores, por agora vou criar manualmente:
    vector<int> ColourFreq(256);
    f_abs(mxOrig, 255, ColourFreq);
    vector<double> ColourRelFreq;
    f_rel(ColourFreq, 320, 428, ColourRelFreq);
    /*
    cout << "Tabela freq abs:" << endl;
    for (auto x: ColourFreq) {
        cout << x << endl;
    }

    cout << "Tabela freq rel:" << endl;
    for (auto y: ColourRelFreq) {
        cout << y << endl;
    }
    */
    



    return 0;
}

//meter link para imgur