#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

/**
 * @brief 巡回セールスマン問題
 * @param graph 隣接行列表現によるグラフ。
 * @param dists dists[i][j] = 初期状態において訪問した集合が i で最後に訪問した頂点が j のときのコスト
 */
void tsp(const vector<vector<ll>>& graph, vector<vector<ll>>& dists) {
  const ll LINF = 3001001001001001001;
  int n = graph.size();
  rep(bit,1<<n) rep(from,n) {
    if(((bit&(1<<from))==0)&&(bit!=0)) continue;
    rep(to,n) {
      if(((bit&(1<<to))==0)&&(graph.at(from).at(to)<LINF)) {
        int v = (bit|(1<<to));
        dists.at(v).at(to) = min(dists.at(v).at(to),dists.at(bit).at(from)+graph.at(from).at(to));
      }
    }
  }
}
