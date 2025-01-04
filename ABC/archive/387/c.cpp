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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll l,r;cin>>l>>r;
  auto f = [](ll x) -> ll {
    if(x<10) return 0;
    string s = to_string(x);
    int n = s.size();
    vector dp(n,vector(10,vector<ll>(2,0)));
    reps(j,1,s.front()-'0') dp.at(0).at(j).at(0) = 1;
    dp.at(0).at(s.front()-'0').at(1) = 1;
    rep(i,n-1) rep(j,10) {
      if(j==0) {
        if(i==n-2) continue;
        reps(jj,1,10) dp.at(i+1).at(jj).at(0)++;
      } else {
        dp.at(i+1).at(j).at(0) += dp.at(i).at(j).at(0)*j;
        if(s.front()>s.at(i+1)) dp.at(i+1).at(j).at(1) += dp.at(i).at(j).at(1);
        dp.at(i+1).at(j).at(0) += dp.at(i).at(j).at(1)*min((ll)(s.at(i+1)-'0'),j);
      }
    }
    ll ret = 0;
    reps(j,1,10) rep(k,2) ret += dp.at(n-1).at(j).at(k);
    return ret;
  };
  ll ans = 0;
  ans += f(r);
  ans -= f(l-1);
  cout << ans << endl;

  return 0;
}
