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
  int n;cin>>n;
  vector<ll> d(n);
  rep(i,n) cin>>d.at(i);
  ll l1,c1,k1,l2,c2,k2;cin>>l1>>c1>>k1>>l2>>c2>>k2;
  vector dp(n+1,vector<ll>(k1+1,LINF));
  dp.at(0).at(0) = 0;
  rep(i,n) rep(j,k1+1) rep(k,k1+1) {
    if(j+k>k1) break;
    ll rest = d.at(i)-l1*k;
    rest = max(rest,0LL);
    dp.at(i+1).at(j+k) = min(dp.at(i+1).at(j+k),dp.at(i).at(j) + (rest+l2-1)/l2);
  }
  ll ans = LINF;
  rep(i,k1+1) {
    if(dp.at(n).at(i)>k2) continue;
    ans = min(ans,i*c1+dp.at(n).at(i)*c2);
  }
  ans = ans==LINF?-1:ans;
  cout << ans << endl;

  exit(0);
}
