#include "data_structure.hpp"

// файл с определениями

#include <iostream>
#include "data_structure.hpp"

namespace itis {

  // Build Fenwick's tree

  int *FenwickTree::PreProc() {
    int *fw = new int[size_ + 1];
    for (int i = 0; i <= size_; i++)
      fw[i] = 0;

    for (int i = 0; i < size_; i++)
      FenwickTree::updateFW(fw, size_, i, data_[i]);

    return fw;
  }

  //сумма элементов от l до r
  int FenwickTree::getSum(int *fw, int l, int r) {
    if (l) {
      return getSumFromZero(fw, r) - getSumFromZero(fw, l - 1);
    } else {
      return getSumFromZero(fw, r);
    }
  }
  //сумма элементов от 0 до x
  int FenwickTree::getSumFromZero(int *fw, int i) {
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

  //увеличение fx[i] на newVal
  void FenwickTree::updateFW(int *fw, int n, int i, int newVal) {
    // Fenwick's index start from 1
    i++;
    while (i <= n) {
      fw[i] += newVal;
      i += i & (-i);
    }
  }

  FenwickTree::~FenwickTree() {
    size_ = 0;
    data_ = nullptr;
  }
}

// namespace itis