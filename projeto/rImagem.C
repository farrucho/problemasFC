#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    ifstream FI("./glassware_noisy.ascii.pgm");

    if(FI.is_open()){
        cout << "aberto ficheiro";   
        while(FI)
        {
            string line;
            getline(FI,line);
            istringstream iss(line);

            int nrows, ncols;
            iss >> ncols >> nrows;


            cout << nrows << " | " << ncols << endl;
        }
        
    }else{
        cout << "erro";
        return -1;
    }


}