/* 2019/8/10 Dijkstra's Algorithm created by seriru */

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>

using namespace std;
using ll = long long;

constexpr ll INF = 10000000000000000;

struct Edge {
  ll to;
  ll cost;

  bool operator>(Edge const& rhs) { return cost > rhs.cost; }
  bool operator<(Edge const& rhs) { return cost < rhs.cost; }
  bool operator>=(Edge const& rhs) { return cost >= rhs.cost; }
  bool operator<=(Edge const& rhs) { return cost <= rhs.cost; }
};

// dijkstra's法 O(|V|log|E|)
using P = pair<ll, ll>;
vector<ll> dijkstra(
  vector<vector<Edge>> const& graph, 
  ll const s, 
  ll const n
) 
{
  vector<ll> d(n+1, INF);
  d[s] = 0;
  priority_queue<P, vector<P>, std::greater<P>> que;
  // (cost, vertex)
  que.push(make_pair(0, s));

  while (!que.empty()) {
    P e = que.top();
    que.pop();
    
    if (d[e.second] < e.first) continue;
    for (auto itr : graph[e.second]) {
      if (d[itr.to] > d[e.second] + itr.cost) {
        d[itr.to] = d[e.second] + itr.cost;
        que.push(P(d[itr.to], itr.to));
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

  auto d = dijkstra(graph, 0, n);

  for (int i = 0; i < n; ++i) {
    cout << "shortest cost " << i << " " << d[i] << endl;
  }
}