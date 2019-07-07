/* BFS(幅優先探索)の雛形 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// CUT CUT
constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
using pl = pair<ll, ll>;
constexpr int WALL = 1;
constexpr ll inf = numeric_limits<ll>::max();

void bfs(vector<vector<ll>>& d, vector<vector<ll>> const& maze, int h, int w, pl s, pl g) {
  d.resize(h * w);
  for_each(d.begin(), d.end(), [](ll& element){ element = inf; });
  queue<pl> p;
  p.push(s);
  d[s.first][s.second] = 0;
  while (!p.empty()) {
    pl now = p.back();
    p.pop();
    if (now.first == g.first and now.second == g.second) break;
    for (int i = 0; i < 4; ++i) {
      ll nx = now.first + dx[i], ny = now.second + dy[i];
      if (nx >= 0 and nx < w and ny >= 0 and ny < h and maze[ny][nx] != WALL and d[ny][nx] == inf) {
        d[ny][nx] += d[now.first][now.second] += 1;
        p.push(pl(nx, ny));
      }
    }
  }
}

// END END

void debug(vector<vector<ll>> const& field) {
  for (auto y : field) {
    for (auto x : y) {
      cout << x << " ";
    }
    cout << "\n";
  }
}

int main() {
  
}