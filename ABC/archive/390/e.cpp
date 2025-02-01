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
  int n,x;cin>>n>>x;
  vector<pair<ll,ll>> s,t,u;
  rep(i,n) {
    int v,a,c;cin>>v>>a>>c;
    if(v==1) {
      s.push_back(pair(a,c));
    } else if(v==2) {
      t.push_back(pair(a,c));
    } else {
      u.push_back(pair(a,c));
    }
  }
  auto f = [&x](vector<pair<ll,ll>>& vec) -> vector<vector<ll>> {
    int m = vec.size();
    vector dp(m+1,vector<ll>(x+1,0));
    rep(i,m) rep(j,x) {
      auto [a,c] = vec.at(i);
      chmax(dp.at(i+1).at(j),dp.at(i).at(j));
      if(j+c<=x) chmax(dp.at(i+1).at(j+c),dp.at(i).at(j)+a);
    }
    return dp;
  };
  auto dp = f(s);
  auto ep = f(t);
  auto fp = f(u);
  ll ok = 0;
  ll ng = INF;
  auto ff = [&](vector<vector<ll>>& vec, ll tgt) -> ll {
    ll ret = INF;
    rep(i,vec.size()) rep(j,vec.at(i).size()) {
      if(vec.at(i).at(j)>=tgt) chmin(ret,j);
    }
    return ret;
  };
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll ss = ff(dp,mid);
    ll tt = ff(ep,mid);
    ll uu = ff(fp,mid);
    if(ss==INF||tt==INF||uu==INF||ss+tt+uu>x) ng = mid;
    else ok = mid;
  }
  cout << ok << endl;

  return 0;
}
