#include <bits/stdc++.h>
using namespace std;
const ll LINF = 3001001001001001001;
using ll = long long;

/**
 * @fn
 * ダイクストラ法
 * @param 隣接リスト表現によるグラフ。pair は (weight, to)
 */
vector<ll> dijkstra(const vector<vector<pair<ll,int>>>& graph, const vector<int>& source_nodes = {0}) {
  
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  for(auto ele : source_nodes) q.push(pair(0,ele));
  vector<ll> dists(graph.size(),LINF);
  for(auto ele : source_nodes) dists.at(ele) = 0;
  while(q.size()) {
    auto [d,v] = q.top();q.pop();
    if(dists.at(v) < d) continue;
    for(auto [w,nv] : graph.at(v)) {
      if(dists.at(nv) <= dists.at(v)+w) continue;
      dists.at(nv) = dists.at(v) + w;
      q.emplace(dists.at(v)+w,nv);
    }
  }
  return dists;
}
