#include <bits/stdc++.h>
// #include <atcoder/dsu>
// using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<int> solve(int n,int m,int h,vector<int>& a,vector<pair<int,int>>& edges,vector<int>& xs,vector<int>& ys) {
  vector<int> ret(n);
  vector graph(n,vector<int>());
  for(auto& [u,v] : edges) {
    graph.at(u).push_back(v);
    graph.at(v).push_back(u);
  }
  vector<bool> is_used(n,false);
  auto dfs = [&](auto f,int v,int dep) -> void {
    if(dep==10) return;
    for(auto nv : graph.at(v)) {
      if(is_used.at(nv)) continue;
      is_used.at(nv) = true;
      ret.at(nv) = v;
      f(f,nv,dep+1);
    }
  };
  rep(i,n) {
    if(is_used.at(i)) continue;
    ret.at(i) = -1;
    is_used.at(i) = true;
    dfs(dfs,i,0);
  }
  return ret;
}

int main() {
  int n,m,h;cin>>n>>m>>h;
  vector<int> a(n);cin>>a;
  vector<pair<int,int>> edges(m);
  rep(i,m) {
    int u,v;cin>>u>>v;
    edges.at(i) = pair(u,v);
  }
  vector<int> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  auto ans = solve(n,m,h,a,edges,x,y);
  rep(i,n) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  
  return 0;
}
