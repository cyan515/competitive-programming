#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
// using mint = modint998244353;
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// https://atcoder.jp/contests/typical90/tasks/typical90_am
int main() {
  int n;cin>>n;
  vector g(n,vector<int>());
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector<int> s(n,0);
  vector<bool> seen(n,false);
  auto f = [&](auto ff,int v) -> int {
    seen.at(v) = true;
    int cnt = 1;
    for(auto nv : g.at(v)) {
      if(seen.at(nv)) continue;
      cnt += ff(ff,nv);
    }
    seen.at(v) = false;
    return s.at(v) = cnt;
  };
  f(f,0);
  ll ans = 0;
  ll cnt = 0;
  reps(i,1,n) cnt += s.at(i);
  rep(i,n) seen.at(i) = false;
  auto dfs = [&](auto dfs,int v) -> void {
    ans += cnt;
    seen.at(v) = true;
    for(auto nv : g.at(v)) {
      if(seen.at(nv)) continue;
      cnt -= s.at(nv);
      cnt += n-s.at(nv);
      dfs(dfs,nv);
      cnt += s.at(nv);
      cnt -= n-s.at(nv);
    }
    seen.at(v) = false;
  };
  dfs(dfs,0);
  cout << ans/2 << endl;
  
  return 0;
}
