#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
  ll n,x;cin>>n>>x;
  vector<ll> w(n),v(n);
  rep(i,n) cin>>w.at(i)>>v.at(i);
  vector dp(x+1,-LINF);
  vector dp2(x+1,vector<ll>(x+1,-LINF));
  ll BD = 500;
  dp.at(0) = 0;
  rep(i,n) for(ll j=x;j>=0;j--) {
    if(w.at(i)>BD) {
      for(ll k=0;j+w.at(i)*k<=x;k++) {
        chmax(dp.at(j+w.at(i)*k),dp.at(j)+v.at(i)*k-k*k);
      }
    } else {
      dp2.at(w.at(i)).at(i%w.at(i));
    }
  }
  ll ans = 0;
  rep(i,x+1) chmax(ans,dp.at(i));
  cout << ans << endl;

  return 0;
}
