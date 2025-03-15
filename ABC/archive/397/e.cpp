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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  int k;cin>>k;
  vector g(n*k,vector<int>());
  rep(i,n*k-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector<bool> seen(n*k,false);
  bool ok = true;
  auto dfs = [&](auto d,int v) -> int {
    int x = 1;
    int c = 0;
    for(auto nv : g.at(v)) {
      if(seen.at(nv)) continue;
      seen.at(nv) = true;
      int diff = d(d,nv);
      c += diff>0;
      x += diff;
    }
    if(x>k) ok = false;
    else if(x==k) ok &= c<=2;
    else ok &= c<=1;
    return x%k;
  };
  seen.at(0) = true;
  dfs(dfs,0);
  cout << (ok?Yes:No) << endl;

  return 0;
}
