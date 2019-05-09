#include <iostream>

/* CUT CUT CUT */

#include <vector>
#include <queue>
using namespace std;

const long long INF = 10000000000000000; // 10e16

struct edge { long long to, cost;};
typedef pair<long long, long long> P_dij;

/* params
 * @s -> start, n -> 要素数, G -> グラフ, d -> 結果(参照渡し)
 * グラフの要素を0 ~ n - 1として見る
*/
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

/* END END END */

// verifiy shpc2018D Saving Snuuk


long long i, j, k;
 
int main(){
    long long n, m, s, t;
    cin >> n >> m >> s >> t;
    vector< vector<edge> > edge_yen(200001);
    vector< vector<edge> > edge_snu(200001);
    vector< long long > d1, d2;
    for(i=0; i<m; i++){
        long long u, v, a, b;
        cin >> u >> v >> a >> b;
        edge e1;
        e1.to = v, e1.cost = a;
        edge_yen[u].push_back(e1);
        edge e2;
        e2.to = u, e2.cost = a;
        edge_yen[v].push_back(e2);
        edge e3;
        e3.to = v, e3.cost = b;
        edge_snu[u].push_back(e3);
        edge e4;
        e4.to = u, e4.cost = b;
        edge_snu[v].push_back(e4);
    }
 
    dijkstra(s, n+1, edge_yen, d1);
    dijkstra(t, n+1, edge_snu, d2);
 
    long long ans[200001];
    long long Max = 0;
    long long FIRST = 1e15;
    for(i=n; i>=1; i--){
        long long val = FIRST - (d1[i] + d2[i]);
        Max = max(val, Max);
        ans[i] = Max;
    }
    for(i=1; i<=n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}