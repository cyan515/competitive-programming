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
  int n,m;cin>>n>>m;
  vector<ll> c(n);cin>>c;
  vector<ll> k(m);
  vector a(m,vector<ll>());
  vector x(n,set<int>());
  rep(i,m) {
    cin>>k.at(i);
    a.at(i).resize(k.at(i));
    cin>>a.at(i);
    rep(j,k.at(i)) a.at(i).at(j)--;
    rep(j,k.at(i)) {
      x.at(a.at(i).at(j)).insert(i);
    }
  }
  ll ans = LINF;
  ll cost = 0;
  vector<int> cnt(m,0);
  auto dfs = [&](auto self, int v) -> void {
    if(v==n) {
      bool ok = true;
      rep(i,m) ok &= cnt.at(i) >= 2;
      if(ok) chmin(ans,cost);
      return;
    }
    self(self,v+1);
    cost += c.at(v);
    for(auto ele : x.at(v)) cnt.at(ele)++;
    self(self,v+1);
    cost += c.at(v);
    for(auto ele : x.at(v)) cnt.at(ele)++;
    self(self,v+1);
    cost -= c.at(v)*2LL;
    for(auto ele : x.at(v)) cnt.at(ele)-=2;
  };
  dfs(dfs,0);
  if(ans==LINF) ans = -1;
  cout << ans << endl;

  return 0;
}
