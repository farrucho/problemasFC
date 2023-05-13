using namespace std;

#ifndef ALGOFILTRO_H
#define ALGOFILTRO_H
#include <vector> // vector
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


// void algFilt_unifDistr_byWeight(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig, vector<vector<int>>& mxFinal);
vector<vector<int>> algFilt_zeroPad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig);

vector<vector<int>> addPadding(vector<vector<int>> mxOrig, int Line, int Col, int sizePad);

vector<vector<int>> algFilt_replicatePad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig);

vector<vector<int>> algFilt_mirrorPad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig);

vector<vector<int>> algFilt_noPad(vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig);

vector<vector<int>> algFilt_unifDist (vector<vector<double>> mxFiltro, vector<vector<int>> mxOrig);

#endif