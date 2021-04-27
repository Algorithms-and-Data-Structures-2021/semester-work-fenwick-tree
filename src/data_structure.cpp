#include "data_structure.hpp"

#include <iostream>
using namespace std;
using namespace itis;

// Return sum from 0...i from array
int FenwickTree::getSumFromZero(int fw[], int i) {
  int sum = 0;
  // Fenwick's index start from 1
  i++;

  while (i > 0) {
    sum += fw[i];
    // i & (-i) returns the decimal value of last set digit
    // eg: if i = 12 (1100) then i & (-i) will 4 (100)
    i -= i & (-i);
  }
  return sum;
}

int FenwickTree::getSum(int fw[], int l, int r) {
  if (l) {
    return getSumFromZero(fw, r) - getSumFromZero(fw, l - 1);
  } else {
    return getSumFromZero(fw, r);
  }
}

// newVal will be updated to Fenwick and all its ancestor
void FenwickTree::updateFW(int fw[], int n, int i, int newVal) {
  // Fenwick's index start from 1
  i++;
  while (i <= n) {
    fw[i] += newVal;
    i += i & (-i);
  }
}

// Build Fenwick's tree
int *FenwickTree::constructFenwick(int a[], int n) {
  int *fw = new int[n + 1];
  for (int i = 0; i <= n; i++)
    fw[i] = 0;

  for (int i = 0; i < n; i++)
    FenwickTree::updateFW(fw, n, i, a[i]);

  return fw;
}