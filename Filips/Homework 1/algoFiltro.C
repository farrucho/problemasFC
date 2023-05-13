#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "algoFiltro.h"
#include "ReadImage.h"
#include "open_writeFile.h"



/* Realizar os 2 algoritmos de pesos + 3 algoritmos de padding (zero padding, simmetric padding, e close value padding).
 Fazer também um algoritmo onde se ignora a borda e a nova imagem passa a ser Line-1 por Col-1.
 Para cada um destes realizar um void (passar por referencia) e um por copia. */

vector<vector<int>> addPadding(vector<vector<int>> mxOrig, int Line, int Col, int sizePad) {
    // Reshape mxFinal passed by reference to size wanted:
    int newL = Line + 2*sizePad;
    int newC = Col + 2*sizePad;
    vector<vector<int>> mxFinal(newL, vector<int> (newC, 0));

    /* Set values in the (sizePad + Lines + sizePad) x (sizePad + Cols + sizePad) matrix to the values of mxOrig
    in the (lines)x(cols) section of the mxFinal */
    for (int i=0; i<Line; i++) {
        for (int j=0; j<Col; j++) {
            mxFinal[sizePad+i][sizePad+j] = mxOrig[i][j];
        }
    }
    return mxFinal;
}

// Filter using zero Padding on borders

vector<vector<int>> algFilt_zeroPad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig) {
    vector<vector<int>> mxFinal;
    // Set values for number of columns and lines in original matrix and size of square filter matrix:
    int Line = mxOrig.size(); // Gets the number of lines
    int Col = mxOrig[0].size(); // Gets the number of collumns
    int NFiltro = mxFiltro.size(); // Assuming filter is a NxN matrix

    int sizePad = (NFiltro-1)/2; // Distance from center of square filter matrix to the border

    // Adds Padding to mxFinal (all set to zero)
    vector<vector<int>> mxPad = addPadding(mxOrig, Line, Col, sizePad);


     // Reshape mxFinal passed by reference to size wanted:
    mxFinal.resize(Line);
    for (int p=0; p<Line; p++) {
        mxFinal[p].resize(Col, 0);
    }

    // Filter application:
    double sum;
    // Gets the element in mxFinal to apply filter:
    for (int lFin=0; lFin<Line; lFin++) {
        for (int cFin=0; cFin<Col; cFin++) {
            // For the element in the position (lFin, cFin) in the mxFin, applies filter
            sum = 0.;
            for (int lFilt = -sizePad; lFilt <= sizePad; lFilt++) {
                for (int cFilt = -sizePad; cFilt <= sizePad; cFilt++) {
                    sum += (double)(mxPad[lFin+sizePad+lFilt][cFin+sizePad+cFilt])*mxFiltro[sizePad+lFilt][sizePad+cFilt];
                }
            }
            mxFinal[lFin][cFin] = (int) sum;
        }
    }
    return mxFinal;
}


vector<vector<int>> algFilt_replicatePad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig) {
    vector<vector<int>> mxFinal;
    // Set values for number of columns and lines in original matrix and size of square filter matrix:
    int Line = mxOrig.size(); // Gets the number of lines
    int Col = mxOrig[0].size(); // Gets the number of collumns
    int NFiltro = mxFiltro.size(); // Assuming filter is a NxN matrix

    int sizePad = (NFiltro-1)/2; // Distance from center of square filter matrix to the border

    // Adds Padding to mxFinal (all set to zero)
    vector<vector<int>> mxPad = addPadding(mxOrig, Line, Col, sizePad);

     // Reshape mxFinal passed by reference to size wanted:
    mxFinal.resize(Line);
    for (int p=0; p<Line; p++) {
        mxFinal[p].resize(Col, 0);
    }

    // Sets Values in Pad to replicate closest ones:
    // First the corners in mxPad:
    // Left Upper Corner:
    for (int lnewPad = -sizePad; lnewPad<=0; lnewPad++) {
        for (int cnewPad = -sizePad; cnewPad<=0; cnewPad++) {
            mxPad[sizePad+lnewPad][sizePad+cnewPad] = mxPad[sizePad][sizePad];
        }
    }
    // Right Upper Corner:
    for (int lnewPad = -sizePad; lnewPad<=0; lnewPad++) {
        for (int cnewPad = 0; cnewPad<=sizePad; cnewPad++) {
            mxPad[sizePad+lnewPad][sizePad+Col-1+cnewPad] = mxPad[sizePad][sizePad+Col-1];
        }
    }
    // Left Bottom Corner:
    for (int lnewPad = 0; lnewPad<=sizePad; lnewPad++) {
        for (int cnewPad = -sizePad; cnewPad<=0; cnewPad++) {
            mxPad[sizePad+Line-1+lnewPad][sizePad+cnewPad] = mxPad[sizePad+Line-1][sizePad];
        }
    }
    // Right Bottom Corner:
    for (int lnewPad = 0; lnewPad<=sizePad; lnewPad++) {
        for (int cnewPad = 0; cnewPad<=sizePad; cnewPad++) {
            mxPad[sizePad+Line-1+lnewPad][sizePad+Col-1+cnewPad] = mxPad[sizePad+Line-1][sizePad+Col-1];
        }
    }

    // Upper border:
    for (int lnewPad = -sizePad; lnewPad<0; lnewPad++) {
        for (int cPad = 0; cPad<Col; cPad++) {
            mxPad[sizePad+lnewPad][sizePad+cPad] = mxPad[sizePad][sizePad+cPad];
        }
    }
    // Lower Border:
    for (int lnewPad = 1; lnewPad<=sizePad; lnewPad++) {
        for (int cPad = 0; cPad<Col; cPad++) {
            mxPad[sizePad+Line-1+lnewPad][sizePad+cPad] = mxPad[sizePad+Line-1][sizePad+cPad];
        }
    }
    // Left Border:
    for (int lPad = 0; lPad<Line; lPad++) {
        for (int cnewPad = -sizePad; cnewPad<0; cnewPad++) {
            mxPad[sizePad+lPad][sizePad+cnewPad] = mxPad[sizePad+lPad][sizePad];
        }
    }
    // Right Border:
    for (int lPad = 0; lPad<Line; lPad++) {
        for (int cnewPad = 1; cnewPad<=sizePad; cnewPad++) {
            mxPad[sizePad+lPad][sizePad+Col-1+cnewPad] = mxPad[sizePad+lPad][sizePad+Col-1];
        }
    }

    // Filter application:
    double sum;
    // Gets the element in mxFinal to apply filter:
    for (int lFin=0; lFin<Line; lFin++) {
        for (int cFin=0; cFin<Col; cFin++) {
            // For the element in the position (lFin, cFin) in the mxFin, applies filter
            sum = 0.;
            for (int lFilt = -sizePad; lFilt <= sizePad; lFilt++) {
                for (int cFilt = -sizePad; cFilt <= sizePad; cFilt++) {
                    sum += (double)(mxPad[lFin+sizePad+lFilt][cFin+sizePad+cFilt])*mxFiltro[sizePad+lFilt][sizePad+cFilt];
                }
            }
            mxFinal[lFin][cFin] = (int) sum;
        }
    }
    return mxFinal;
}   

vector<vector<int>> algFilt_mirrorPad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig) {
    vector<vector<int>> mxFinal;
    // Set values for number of columns and lines in original matrix and size of square filter matrix:
    int Line = mxOrig.size(); // Gets the number of lines
    int Col = mxOrig[0].size(); // Gets the number of collumns
    int NFiltro = mxFiltro.size(); // Assuming filter is a NxN matrix

    int sizePad = (NFiltro-1)/2; // Distance from center of square filter matrix to the border

    // Adds Padding to mxFinal (all set to zero)
    vector<vector<int>> mxPad = addPadding(mxOrig, Line, Col, sizePad);

    // Reshape mxFinal passed by reference to size wanted:
    mxFinal.resize(Line);
    for (int p=0; p<Line; p++) {
        mxFinal[p].resize(Col, 0);
    }

    // Sets Values in Pad to mirror opossite ones:
    // First the corners in mxPad:
    // Left Upper Corner:
    for (int lnewPad = -sizePad; lnewPad<0; lnewPad++) {
        for (int cnewPad = -sizePad; cnewPad<0; cnewPad++) {
            mxPad[sizePad+lnewPad][sizePad+cnewPad] = mxPad[sizePad-lnewPad][sizePad-lnewPad];
        }
    }
    // Right Upper Corner:
    for (int lnewPad = -sizePad; lnewPad<0; lnewPad++) {
        for (int cnewPad = 1; cnewPad<=sizePad; cnewPad++) {
            mxPad[sizePad+lnewPad][sizePad+Col-1+cnewPad] = mxPad[sizePad-lnewPad][sizePad+Col-1-cnewPad];
        }
    }
    // Left Bottom Corner:
    for (int lnewPad = 1; lnewPad<=sizePad; lnewPad++) {
        for (int cnewPad = -sizePad; cnewPad<0; cnewPad++) {
            mxPad[sizePad+Line-1+lnewPad][sizePad+cnewPad] = mxPad[sizePad+Line-1-lnewPad][sizePad-cnewPad];
        }
    }
    // Right Bottom Corner:
    for (int lnewPad = 1; lnewPad<=sizePad; lnewPad++) {
        for (int cnewPad = 1; cnewPad<=sizePad; cnewPad++) {
            mxPad[sizePad+Line-1+lnewPad][sizePad+Col-1+cnewPad] = mxPad[sizePad+Line-1-lnewPad][sizePad+Col-1-cnewPad];
        }
    }

    // Upper border:
    for (int lnewPad = -sizePad; lnewPad<0; lnewPad++) {
        for (int cPad = 0; cPad<Col; cPad++) {
            mxPad[sizePad+lnewPad][sizePad+cPad] = mxPad[sizePad-lnewPad][sizePad+cPad];
        }
    }
    // Lower Border:
    for (int lnewPad = 1; lnewPad<=sizePad; lnewPad++) {
        for (int cPad = 0; cPad<Col; cPad++) {
            mxPad[sizePad+Line-1+lnewPad][sizePad+cPad] = mxPad[sizePad+Line-1-lnewPad][sizePad+cPad];
        }
    }
    // Left Border:
    for (int lPad = 0; lPad<Line; lPad++) {
        for (int cnewPad = -sizePad; cnewPad<0; cnewPad++) {
            mxPad[sizePad+lPad][sizePad+cnewPad] = mxPad[sizePad+lPad][sizePad-cnewPad];
        }
    }
    // Right Border:
    for (int lPad = 0; lPad<Line; lPad++) {
        for (int cnewPad = 1; cnewPad<=sizePad; cnewPad++) {
            mxPad[sizePad+lPad][sizePad+Col-1+cnewPad] = mxPad[sizePad+lPad][sizePad+Col-1-cnewPad];
        }
    }

    // Filter application:
    double sum;
    // Gets the element in mxFinal to apply filter:
    for (int lFin=0; lFin<Line; lFin++) {
        for (int cFin=0; cFin<Col; cFin++) {
            // For the element in the position (lFin, cFin) in the mxFin, applies filter
            sum = 0.;
            for (int lFilt = -sizePad; lFilt <= sizePad; lFilt++) {
                for (int cFilt = -sizePad; cFilt <= sizePad; cFilt++) {
                    sum += (double)(mxPad[lFin+sizePad+lFilt][cFin+sizePad+cFilt])*mxFiltro[sizePad+lFilt][sizePad+cFilt];
                }
            }
            mxFinal[lFin][cFin] = (int) sum;
        }
    }
    return mxFinal;
}

// This function resizes the original photo by eliminating borders in which the filter can´t be apllied:
vector<vector<int>> algFilt_noPad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig) {
    vector<vector<int>> mxFinal;
    // Set values for number of columns and lines in original matrix and size of square filter matrix:
    int Line = mxOrig.size(); // Gets the number of lines
    int Col = mxOrig[0].size(); // Gets the number of collumns
    int NFiltro = mxFiltro.size(); // Assuming filter is a NxN matrix

    int sizePad = (NFiltro-1)/2; // Distance from center of square filter matrix to the border

    // Reshape mxFinal passed by reference to size wanted:
    mxFinal.resize(Line-2*sizePad);
    for (int p=0; p<Line; p++) {
        mxFinal[p].resize(Col-2*sizePad, 0);
    }
    
    // Filter application:
    double sum;
    // Gets the element in mxFinal to apply filter:
    for (int lFin=sizePad; lFin<Line-sizePad; lFin++) {
        for (int cFin=sizePad; cFin<Col-sizePad; cFin++) {
            // For the element in the position (lFin, cFin) in the mxFin, applies filter
            sum = 0.;
            for (int lFilt = -sizePad; lFilt <= sizePad; lFilt++) {
                for (int cFilt = -sizePad; cFilt <= sizePad; cFilt++) {
                    sum += (double)(mxOrig[lFin+lFilt][cFin+cFilt])*mxFiltro[sizePad+lFilt][sizePad+cFilt];
                }
            }
            mxFinal[lFin-sizePad][cFin-sizePad] = (int) sum;
        }
    }
    return mxFinal;

}
vector<vector<int>> algFilt_unifDist (vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig) {
    vector<vector<int>> mxFinal;
    // Set values for number of columns and lines in original matrix and size of square filter matrix:
    int Line = mxOrig.size(); // Gets the number of lines
    int Col = mxOrig[0].size(); // Gets the number of collumns
    int NFiltro = mxFiltro.size(); // Assuming filter is a NxN matrix

    int sizePad = (NFiltro-1)/2; // Distance from center of square filter matrix to the border

    // Reshape mxFinal passed by reference to size wanted:
    mxFinal.resize(Line);
    for (int p=0; p<Line; p++) {
        mxFinal[p].resize(Col, 0);
    }


    // Set Values for loops
    double ctd;
    double numZeroOutSide;
    double numZeroInside;

    double elem_dif_zero;
    double fator;

    vector<vector<double>> mxFiltroUpdate;
    vector<double> dummyV;

    
    // First 2 for loops get the element l,c of the original matrix
    for (int l=0; l<Line; l++) {
        for (int c=0; c<Col; c++) {
                 
            // At the start of the loop for each element (l,c) the filter matrix is updated:
            for (int n1 = 0; n1 < NFiltro; n1++) {
                mxFiltroUpdate.push_back(dummyV);
                for (int n2=0; n2 < NFiltro; n2++) {
                    mxFiltroUpdate[n1].push_back(mxFiltro[n1][n2]);
                }
            }
            
            // Looping through the filtermatrix and OGMatrix to count the number of zeros (in and out), and number of outside elements:
            ctd = 0;
            numZeroInside = 0;
            numZeroOutSide = 0;
            for (int m1= -sizePad; m1<=sizePad; m1++) {
                for (int k1= -sizePad; k1<=sizePad; k1++) {
                    // Checks if the element c,j when put the filter matrix on top has elements outside:
                    if ((l+m1)<0 || (l+m1)>=Line || (c+k1)<0 || (c+k1)>=Col) {
                        // If that element is outside, then check if its a zero:
                        if (mxFiltroUpdate[sizePad+m1][sizePad+k1] == 0.) {
                            numZeroOutSide++;
                        }
                        ctd++; // Increases number of outside elements
                        mxFiltroUpdate[sizePad+m1][sizePad+k1] == 0.; 
                        // ^^ if its outside sets the filter matrix corresponding of the outside element to zero ^^

                    // Then if element is inside, check if its a zero:
                    } else {
                        if (mxFiltroUpdate[sizePad+m1][sizePad+k1] == 0.) {
                            numZeroInside++;
                        }  
                    }
                }
            }
            fator = 0;
            elem_dif_zero = 0;
            // (Set factor of multiplication, for a complete uniform distribution with zeros or the distributed value)
            elem_dif_zero = NFiltro*NFiltro - (numZeroInside+numZeroOutSide);
            fator = elem_dif_zero /(double) (elem_dif_zero - (ctd - numZeroOutSide));
            
            // Update filter
            
            for (int m2= -sizePad; m2<=sizePad; m2++) {
                for (int k2= -sizePad; k2<=sizePad; k2++) {
                    if (mxFiltroUpdate[sizePad+m2][sizePad+k2] != 0.) {
                        mxFiltroUpdate[sizePad+m2][sizePad+k2] *= fator;
                    }
                }
            }

            
            // Applies the fully updated filter to the element (l,c) of the matrix:
            for (int m3= -sizePad; m3<=sizePad; m3++) {
                for (int k3= -sizePad; k3<=sizePad; k3++) {
                    if ((c+k3)>=0 && (c+k3)<Col && (l+m3)>=0 && (l+m3)<Line) {
                        mxFinal[l][c] += int((double) (mxOrig[l+m3][c+k3]) * (mxFiltroUpdate[sizePad+m3][sizePad+k3]));
                    }
                }
            }            

            // Resets Updated filter matrix:
            for (int n3=0; n3<NFiltro; n3++) {
                mxFiltroUpdate[n3].clear();
            }
            mxFiltroUpdate.clear();
        }
    }
    return mxFinal;
}
