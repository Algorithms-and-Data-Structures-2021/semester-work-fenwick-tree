#pragma once

#include <vector>
using namespace std;
namespace itis {

  struct FenwickTree {
   public:
    ~FenwickTree();

    int getSum(vector<long> fw, int i);

    void updateFW(vector<long> fw, int n, int i, int newVal);

    vector<long> constructFenwick(vector<long> fw, int n);
  };
}  // namespace itis