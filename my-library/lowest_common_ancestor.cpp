#include <bits/stdc++.h>
using namespace std;

/**
 * lowest_common_ancestor(graph, root): 木 graph について、root を根として Lowest Common Ancestor を求める構造体<br/>
 * query(u,v): u と v の lowest_common_ancestor を求める。計算量 O(logn)
 * 前処理: O(nlogn)時間, O(nlogn)空間
 * @see https://algo-logic.info/lca/#
*/
struct lowest_common_ancestor {

  // graph.at(親) = 子どもの配列
  lowest_common_ancestor(const vector<vector<int>>& graph, const int& root = 0) {
    init(graph, root);
  }

  int query(int u, int v) {
    if (depth.at(u) < depth.at(v)) swap(u, v);  // u の方が深いとする
    int K = parent.size();
    // lowest_common_ancestor までの距離を同じにする
    for (int k = 0; k < K; k++) {
      if ((depth[u] - depth[v]) >> k & 1) {
        u = parent[k][u];
      }
    }
    // 二分探索で lowest_common_ancestor を求める
    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  int dist(int u,int v) {
    int lca = query(u,v);
    int ret = depth.at(u) + depth.at(v) - 2*depth.at(lca);
    return ret;
  }

private:
  vector<vector<int>> parent; // parent[k][u]:= u の 2^k 先の親
  vector<int> depth; // root からの距離

  // 初期化
  void init(const vector<vector<int>>& graph, const int& root = 0) {
    int vertices_count = graph.size();
    int K = 1;
    while ((1 << K) < vertices_count) K++;
    parent.assign(K, vector<int>(vertices_count, -1));
    depth.assign(vertices_count, -1);
    dfs(graph, root, -1, 0);
    for (int k = 0; k + 1 < K; k++) {
      for (int v = 0; v < vertices_count; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  // 根からの距離と1つ先の頂点を求める
  void dfs(const vector<vector<int>> &graph, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (auto e : graph[v]) {
      if (e != p) dfs(graph, e, v, d + 1);
    }
  }

};
