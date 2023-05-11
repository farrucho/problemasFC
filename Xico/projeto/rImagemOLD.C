#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


/*
ESTADO:
bro por favor digam me como é que fizeram para converter em matriz
o meu metodo ta bue ranhoso

DAR RESHAPE DA MATRIZ

*/

vector<int> line_2_vector(string line);
vector<vector<int>> reshape(vector<vector<int>> originalVec, int m);
vector<int> line_2_vector(string line);



int main()
{

    
    ifstream FI("./glassware_noisy.ascii.pgm");

    if(FI.is_open()){
        cout << "aberto ficheiro" << endl;

        string line;
        vector<vector<int>> imagemVec; //inicializar melhor isto, ta a alocar mt memoria


        getline(FI, line);//dar skip da primeira linha pois nao interessa e não é int para nao complicar
        getline(FI, line);//dar skip da segunda
        getline(FI, line);//dar skip da terceira

        while(getline(FI, line)){ //enquanto nao chega ao final do ficheiro
            imagemVec.push_back(line_2_vector(line));
        }

        //teste para verificar se tem os pixeis certos
        int counter = 0;
        for(int i = 0; i < imagemVec.size(); i++){
            for(int j = 0; j < imagemVec[i].size(); j++){
                counter+=1;
            }
        }
        cout << "n pixels: " << counter << endl;

        vector<vector<int>> reshapeImage = reshape(imagemVec,428);
        for(int i = 0; i<reshapeImage.size();i++){
            //cout << reshapeImage[i].size();
        }

        //teste para verificar se tem os pixeis certos
        counter = 0;
        for(int i = 0; i < reshapeImage.size(); i++){
            for(int j = 0; j < reshapeImage[i].size(); j++){
                counter+=1;
            }
        }
        cout << "n pixels: " << counter << " rows: " << reshapeImage.size() << endl;

        
    }else{
        cout << "erro ao abrir ficheiro";
        return -1;
    }

}

vector<vector<int>> reshape(vector<vector<int>> originalVec, int m){
    vector<int> line;
    vector<vector<int>> vec;
    int counter = 0;


    for(vector<int> vi : originalVec){
        for(int i: vi){
            if(counter < m){
                line.push_back(i);
                counter+=1;
            }else{
                counter = 0;
                vec.push_back(line);
                line.clear();
                line.push_back(i);
            }
        }
    }
    
    if(!line.empty()){
        vec.push_back(line);
    }

    return vec;
}

vector<int> line_2_vector(string line){
    /*
        Algoritmo para converter string line do tipo "1 2 3" para vector de int
    */
    vector<int> vec;
    string stringnum;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ' ' || line[i] == '\n'){
            vec.push_back(stoi(stringnum));
            stringnum = "";
        }else{
            stringnum+=line[i];
            if(i == line.size()-1){
                vec.push_back(stoi(stringnum));
                stringnum = "";
            }
        }
    }
    return vec;
}