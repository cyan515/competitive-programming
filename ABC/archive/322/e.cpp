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
  ll n,k,p;cin>>n>>k>>p;
  vector<ll> c(n);
  vector a(n,vector<ll>(k));
  rep(i,n) {
    cin>>c.at(i);
    rep(j,k) cin>>a.at(i).at(j);
  }
  map<vector<ll>,ll> dp;
  vector<ll> def(k,0);
  dp[def] = 0;
  rep(i,n) {
    map<vector<ll>,ll> cp = dp;
    for(auto [key,cost] : cp) {
      cost += c.at(i);
      vector<ll> kcp = key;
      rep(j,k) kcp.at(j)+=a.at(i).at(j),kcp.at(j)=min(kcp.at(j),p);
      if(dp.find(kcp)==dp.end()) {
        dp[kcp] = cost;
      } else {
        dp[kcp] = min(dp[kcp],cost);
      }
    }
  }
  ll ans = LINF;
  for(auto [key,val] : dp) {
    bool flg = true;
    rep(i,k) flg &= key.at(i)>=p;
    if(flg) ans = min(ans,val);
  }
  if(ans==LINF) ans=-1;
  cout << ans << endl;

  exit(0);
}
