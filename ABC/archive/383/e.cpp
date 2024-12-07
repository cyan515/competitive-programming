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
  int n,m;cin>>n>>m;
  int k;cin>>k;
  vector g(n,vector<pair<ll,int>>());
  vector<tuple<ll,int,int>> es(m);
  rep(i,m) {
    int u,v,w;cin>>u>>v>>w;u--;v--;
    es.at(i) = tuple(w,u,v);
    // g.at(u).push_back(pair(w,v));
    // g.at(v).push_back(pair(w,u));
  }
  map<int,int> a,b;
  rep(i,k) {
    int aa;cin>>aa;aa--;a[aa]++;
  }
  rep(i,k) {
    int bb;cin>>bb;bb--;b[bb]++;
  }
  sort(all(es));
  vector<ll> cnt(n,0);
  for(auto [kk,v]:a) {
    cnt.at(kk)+=v;
  }
  for(auto [kk,v]:b) {
    cnt.at(kk)-=v;
  }
  dsu uf(n);
  ll ans = 0;
  rep(i,m) {
    auto [w,u,v] = es.at(i);
    if(uf.same(u,v)) continue;
    if(cnt.at(uf.leader(u))*cnt.at(uf.leader(v))<0) {
      ll x = abs(cnt.at(uf.leader(u)));
      ll y = abs(cnt.at(uf.leader(v)));
      ll z = min(x,y);
      ans += z*w;
    }
    ll temp = cnt.at(uf.leader(u))+cnt.at(uf.leader(v));
    uf.merge(u,v);
    cnt.at(uf.leader(u)) = temp;
  }
  cout << ans << endl;

  return 0;
}
