#include <iostream>

#include <vector>
using namespace std;

template <class T = long long>
class Union_Find {
  using size_type = std::size_t;
  using _Tp = T;
public:

  vector<_Tp> par;

  const _Tp & operator[] (size_type child) {
    return -par[root(child)];
  }

  Union_Find(size_type n) : par(n, -1) {}
  void init(int n) {
    par.assign(n, -1);
  }

  _Tp root(size_type x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(size_type x, size_type y) {
    return root(x) == root(y);
  }

  bool merge(size_type x, size_type y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  _Tp size(int x) {
    return -par[root(x)];
  }
};
