#include <iostream>
#include <map>

/* CUT CUT CUT */
#include <vector>
using namespace std;

/* Union-Find-Tree */
/* 必ず要素数をコンストラクタに入れること */
template <class T = long long>
class Union_Find {
  using size_type = std::size_t;
  using _Tp = T;
public:

  vector<_Tp> par;
  vector<_Tp> rnk;

  // 親の根を返す。値の変更は認めない。
  const _Tp & operator[] (size_type child) {
    find(child);
    return par[child];
  }

  Union_Find (size_type n) {
    par.resize(n), rnk.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
      rnk[i] = 0;
    }
  }

  // 木の根を求める
  _Tp find(_Tp x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }

  // xとyの属する集合を併合
  void merge(_Tp x, _Tp y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rnk[x] < rnk[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rnk[x] == rnk[y]) rnk[x]++;
    }
  }

  // xとyが同じ集合に属するか否か
  bool same(_Tp x, _Tp y) {
    return find(x) == find(y);
  }
};

/* SNIPET END */

// verify ARC65_D 連結
int main() {
  int n,k,l;
  cin >> n >> k >> l;
  Union_Find<long long> uf_road(n+1), uf_train(n+1);

  int r,s;
  for (int i = 0; i < k; ++i) {
    cin >> r >> s;
    uf_road.merge(r, s);
  }

  for (int i = 0; i < l; ++i) {
    cin >> r >> s;
    uf_train.merge(r, s);
  }

  vector<pair<int,int> > com;
  map<pair<int,int>, int> mp;

  for (int i = 1; i <= n; ++i) {
    int a, b;
    a = uf_road[i];
    b = uf_train[i];
    com.push_back(make_pair(a,b));
    mp[make_pair(a,b)] += 1;
  }

  for (int i = 0; i < n; ++i) {
    cout << mp[com[i]] << " ";
  }
  cout << endl;
}