#include <iostream>

#include <set>
#include <map>
using namespace std;

// 素因数分解
/*
 * [2]-> 5, [3] -> 5のとき N = 2^5 * 3^5
 */
template<typename T>
map<T, long long> factorize(T x) {
  map<T, long long> res;
  for (long long i = 2; i * i <= x; ++i) {
    while (x % i == 0) {
      x /= i;
      res[i] += 1;
    }
  }
  if (x != 1) res[x]++;
  return res;
}

// 素因数の計算(素因数だけ)
template <typename T>
set<T> factorize(T x) {
  set<T> res;
  for (long long i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      res.insert(i);
      while (x % i == 0) x /= i;
    }
  }
  return res;
}

// 約数の列挙
/*
 * 2, 4, 8 ... 的な
 */
template<typename T>
set<T> div_count(T x) {
  set<T> st;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      st.insert(i);
      st.insert(x/i);
    }
  }
  return st;
}
