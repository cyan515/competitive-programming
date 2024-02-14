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

int main() {
  ll n;cin>>n;
  vector<ll> a(n+1);
  a.at(0) = 0;
  rep(i,n) cin>>a.at(i+1);
  int inv = inv_mod(n,MOD);
  vector<modint998244353> dp(n+1,0);
  dp.at(n) = a.at(n);
  modint998244353 s = a.at(n);
  rep(i,n) {
    dp.at(n-1-i) += s*inv + a.at(n-1-i);
    s += dp.at(n-1-i);
  }
  cout << dp.at(0).val() << endl;

  exit(0);
}
