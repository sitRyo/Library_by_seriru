#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/* CUT CUT */

// 最大公約数を求める(ユークリッドの互除法).
long long gcd (long long x, long long y) {
  if (y > x) swap(x,y);
  if (y == 0) return x;
  return gcd(x%y,y);
}

// 最小公倍数を求める(lcm(a,b) = a*b / gcd(a,b)). overflowに気をつけよう
ll lcm (long long  x, long long y) {
  ll t = gcd(x,y);
  return (x / t) * y;
}

/* END END */

// test
int main() {
  ll x,y;
  cin >> x >> y;
  cout << lcm(x,y) << endl;
}
