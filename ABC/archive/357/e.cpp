#include <bits/stdc++.h>
#include <atcoder/scc>
#include <atcoder/dsu>
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

int main() {
  ll n;cin>>n;
  vector<int> g(n);
  vector rg(n,vector<int>());
  dsu uf(n);
  scc_graph scc(n);
  rep(i,n) {
    int a;cin>>a;a--;
    g.at(i) = a;
    rg.at(a).push_back(i);
    uf.merge(i,a);
    scc.add_edge(i,a);
  }
  ll ans = 0;
  vector<ll> c(n,-1);
  for(auto vec : scc.scc()) {
    if(vec.size()==1) continue;
    for(auto ele : vec) {
      c.at(ele) = vec.size();
    }
  }
  rep(i,n) {
    if(g.at(i)==i) c.at(i) = 1;
  }
  auto dfs = [&](auto dfs,int v,int num) -> ll {
    ll ret = 0;
    for(auto nv : rg.at(v)) {
      if(c.at(nv)!=-1) continue;
      c.at(nv) = dfs(dfs,nv,num+1);
    }
    return num+ret;
  };
  rep(i,n) {
    if(c.at(i)==-1) continue;
    dfs(dfs,i,c.at(i));
  }
  // map<int,ll> scnt;
  // for(auto vec : scc.scc()) {
  //   for(auto v : vec) {
  //     scnt[v] = vec.size();
  //   }
  // }
  // map<int,ll> cnt;
  // for(auto vec : uf.groups()) {
  //   ll ma = -LINF;
  //   for(auto v : vec) {
  //     chmax(ma,scnt[v]);
  //   }
  //   for(auto v : vec) {
  //     cnt[v] = ma;
  //   }
  // }
  // for(auto vec : uf.groups()) {
  //   int v = vec.front();
  //   ans += uf.size(v)*cnt[v];
  //   ll tail = uf.size(v)-cnt[v];
  //   ans += (1+tail)*tail/2;
  // }
  rep(i,n) ans += c.at(i);
  cout << ans << endl;

  return 0;
}
