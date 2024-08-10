#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

/// @brief 巡回セールスマン問題
/// @param dist 隣接行列によるグラフ表現
vector<vector<ll>> tsp(const vector<vector<ll>>& dist) {
  const ll LINF = 3001001001001001001;
  int n = dist.size();
  vector<vector<ll>> ret((1<<n),vector<ll>(n,LINF));
  rep(bit,1<<n) rep(from,n) {
    if(((bit&(1<<from))==0)&&(bit!=0)) continue;
    rep(to,n) {
      if(((bit&(1<<to))==0)&&(dist.at(from).at(to)<LINF)) {
        int v = (bit|(1<<to));
        ret.at(v).at(to) = min(ret.at(v).at(to),ret.at(bit).at(from)+dist.at(from).at(to));
      }
    }
  }
  return ret;
}
