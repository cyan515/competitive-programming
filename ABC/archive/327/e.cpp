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
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n) cin>>p.at(i);
  vector<long double> div(n+1);
  div.at(0) = 1;
  reps(i,1,n+1) {
    div.at(i) = div.at(i-1)*(long double)0.9+1;
  }
  vector dp(n+1,vector<long double>(n+1,-INF));
  dp.at(0).at(0) = 0;
  rep(i,n) rep(j,n) {
    if(dp.at(i+1).at(j)/div.at(j)<dp.at(i).at(j)/div.at(j)) {
      dp.at(i+1).at(j) = dp.at(i).at(j);
    }
    if(dp.at(i+1).at(j+1)/div.at(j+1)<dp.at(i).at(j)/div.at(j)) {
      dp.at(i+1).at(j+1) = dp.at(i).at(j)*(long double)0.9+(long double)p.at(i);
    }
  }
  
  long double ans = -INF;
  reps(i,1,n+1) ans = max(ans,dp.at(n).at(i)/div.at(i-1)-((long double)1200/sqrtl(i)));
  cout << fixed << setprecision(20);
  cout << ans << endl;

  exit(0);
}
