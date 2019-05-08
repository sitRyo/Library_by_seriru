#include <iostream>
#include <vector>
using namespace std;

/* CUT CUT */
const long long SEG_MAX = 2147483647; // 2^31 - 1

template <class T>
class SegmentTreeRMQ {
  using size_type = std::size_t;
  using _Tp = T;

  int n;
  vector<T> dat;
public:
  // 数列を渡す。
  SegmentTreeRMQ(vector<_Tp> & v) {
    size_type size = v.size();
    n = 1;
    while (n < size) n *= 2;
    dat.resize(2 * n -1, SEG_MAX);
    
    for (int i = 0; i < size; ++i) dat[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; --i) dat[i] = min(dat[2 * i + 1], dat[2 * i + 2]); 
  }

  int getElements() {
    return n;
  }

  // 配列をアップデート(Ax成分をvalに変更。再帰的に木のRMQを変更する)
  void update(size_type x, _Tp val) {
    x += n - 1;
    dat[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      dat[x] = min (dat[2 * x + 1], dat[2 * x + 2]);
    }
  }

  // [a, b), k: 節点, [l,r) rはセグメント木の要素数 (n * 2 - 1);
  // 1,3を求めたいときは find(1, 3 + 1)
  _Tp find(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = this->n;
    if (r <= a or b <= l) return SEG_MAX;
    if (a <= l and r <= b) return dat[k];

    _Tp vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
    _Tp vr = find(a, b, 2 * k + 2, (l + r) / 2, r);

    return min(vl, vr);
  }
};

/* END END */

// verify DSL2_A AOJ
int main() {
  int n,q;
  cin >> n >> q;
  vector<long long> v(n, SEG_MAX);
  SegmentTreeRMQ<long long> rmq(v);

  for (int i = 0; i < q; ++i) {
    int a,b,c;
    cin >> a >> b >> c;
    if (a == 1) {
      cout << rmq.find(b,c + 1) << endl;
    } else {
      rmq.update(b,c);
    }
  }
}