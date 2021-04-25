#pragma once

#include <vector>
namespace itis {

  struct FenwickTree {
   public:
    ~FenwickTree();

    int getSum(int fw[], int i);

    void updateFW(int fw[], int n, int i, int newVal);

    int *constructFenwick(int a[], int n);
  };
}  // namespace itis