#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
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
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector len(12,vector<ll>(n+1,0));
  mint ans = 0;
  rep(i,n) {
    ll l = to_string(a.at(i)).size();
    rep(j,12) {
      len.at(j).at(i+1)+=len.at(j).at(i);
      if(j==l) len.at(l).at(i+1)++;
    }
  }
  rep(i,n) {
    vector<mint> llen(12);
    rep(j,12) llen.at(j) = len.at(j).back();
    rep(j,12) llen.at(j) -= len.at(j).at(i+1);
    mint base = 1;
    rep(j,12) {
      ans += base*llen.at(j)*mint(a.at(i));
      base *= 10;
    }
    ans+=a.at(i)*i;
  }
  
  cout << ans.val() << endl;

  return 0;
}
