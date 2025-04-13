#include <bits/stdc++.h>
using namespace std;

/**
 * @fn
 * 木の直径を求め、端点を (u, v) に格納する
 * 木の直径の長さを返却する
 * @brief 木の直径を求める
 * @param grpah 隣接リスト表現による木
 * @return 木の直径の長さ
 */
int tree_diameter(const vector<vector<int>> &graph, int *u = nullptr, int *v = nullptr) {
  const int INF = (1 << 30) - 1;
  int n = graph.size();
  auto bfs = [&](int s) -> vector<int> {
    vector<int> dists(n,INF);
    dists.at(s) = 0;
    queue<int> q;
    q.push(s);
    while(q.size()) {
      int v = q.front();q.pop();
      for(auto nv : graph.at(v)) {
        if(dists.at(nv)!=INF) continue;
        dists.at(nv) = dists.at(v) + 1;
        q.push(nv);
      }
    }
    return dists;
  };
  int x;
  {
    auto dists = bfs(0);
    int ma = -INF;
    for(int i = 0; i < n; i++) {
      if(ma < dists.at(i)) {
        ma = dists.at(i);
        x = i;
      }
    }
  }
  int y;
  int ret = -INF;
  {
    auto dists = bfs(x);
    for(int i = 0; i < n; i++) {
      if(ret < dists.at(i)) {
        ret = dists.at(i);
        y = i;
      }
    }
  }
  if(u) *u = x;
  if(v) *v = y;
  return ret;
}
