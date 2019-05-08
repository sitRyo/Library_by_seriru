// 参考にさせていただきました https://qiita.com/drken/items/cce6fc5c579051e64fab

#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
template<class T> 
class UnionFind {
  using _Tp = T;
  using size_type = std::size_t;
public:
  vector<int> par;
  vector<int> rank;
  vector<_Tp> diff_weight;
 
  UnionFind(int n = 1, _Tp SUM_UNITY = 0) {
    init(n, SUM_UNITY);
  }

  const _Tp & operator[] (size_type i) {
    root(i);
    return diff_weight[i];
  }
 
  void init(int n = 1, _Tp SUM_UNITY = 0) {
    par.resize(n); rank.resize(n); diff_weight.resize(n);
    for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
  }
 
  int root(int x) {
    if (par[x] == x) {
      return x;
    }
    else {
      int r = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = r;
    }
  }
 
  _Tp weight(int x) {
    root(x);
    return diff_weight[x];
  }
 
  bool issame(int x, int y) {
    return root(x) == root(y);
  }
 
  bool merge(int x, int y, _Tp w) {
    w += weight(x); w -= weight(y);
    x = root(x); y = root(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y), w = -w;
    if (rank[x] == rank[y]) ++rank[x];
    par[y] = x;
    diff_weight[y] = w;
    return true;
  }
 
  _Tp diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

// verify ABC87D Poeple on the line
 
int main() {
    int N, M;
    cin >> N >> M;
    UnionFind<int> uf(N);
    for (int i = 0; i < M; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        if (uf.issame(l, r)) {
            int diff = uf[r] - uf[l];
            if (diff != d) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            uf.merge(l, r, d);
        }
    }
    cout << "Yes" << endl;
}