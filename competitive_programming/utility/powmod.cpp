constexpr long long MOD = 10e9+7;

// 繰り返し2乗法を使ったべき乗計算
constexpr
long long powmod(long long n, long long k) {
  long long ret = 1;
  while (k) {
    if (k & 1) ret = ret * n % MOD;
    n = n * n % MOD;
    k >>= 1;
  }
  return ret;
}