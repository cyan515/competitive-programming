#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;ll m;cin>>m;
  vector a(n,vector<ll>(n));
  rep(i,n) cin>>a.at(i);
  auto s = a;
  rep(i,n) rep(j,n-1) {
    s.at(i).at(j+1) += s.at(i).at(j);
  }
  rep(j,n) rep(i,n-1) {
    s.at(i+1).at(j) += s.at(i).at(j);
  }
  vector cnt(n,vector(n,0));
  rep(i,n) rep(j,n) {
    if(i-m<0||j-m<0) continue;
    cnt.at(i).at(j) = s.at(i).at(j) - s.at(i-m).at(j) - s.at(i).at(j-m) + s.at(i-m).at(j-m);
  }
  

  return 0;
}
