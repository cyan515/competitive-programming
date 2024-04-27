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
  ll n,m,p;cin>>n>>m>>p;
  vector<ll> as(n);
  vector<ll> bs(m);
  rep(i,n) cin>>as.at(i);
  rep(i,m) cin>>bs.at(i);
  vector<ll> bsum(m+1,0);
  sort(all(as));
  sort(all(bs));
  rep(i,m) bsum.at(i+1) += bsum.at(i),bsum.at(i+1)+=bs.at(i);
  ll ans = 0;
  for(ll a : as) {
    ll idx = lower_bound(all(bs),p-a) - bs.begin();
    ans += (m-idx)*p;
    ans += a*idx+bsum.at(idx);
  }
  cout << ans << endl;

  exit(0);
}
