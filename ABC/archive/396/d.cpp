#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

int main() {
  ll n,m;cin>>n>>m;
  vector g(n,vector<pair<ll,int>>());
  rep(i,m) {
    ll u,v,w;cin>>u>>v>>w;u--;v--;
    g.at(u).push_back(pair(w,v));
    g.at(v).push_back(pair(w,u));
  }
  vector<bool> seen(n,false);
  ll ans = LINF;
  ll cur = 0;
  auto dfs = [&](auto f,int v) -> void {
    if(v==n-1) {
      ans = min(ans,cur);
      return;
    }
    for(auto [w,nv] : g.at(v)) {
      if(seen.at(nv)) continue;
      seen.at(nv) = true;
      cur ^= w;
      f(f,nv);
      seen.at(nv) = false;
      cur ^= w;
    }
  };
  seen.at(0) = true;
  dfs(dfs,0);
  cout << ans << endl;

  return 0;
}
