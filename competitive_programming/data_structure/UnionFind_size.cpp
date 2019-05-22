#include <iostream>

#include <vector>
using namespace std;

template <class T = long long>
class Union_Find {
  using size_type = std::size_t;
  using _Tp = T;
public:

  vector<_Tp> par;

  const _Tp operator[] (size_type child) {
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

// verify ABC120_D Decayid Bridge
 
int main() {
  long long n, m, ans = 0;
  cin >> n >> m;
  Union_Find<long long> uf(n);
 
  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    a[i] -= 1; b[i] -= 1;
  }
  long long con = (n * (n-1)) / 2;
  vector<long long> comf;
 
  for (int i = m - 1; i >= 0; --i) {
    comf.push_back(con);
    if (uf.issame(a[i], b[i])) {
      continue;
    }
    long long ta = uf.size(a[i]), tb = uf.size(b[i]);
    con -= ta * tb;
    uf.merge(a[i], b[i]);
  }
 
  for (int i = m - 1; i >= 0; --i) {
    cout << comf[i] << endl;
  }
}
