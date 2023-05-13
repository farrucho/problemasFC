using namespace std;

#ifndef READIMAGE_H
#define READIMAGE_H
#include <vector> // vector
#include <fstream> // operations with files
#include <iostream> // input and outputs
#include <sstream> // stream do file
#include <string> // string

vector<vector<int>> ReadImage(string filename);
void ReadImage(string filename, vector<vector<int>>& M);

#endif