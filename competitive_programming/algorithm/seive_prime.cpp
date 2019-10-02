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

bool IsPrime(ll num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

