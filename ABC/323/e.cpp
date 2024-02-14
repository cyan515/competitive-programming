#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n,x;cin>>n>>x;
  vector<int> t(n);
  rep(i,n) cin>>t.at(i);
  vector<mint> dp(x+1,0);
  dp.at(0) = 1;
  rep(i,x+1) rep(j,n) {
    if(i+t.at(j)>x) continue;
    dp.at(i+t.at(j)) += dp.at(i)/n;
  }
  mint ans = 0;
  rep(i,min(x+1,t.at(0))) {
    ans += dp.at(x-i)/n;
  }
  cout << ans.val() << endl;

  exit(0);
}
