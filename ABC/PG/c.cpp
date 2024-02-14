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
  cin.tie(0) -> sync_with_stdio(0);
  ll n;cin>>n;
  ll m;cin>>m;
  string s;cin>>s;
  vector dp(n,vector<modint998244353>(m,0));
  dp.at(0).at((s.at(0)-'0')%m)++;
  rep(i,n-1) {
    dp.at(i+1).at((s.at(i+1)-'0')%m)++;
    rep(j,m) {
      dp.at(i+1).at((j*10+(s.at(i+1)-'0'))%m) += dp.at(i).at(j);
      dp.at(i+1).at(j) += dp.at(i).at(j);
    }
  }
  cout << dp.at(n-1).at(0).val() << endl;

  exit(0);
}
