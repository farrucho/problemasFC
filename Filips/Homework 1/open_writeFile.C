#include <vector> // vector
#include <fstream> // operations with files
#include <iostream> // input and outputs
#include <sstream> // stream do file
#include <string> // string


using namespace std;

// My includes:
#include "open_writeFile.h"

// Function to open and write to new file for a matrix
void open_writeFile (string filename, vector<vector<int>>& mx) {
    //Open new file with the string input
    ofstream Myfile(filename);

    // Check wheter new file is open or not
    if (!(Myfile.is_open())) {
        throw 505;
    } else {
        cout << "Ficheiro aberto para Escrita!" << endl;
        // Set number of lines, columns, and pixel values of the matrix
        int line = mx.size();
        int col = mx[0].size();
        int N = 255;

        //Write the first three lines
        Myfile << "P2\n";
        Myfile << col << " " << line << endl;
        Myfile << N << endl;

        // Write all the other lines from top to bottom (and left to right), with 20 values per line:
        int trocaLinha = 0;
        for (int i=0; i<line; i++) {
            for (int j=0; j<col; j++) {
                if (trocaLinha == 19) {
                    Myfile << mx[i][j] << endl;
                    trocaLinha = 0;
                } else {
                    Myfile << mx[i][j] << " ";
                    trocaLinha++;
                }
            }
        }
        Myfile.close();
        cout << "Ficheiro Fechado!" << endl;
    }
}
