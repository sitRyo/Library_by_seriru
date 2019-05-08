#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

vector<bool> SievePrimes(long long n) {
  vector<bool> primes(n,true);
  primes[0] = primes[1] = false;

  ll m = 2;
  while (m*m <= n) {
    if (primes[m]) {
      for (ll i = m; i <= n; i += m) {
        if (i == m) continue;
        if (primes[i]) {
          primes[i] = false;
        }
      }
    }
    m++;
  }

  return primes;
}
