#include "data_structure.hpp"

#include <iostream>
using namespace std;
using namespace itis;

// Return sum from 0...i from array
int FenwickTree::getSum(vector<long> fw, int i) {
  int sum = 0;
  // Fenwick's index start from 1
  i++;

  while (i > 0) {
    sum += fw[i];
    // i & (-i)  returns the decimal value of last set digit
    // eg: if i = 12 (1100) then  i & (-i) will 4 (100)
    i -= i & (-i);
  }
  return sum;
}

// newVal will be updated to Fenwick and all its ancestor
void FenwickTree::updateFW(vector<long> fw, int n, int i, int newVal) {
  // Fenwick's index start from 1
  i++;
  while (i <= n) {
    fw[i] += newVal;
    i += i & (-i);
  }
}

// Build Fenwick's tree
vector<long> FenwickTree::constructFenwick(vector<long> a, int n) {
  vector<long> fw(n + 1);
  for (int i = 0; i <= n; i++)
    fw[i] = 0;

  for (int i = 0; i < n; i++)
    FenwickTree::updateFW(fw, n, i, a[i]);

  return fw;
}

//int main() {
//  FenwickTree *fenwickTree;
//  vector<long> a = {1, 2, 3, 4, 5, 6, 7};
//  int n = sizeof(a) / sizeof(a[0]);
//  vector<long> fw = fenwickTree->constructFenwick(a, n);
//  cout << fenwickTree->getSum(fw, 4);
//  a[3] += 7;
//  fenwickTree->updateFW(fw, n, 3, 7);
//  cout << "\nAfter update ";
//  cout << fenwickTree->getSum(fw, 4) << "\n";
//  return 0;
//}
