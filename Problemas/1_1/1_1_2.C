#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return pow(sin(x),2);
}

double z(double x){
    return x + f(x);
}


int main(){    
    double nums[3] = {0.4,2.1,1.5};

    for (double i : nums) {
        cout << z(i) << endl;
    }

}
