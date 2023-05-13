#include <vector>

using namespace std;

// My includes:
#include "invertImage.h"

// Function:
void invertImage(int N, vector<vector<int>> mxOrig, vector<vector<int>>& invMx) {

    // Get number of lines and collumns in mxOrig:
    int line = mxOrig.size();
    int col = mxOrig[0].size();

    //Reshape Matrix passed by reference to the size wanted:
    invMx.resize(line);
    for (int k=0; k<line; k++) {
        invMx[k].resize(col, 0);
    }

    // Set values to inverted:
    for (int i=0; i<line; i++) {
        for(int j=0; j<col; j++) {
            invMx[i][j] = N - mxOrig[i][j];
        }
    }
}
