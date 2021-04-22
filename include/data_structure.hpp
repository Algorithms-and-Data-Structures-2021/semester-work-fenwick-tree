#pragma once

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

    int *PreProc();

    int getSumFromZero(int fw[], int i);

    int getSum(int fw[], int l, int r);

    static void updateFW(int fw[], int n, int i, int newVal);
  };
} // namespace itis