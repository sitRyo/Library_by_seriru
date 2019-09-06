/* Binary Indexed Tree(Finwick Tree) referd to http://hos.ac/slides/20140319_bit.pdf */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace indexed1 {
constexpr int LEN = 10000010; // for c++11
int N = LEN;
int bit[LEN];

// 1-indexedなBIT

// 負の数は2の補数
// a[index]をvalueだけ追加
void add(ll index, ll value) {
  for (int i = index; i <= N; i += i & (-i)) bit[i] += value;
}

// 1-indexed, a[1] ~ a[index] の総和
ll get(ll index) {
  ll ret = 0;
  for (int i = index; i > 0; i -= i & (-i)) ret += bit[i];
  return ret;
}

// 1-indexed, a[x] ~ a[y]までの区間和を取る。
ll sum(int x, int y) {
  return get(y) - get(x);
}



}

namespace indexed0 {

constexpr int LEN = 10000010; // for c++11
int N = LEN;
int bit[LEN];

// 0-indexedなBIT

// 負の数は2の補数
// a[index]をvalueだけ追加
void add(ll index, ll value) {
  for (int i = index+1; i <= N; i += i & (-i)) bit[i] += value;
}

// 0-indexed, a[1] ~ a[index] の総和
ll get(ll index) {
  ll ret = 0;
  index += 1;
  for (int i = index; i > 0; i -= i & (-i)) ret += bit[i];
  return ret;
}

// 0-indexed, a[x] ~ a[y]までの区間和を取る。
ll sum(int x, int y) {
  return get(y) - get(x);
}

}

int main() {}
