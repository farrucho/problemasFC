#include<iostream>
#include<vector>
using namespace std;

// ROOT

#include "TF1.h" //-Ipathdosincluedes g++ massacair.C `root-config --cflags --libs`
#include "TApplication.h"
#include "TCanvas.h"
#include "TSystem.h"

int main()
{
    double y0 = 200; // m
    double v0 = 25; // m/s
    double g = 9.80665; // m/s^2
    
    // lambda function
    auto y = [y0, v0, g](double t){
        return y0 + v0*t - 0.5*g*t*t;
    };
    cout << "t(s)=0.5 h(m)=" << y(0.5) << endl;
    
    vector<pair<double,double>> v; //há um elemento especifico de size 2 que se chama pair

    for(double i = 0; i < 10; i+=0.01){
        v.push_back(make_pair(i,y(i)));
    }

    for(auto p: v){
        cout << "t(s)=" << p.first << " y(m)=" << p.second << endl;
    }

    // time 
    int groundTime;
    for(int i = 0; i < v.size()-1; i++){
        if(v[i].second*v[i+1].second < 0){
            groundTime = i;
            break;
        }
    }
    cout << groundTime << endl;

    //aproximacao linear entre dois pontos
    double m_line = (v[groundTime].second - v[groundTime+1].second) /( v[groundTime].first + v[groundTime+1].first);
    double b_line = v[groundTime].second - m_line*v[groundTime].first;

    double t_crossing = -b_line/m_line;

    cout << v[groundTime].second << endl;
    cout << v[groundTime+1].second  << endl;
    cout << v[groundTime].first << endl;
    cout << v[groundTime+1].first  << endl;

    cout << "t_crossing(s)" << t_crossing << "y(t_crossing)" << y(t_crossing) << endl;

    auto f = [g](double* x, double* par){
        // x[0]: t
        // par[0]: yo
        // par[1]: v0
        return par[0] + par[1]*x[0] - 0.5*g*x[0]*x[0];
    };

    TF1 F("F", f, 0, 10, 2);
    F.SetParameters(y0, v0);
    TApplication A("A", 0, 0);
    TCanvas c("canvas", "canvas teste", 1000, 800);
    F.SetLineWidth(5);
    F.SetLineColor(kBlue+1);
    F.Draw();
    c.Update();
    gSystem->ProcessEvents();
    c.WaitPrimitive();
}