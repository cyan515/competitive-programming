#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
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
  ll n,k;cin>>n>>k;
  string s;cin>>s;
  auto c = [&](int bit) {
    string t;
    rep(i,k) {
      t += (bit & (1 << i)) ? "B" : "A";
    }
    string u = t;
    reverse(all(u));
    return t==u;
  };
  vector dp(n+1,vector<mint>(1LL<<k,0));
  dp.front().front() = 1;
  rep(i,n) rep(bit,1LL<<k) {
    if(dp.at(i).at(bit)==0) continue;
    if(s.at(i)!='B') {
      ll nx = ((bit<<1)&((1<<k)-1));
      if(i+1<k||!c(nx)) dp.at(i+1).at(nx) += dp.at(i).at(bit);
    }
    if(s.at(i)!='A') {
      ll nx = (((bit<<1)|1)&((1<<k)-1));
      if(i+1<k||!c(nx)) dp.at(i+1).at(nx) += dp.at(i).at(bit);
    }
  }
  mint ans = 0;
  rep(i,1<<k) ans += dp.at(n).at(i);
  cout << ans.val() << endl;

  return 0;
}
