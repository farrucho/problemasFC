#include<iostream>
#include<cmath>
using namespace std;

double func(double);
void func_ref(double x, double& f);
void func_ptr(double x, double* f);

int main()
{
    double x = 90;
    cout << func(x) << " | " << x << endl;
    func_ref(x, x);
    cout << x << endl;
    x=90;
    func_ptr(x, &x);
    cout << x << endl;


    return 0;
}

double func(double x){
    x*2;
    return sqrt(sin(x));
}

void func_ref(double x, double& f){
    x*2;
    f = sqrt(sin(x));
}

void func_ptr(double x, double* f){
    x*2;
    double& v = *f;
    v = sqrt(sin(x));
}

