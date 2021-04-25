//
// Created by akhme on 25.04.2021.
//
using namespace std;
int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(a)/sizeof(a[0]);
  int *fw = constructFenwick(a, n);
  cout<<getSum(fw, 4);
  a[3] += 7;
  updateFW(fw, n, 3, 7);
  cout<<"\nAfter update ";
  cout<<getSum(fw, 4) << "\n";
  return 0;
}