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