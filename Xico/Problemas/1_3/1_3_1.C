#include<iostream>
using namespace std;

int main()
{
    auto fE = [](int n)->double{
        const double me = 9.109E-31;
        const double h = 6.626E-34;
        const double e_0 = 8.854E-12;
        double En = -me/(8*h*h*e_0*n*n);
        return En;
    }

    cout << fE(2) << endl;





    return 0;
}