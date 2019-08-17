/* Binary Indexed Tree(Finwick Tree) referd to http://hos.ac/slides/20140319_bit.pdf */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define LEN 10000010
int N;
int bit[LEN];

// 負の数は2の補数
// a[index]をvalueだけ追加
void add(ll index, ll value) {
  for (int i = index; i <= N; i += i & (-i)) bit[i] += value;
}

// 1-indexed, a[1] ~ a[index] の総和
void get(ll index) {
  ll ret = 0;
  for (int i = index; i > 0; i -= i & (-i)) ret += bit[i];
}

int main() {}
