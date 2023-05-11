#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


vector<vector<int>> ReadImage(string filename);
void ReadImage(string filename, vector<vector<int>>& M);

int main(){
    try{
        vector<vector <int>> originalMatrix = ReadImage("glassware_noisy.ascii.pgm");
    }catch(...){
        cout << "Erro ao abrir ficheiro";
        return -1;
    }


    return 0;
}

vector<vector<int>> ReadImage(string filename){
    ifstream FI(filename);

    if(FI.is_open()){
        cout << "Ficheiro aberto" << endl;
        
        string line;

        int lines;
        int columns;
        string testStr;
        int testInt;

        FI >> testStr;
        FI >> columns >> lines;
        
        vector<vector<int>> matriz(lines,vector<int> (columns,0)); // inicializado a zeros

        FI >> testInt; // 255 linha 2

        int j = 0;
        int currentLineIndex = 0;
        vector<int> lineVector;
        while(j < lines*columns){
            int elem = 0;
            FI >> elem;
            if((j+1)%(columns) == 0 && j != 0){ // se chegou ao final da linha
                lineVector.push_back(elem);
                matriz[currentLineIndex] = lineVector;
                lineVector.clear();
                currentLineIndex+=1;
            }else{
                lineVector.push_back(elem);
            }
            j+=1;
        }
        FI.close();
        return matriz;
    }else{
        throw 505;
    }
    
}

void ReadImage(string filename, vector<vector<int>>& M){
    M = ReadImage(filename);
}