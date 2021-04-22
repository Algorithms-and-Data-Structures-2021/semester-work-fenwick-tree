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
  } // namespace itis