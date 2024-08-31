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

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector dp(n+1,vector<ll>(2,0));
  dp.at(0).at(1) = -LINF;
  rep(i,n) {
    chmax(dp.at(i+1).at(0),dp.at(i).at(1)+a.at(i)*2);
    chmax(dp.at(i+1).at(0),dp.at(i).at(0));
    chmax(dp.at(i+1).at(1),dp.at(i).at(0)+a.at(i));
    chmax(dp.at(i+1).at(1),dp.at(i).at(1));
  }
  ll ans = 0;
  rep(j,2) chmax(ans,dp.at(n).at(j));
  cout << ans << endl;

  return 0;
}
