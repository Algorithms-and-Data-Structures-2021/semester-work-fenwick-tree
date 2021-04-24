#pragma once

#include <vector>
namespace itis {

  struct FenwickTree {
   public:
    int* data_{nullptr};
    int size_;

    FenwickTree(int* data, int n) {
      this->size_ = n;
      data_ = data;
    }

    ~FenwickTree();

    std::vector<int> PreProc(std::vector<int> fw);

    int getSumFromZero(std::vector<int> fw, int i);

    int getSum(std::vector<int> fw, int l, int r);//переделать вектор

    static void updateFW(std::vector<int> fw, int n, int i, int newVal);
  };
} // namespace itis