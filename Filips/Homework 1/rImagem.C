#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "open_writeFile.h"
#include "ReadImage.h"
#include "algoFiltro.h"
#include "invertImage.h"
#include "ColourFreq.h"
#include "Var_Med.h"

int main() {
    vector<vector<int>> mxOrig;
    try{
        ReadImage("glassware_noisy.ascii.pgm", mxOrig);
        cout << "Ficheiro Fechado"<< endl;
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

    // Media e variancia:
    
    cout << "Média: " << Media(mxOrig) << endl;
    cout << "Variância: " << Var(mxOrig) << endl;

    //Imagem Invertida:
    string nameImagInv = "glassware_noisy_inverted.ascii.pgm";
    vector<vector<int>> invMx;

    invertImage(255, mxOrig, invMx);
    open_writeFile(nameImagInv, invMx);
    /*
    // Sum check:
    for(int l= 0; l<320; l++) {
        for (int c=0; c<428; c++) {
            // if (mxOrig[l][c] + invMx[l][c] != 255) cout << "FALSE!!" << endl;
            // cout << mxOrig[l][c] + invMx[l][c] << endl;
        }
    }
    */
    cout << "Testing Sum" << endl;

    // Imagem Reduced noise:
    vector<vector<int>> redNoiseMx;
    vector<vector<int>> blurMx;

    vector<vector<double>> filterMxBlur(3, vector<double>(3, (1./9.)));

    double elem1 = 1./8.;
    vector<vector<double>> filterMxRedNoise = {
        {elem1, elem1, elem1},
        {elem1, 0., elem1},
        {elem1, elem1, elem1}
    };

    /* Zero Padding:

    redNoiseMx = algFilt_zeroPad(filterMxRedNoise, mxOrig);
    open_writeFile("glassware_reduced_noise.ascii.pgm", redNoiseMx);
    blurMx = algFilt_zeroPad(filterMxBlur, mxOrig);
    open_writeFile("glassware_box_blur.ascii.pgm", redNoiseMx);

    */

   /* Replicate Padding 
    redNoiseMx = algFilt_replicatePad(filterMxRedNoise, mxOrig);
    open_writeFile("glassware_reduced_noise.ascii.pgm", redNoiseMx);
    blurMx = algFilt_replicatePad(filterMxBlur, mxOrig);
    open_writeFile("glassware_box_blur.ascii.pgm", blurMx);
    */

    /* Mirror Padding 
    redNoiseMx = algFilt_mirrorPad(filterMxRedNoise, mxOrig);
    open_writeFile("glassware_reduced_noise.ascii.pgm", redNoiseMx);
    blurMx = algFilt_mirrorPad(filterMxBlur, mxOrig);
    open_writeFile("glassware_box_blur.ascii.pgm", blurMx);
    */

    /* Funciona mas aparece erro: free() invalid size: aborted
    redNoiseMx = algFilt_noPad(filterMxRedNoise, mxOrig);
    open_writeFile("glassware_reduced_noise.ascii.pgm", redNoiseMx);
    blurMx = algFilt_noPad(filterMxBlur, mxOrig);
    open_writeFile("glassware_box_blur.ascii.pgm", blurMx);
    */

    /* Uniform Distibuition
    redNoiseMx = algFilt_unifDist(filterMxRedNoise, mxOrig);
    open_writeFile("glassware_reduced_noise.ascii.pgm", redNoiseMx);
    blurMx = algFilt_unifDist(filterMxBlur, mxOrig);
    open_writeFile("glassware_box_blur.ascii.pgm", blurMx);
    */

   // To be done: Any distribuition and porportional distribuition

    
    return 0;
}
