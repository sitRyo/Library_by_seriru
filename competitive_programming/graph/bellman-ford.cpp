/* 2019/8/10 Bellman-Ford Algorithm created by seriru */

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;
using ll = long long;

constexpr ll INF = 10000000000000000;

struct Edge {
  ll to;
  ll cost;
};

// 最短距離の更新は |V| - 1 回行う。
vector<ll> bellmanFord(vector<vector<Edge>> graph, int n, int s, int g) {
  vector<ll> d(n+1, INF);
  d[s] = 0;
  int roopLimit = n - 1;

  for (int i = 0; i < roopLimit; ++i) {
    for (int v = 0; v < n; ++v) {
      for (auto e : graph[v]) {
        d[e.to] = min(d[e.to], d[v] + e.cost);
      }
    }
  }
  return d; 
}

int main() {
  int n, e;
  cin >> n >> e;

  vector<vector<Edge>> graph(n+1);
  
  for (int i = 0; i < e; ++i) {
    int to, from, cost;
    cin >> from >> to >> cost;
    graph[to].push_back({from, cost});
    graph[from].push_back({to, cost});
  }

  auto d = bellmanFord(graph, n, 0, n-1);

  for (int i = 0; i < n; ++i) {
    cout << "shortest cost " << i << " " << d[i] << endl;
  }
}