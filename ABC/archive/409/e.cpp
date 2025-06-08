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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<ll> x(n);cin>>x;
  vector g(n,vector<pair<ll,int>>());
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    ll w;cin>>w;
    g.at(u).push_back(pair(w,v));
    g.at(v).push_back(pair(w,u));
  }
  vector<ll> dp(n,0);
  ll ans = 0;
  auto dfs = [&](auto self,int v,int p) -> ll {
    ll ret = x.at(v);
    for(auto [w,nv] : g.at(v)) {
      if(nv==p) continue;
      ll temp = self(self,nv,v);
      ret += temp;
      ans += abs(temp)*w;
    }
    return ret;
  };
  dfs(dfs,0,-1);
  cout << ans << endl;

  return 0;
}
