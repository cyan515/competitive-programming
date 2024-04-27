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
  int q;cin>>q;
  vector<ll> r(n+1,0);
  rep(i,n) cin>>r.at(i+1);
  sort(all(r));
  rep(i,n) r.at(i+1) += r.at(i);
  while(q--) {
    ll x;cin>>x;
    int ans = upper_bound(all(r),x) - r.begin();
    if(ans) ans--;
    cout << ans << endl;
  }

  exit(0);
}
