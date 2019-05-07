#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

/* CUT CUT CUT */

template <class T>
void floyd_wardhall(vector< vector<T> > & cost, int N) {
  for (ll k = 0; k < N; ++k) {
    for (ll i = 0; i < N; ++i) {
      for (ll j = 0; j < N; ++j) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }
}

/* END */

// verify ABC79_D Wall
int main() {
  int h,w;
  cin >> h >> w;
 
  vector< vector<long long> > cost(10, vector<long long>(10));
  
  for (int i = 0; i < 10; ++i) 
    for (int j = 0; j < 10; ++j)
      cin >> cost[i][j];
  
  int wall[h][w]; 
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      cin >> wall[i][j];

  floyd_wardhall(cost, 10);

  ll ans = 0;
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
    if (wall[i][j] == -1 or wall[i][j] == 1) continue;
    ans += cost[wall[i][j]][1];
  }

  cout << ans << endl;
}