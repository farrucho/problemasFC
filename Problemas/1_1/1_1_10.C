#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int number = 0;
    for(int i = 0; i < 1000; i++){
        number = rand()%51 + 5;
        while(number == 5 || number == 55){
            number = rand()%51 + 5;
        }
        cout << number << endl;
    }
    return 0;
}