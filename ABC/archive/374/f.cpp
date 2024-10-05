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
  ll n,k,x;cin>>n>>k>>x;
  vector<ll> t(n);cin>>t;
  vector dp(n+1,vector(n+1,vector<ll>(k+1,LINF)));
  rep(i,n) rep(j,n) rep(s,k) {
    if(j>i) continue;
    chmin(dp.at(i+1).at(j).at(s),dp.at(i).at(j).at(s));
    
  }
  ll ans = LINF;
  rep(s,k+1) chmin(ans,dp.at(n).at(n).at(s));
  cout << ans << endl;

  return 0;
}
