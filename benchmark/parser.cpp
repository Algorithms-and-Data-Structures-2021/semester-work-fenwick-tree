//
// Created by akhme on 22.04.2021.
//


#include <iostream>
#include <math.h>
#include "ctime"
#include <iomanip>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/data_structure.hpp"
using namespace std;
using namespace itis;

vector<int> split(const string& s, char delimiter) {
  vector<int> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(stoi(token));
  }
  return tokens;
}

string absolutePathToInputFile = "dataset/getSumFromZero/data(100).txt"; // absolute path to file нигде не используется!!!!
int main() {
  ifstream infile(absolutePathToInputFile);
  string result = "";
  string line;

  while (getline(infile, line)) {
    // create structure here
    FenwickTree *fenwickTree;
    vector<int> intValues = split(line, ' '); // splitting by delimiter and creating vector with int values
  //  result = to_string(intValues.size()) + ","; // amount of elements. "," - delimiter
    double startTime = clock();
    // here is executing tests
    fenwickTree->getSumFromZero(intValues, 4);
    double endTime = clock();
    cout << endTime - startTime + "\n"; // output elements count and test complition time
  }
  infile.close();
  return result;
}


