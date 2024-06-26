#include <bits/stdc++.h>
using namespace std;

/**
 * LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
 * query(u,v): u と v の LCA を求める。計算量 O(logn)
 * 前処理: O(nlogn)時間, O(nlogn)空間
 * @see https://algo-logic.info/lca/#
*/
struct LCA {

  // G.at(親) = 子どもの配列
  LCA(const vector<vector<int>> &G, int root = 0) {
    init(G, root);
  }

  int query(int u, int v) {
    if (dists[u] < dists[v]) swap(u, v);  // u の方が深いとする
    int K = parent.size();
    // LCA までの距離を同じにする
    for (int k = 0; k < K; k++) {
      if ((dists[u] - dists[v]) >> k & 1) {
        u = parent[k][u];
      }
    }
    // 二分探索で LCA を求める
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
    int ret = dists.at(u) + dists.at(v) - 2*dists.at(lca);
    return ret;
  }

private:
  vector<vector<int>> parent; // parent[k][u]:= u の 2^k 先の親
  vector<int> dists; // root からの距離

  // 初期化
  void init(const vector<vector<int>> &G, int root = 0) {
    int V = G.size();
    int K = 1;
    while ((1 << K) < V) K++;
    parent.assign(K, vector<int>(V, -1));
    dists.assign(V, -1);
    dfs(G, root, -1, 0);
    for (int k = 0; k + 1 < K; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  // 根からの距離と1つ先の頂点を求める
  void dfs(const vector<vector<int>> &G, int v, int p, int d) {
    parent[0][v] = p;
    dists[v] = d;
    for (auto e : G[v]) {
      if (e != p) dfs(G, e, v, d + 1);
    }
  }

};
