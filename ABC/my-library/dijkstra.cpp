#include <bits/stdc++.h>
using namespace std;
const ll LINF = 3001001001001001001;
using ll = long long;

// ダイクストラ法 dijkstra method
// G の pair は <辺の重み, 頂点番号> です。
vector<ll> dijkstra(const vector<vector<pair<ll,ll>>>& G,int V=0) {
  
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  q.emplace(0,V);
  vector<ll> dists(G.size(),LINF);
  dists.at(V) = 0;
  while(q.size()) {
    auto [d,v] = q.top();q.pop();
    if(dists.at(v) < d) continue;
    for(auto [w,nv] : G.at(v)) {
      if(dists.at(nv) <= dists.at(v)+w) continue;
      dists.at(nv) = dists.at(v) + w;
      q.emplace(dists.at(v)+w,nv);
    }
  }
  return dists;
}
