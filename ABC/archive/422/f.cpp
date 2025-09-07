#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int n;
/**
 * @fn
 * ダイクストラ法
 * @param 隣接リスト表現によるグラフ。pair は (weight, to)
 */
vector<ll> dijkstra(const vector<vector<pair<ll,int>>>& graph) {
  
  queue<pair<ll,int>> q;
  rep(i,n) q.emplace(0,i*n);
  vector<ll> dists(graph.size(),LINF);
  rep(i,n) dists.at(i*n) = 0;
  while(q.size()) {
    auto [d,v] = q.front();q.pop();
    if(dists.at(v) < d) continue;
    for(auto [w,nv] : graph.at(v)) {
      if(dists.at(nv) <= dists.at(v)+w) continue;
      dists.at(nv) = dists.at(v) + w;
      q.emplace(dists.at(v)+w,nv);
    }
  }
  return dists;
}

int main() {
  int m;cin>>n>>m;
  vector<ll> w(n);cin>>w;
  set<pair<int,int>> es;
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    if(u==v) continue;
    es.insert(pair(u,v));
  }
  vector g(n*n,vector<pair<ll,int>>());
  for(auto [u,v] : es) {
    rep(i,n-1) {
      g.at(u+n*(i+1)).push_back(pair(w.at(u)*(i+1),v+n*i));
      g.at(v+n*(i+1)).push_back(pair(w.at(v)*(i+1),u+n*i));
    }
  }
  vector dist(n,vector<ll>(n,LINF));
  rep(i,n) dist.at(i).at(0) = 0;
  for(int i=n-1;i>0;i--) {
    rep(j,n) {
      for(auto [wt,nj] : g.at(j)) {
        chmin(dist.at(i-1).at(nj),dist.at(i).at(j)+wt);
      }
    }
  }
  rep(i,n) {
    ll ans = LINF;
    rep(j,n) {
      chmin(ans,dist.at(j).at(i));
    }
    cout << ans << endl;
  }

  return 0;
}
