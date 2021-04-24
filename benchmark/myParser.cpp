//
// Created by akhme on 23.04.2021.
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

int main(){
  std::ifstream infile("infile.txt");//my file data(100).txt
//  std::ofstream outfile("outfile.txt");
  vector<int> ourTreeVector;

  if (!infile )
  {
    std::cout << "Error in opening file for reading !" << std::endl;
    return -1;
  }
  if (!outfile )
  {
    std::cout << "Error in opening file for writing !" << std::endl;
    return -1;
  }
  string str;
  while(getLine(infile, str)){

  }


}
