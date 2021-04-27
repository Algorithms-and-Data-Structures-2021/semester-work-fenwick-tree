#pragma once

using namespace std;
namespace itis {

  struct FenwickTree {
   public:
    ~FenwickTree();

    int getSumFromZero(int fw[], int i);

    int getSum(int fw[], int l, int r);

    void updateFW(int fw[], int n, int i, int newVal);

    int *constructFenwick(int fw[], int n);
  };
}  // namespace itis