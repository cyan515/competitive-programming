#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
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
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> xy(n);
  vector<ll> z(n);
  rep(i,n) cin>>x.at(i)>>y.at(i)>>z.at(i);
  rep(i,n) {
    ll sum = x.at(i) + y.at(i);
    ll half = sum / 2 + 1;
    xy.at(i) = max(0LL,half-x.at(i));
  }
  ll tgt = 0;
  rep(i,n) tgt += z.at(i);
  tgt /= 2; tgt++;
  vector dp(n,vector<ll>(tgt+100,LINF));
  rep(i,n) dp.at(i).at(0) = 0;
  reps(i,1,tgt+100) {
    if(i<=z.at(0)) dp.at(0).at(i) = xy.at(0);
  }
  reps(i,1,n) reps(j,1,tgt+100) {
    dp.at(i).at(j) = min(dp.at(i).at(j),dp.at(i-1).at(j));
    if(j<=z.at(i)) dp.at(i).at(j) = min(dp.at(i).at(j),xy.at(i));
    dp.at(i).at(min(j+z.at(i),tgt+99)) = min(dp.at(i).at(min(j+z.at(i),tgt+99)),dp.at(i-1).at(j)+xy.at(i));
  }
  ll ans = LINF;
  rep(i,n) {
    ans = min(ans,dp.at(i).at(tgt));
  }
  cout << ans << endl;

  exit(0);
}
