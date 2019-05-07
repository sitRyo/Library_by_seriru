#include <iostream>
#include <vector>


#define MOD 1000000007
using namespace std;
using ll = long long;

// 参考にさせていただきました @http://drken1215.hatenablog.com/entry/2018/06/08/210000

/* Cut Cut Cut */

#define MAX 500010

class Combination {
  using _Tp = long long;
public:
  
  _Tp fac[MAX], finv[MAX], inv[MAX];

  Combination() {
    init();
  }

  void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
      fac[i] = fac[i-1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
      finv[i] = finv[i-1] * inv[i] % MOD;
    }
  }

  // n!! * k!^(-1) * ((n - k)!)^(-1)
  _Tp comb(_Tp n, _Tp k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k]* finv[n - k] % MOD) % MOD;
  }
};

/* END END */


// verify iroha con E 連呼
int main() {
  ll n, m;
  cin >> n >> m;
  
  Combination co;
 
  ll ans = 0;
  for (int k = 1; k <= min(n,m); ++k) {
    ans += co.comb(k, n - k) * co.comb(m - 1, k - 1) % MOD;
    ans %= MOD;
  }
  cout << (co.comb(n + m - 2, m - 1) - ans + MOD) % MOD << endl;
}