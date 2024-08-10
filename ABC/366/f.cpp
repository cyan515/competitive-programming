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
  int k;cin>>k;
  vector<pair<ll,ll>> ab(n);
  rep(i,n) cin>>ab.at(i).first>>ab.at(i).second;
  sort(all(ab), [](pair<ll,ll> x,pair<ll,ll> y) -> bool {
    auto [a,b] = x;
    auto [c,d] = y;
    return (a-1)*d < (c-1)*b;
  });
  vector<ll> a(n),b(n);
  rep(i,n) {
    a.at(i) = ab.at(i).first;
    b.at(i) = ab.at(i).second;
  }
  vector dp(n+1,vector(k+1,vector<ll>(k+1,-LINF)));
  dp.at(0).at(0).at(0) = 1;
  rep(i,n) rep(j,k+1) {
    if(dp.at(i).at(j).at(0)==-LINF) continue;
    rep(s,k+1) chmax(dp.at(i+1).at(j).at(s),dp.at(i).at(j).at(s));
    if(j==k) continue;
    rep(s,k+1) chmax(dp.at(i+1).at(j+1).at(s),dp.at(i).at(j).at(s));
    for(int s=k;s>0;s--) {
      if(dp.at(i+1).at(j+1).at(s-1)==-LINF) continue;
      chmax(dp.at(i+1).at(j+1).at(s),dp.at(i+1).at(j+1).at(s-1)*a.at(i)+b.at(i));
    }
  }
  ll ans = 0;
  rep(i,k+1) chmax(ans,dp.at(n).at(k).at(i));
  cout << ans << endl;
  
  return 0;
}
