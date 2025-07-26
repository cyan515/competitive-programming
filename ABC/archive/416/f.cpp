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

int main() {
  int n;int k;cin>>n>>k;
  vector<ll> a(n);cin>>a;
  vector g(n,vector<int>());
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector dp(n,vector(k+1,vector<ll>(2,-LINF)));
  rep(i,n) rep(kk,2) dp.at(i).at(0).at(kk) = 0;
  auto f = [&](auto self,int v,int p) -> void {
    vector ep(g.at(v).size()+1,vector<ll>(k+1,-LINF));
    rep(i,g.at(v).size()) ep.at(i).at(0) = 0;
    vector<pair<ll,int>> cont;
    vector<pair<ll,int>> fin;
    rep(ii,g.at(v).size()) {
      int nv = g.at(v).at(ii);
      if(nv==p) continue;
      self(self,nv,v);
      rep(i,k+1) cont.push_back(pair(dp.at(nv).at(i).at(0),nv));
      rep(i,k+1) fin.push_back(pair(dp.at(nv).at(i).at(1),nv));
      rep(i,k+1) rep(j,k+1) rep(kk,2) {
        if(i+j>k) continue;
        chmax(ep.at(ii+1).at(i+j),ep.at(ii).at(i)+dp.at(nv).at(j).at(kk));
      }
    }
    sort(rall(cont));
    sort(rall(fin));
    rep(i,k+1) rep(j,k+1) {
      if(i+j>k) continue;
      // chmax(dp.at(v).at(i+j).at(),dp.at(v).at(i+j).at()+ep.back().at(j));
    }
  };
  f(f,0,-1);
  ll ans = 0;
  rep(i,n) rep(j,k+1) rep(kk,2) chmax(ans,dp.at(i).at(j).at(kk));
  cout << ans << endl;

  return 0;
}
