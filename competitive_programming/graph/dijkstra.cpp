#include <vector>
#include <queue>
using namespace std;

const long long INF = 10000000000000000; // 10e16

struct edge { long long to, cost;};
typedef pair<long long, long long> P_dij;

void dijkstra(const long long s, const long long n,
  vector< vector<edge> > const &G, vector<long long> & d){
  d.resize(n);
  for(int i=0; i<n; i++) d[i] = INF; 
  priority_queue<P_dij, vector<P_dij>, greater<P_dij>> que;
  d[s] = 0;
  que.push(P_dij(0, s));
  while (!que.empty()) {
    P_dij p = que.top();
    que.pop();
    long long v = p.second;
    if(d[v] < p.first)continue;
    for(int i=0;i<G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P_dij(d[e.to], e.to));
      }
    }
  }
}