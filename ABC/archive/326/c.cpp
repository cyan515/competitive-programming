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
  ll m;cin>>m;
  vector<ll> a(n);
  rep(i,n) cin>>a.at(i);
  sort(all(a));
  ll ans = 0;
  rep(i,n) {
    ll r = a.at(i)+m;
    ll cnt = lower_bound(all(a),r) - a.begin() - i;
    ans = max(ans,cnt);
  }
  cout << ans << endl;

  exit(0);
}
