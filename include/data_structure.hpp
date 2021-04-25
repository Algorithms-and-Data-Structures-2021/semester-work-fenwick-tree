#pragma once

#include <vector>
using namespace std;
namespace itis {

  struct FenwickTree {
   public:
    ~FenwickTree();

    int getSumFromZero(vector<long> fw, int i);

    int getSum(vector<long> fw, int l, int r);

    void updateFW(vector<long> fw, int n, int i, int newVal);

    vector<long> constructFenwick(vector<long> fw, int n);
  };
}  // namespace itis