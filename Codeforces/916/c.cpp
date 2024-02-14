#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    vector<ll> l(n),c(n);
    set<ll> r;
    rep(i,n) cin>>l.at(i);
    sort(all(l),greater<ll>());
    rep(i,n) {
      ll a;cin>>a;r.insert(a);
    }
    rep(i,n) cin>>c.at(i);
    sort(all(c),greater<ll>());
    vector<pair<ll,ll>> lr(n);
    rep(i,n) {
      auto it = r.lower_bound(l.at(i));
      lr.at(i) = make_pair(l.at(i),*it);
      r.erase(it);
    }
    auto cmp = [](pair<ll,ll> a,pair<ll,ll> b) -> bool {
      return a.second - a.first < b.second - b.first;
    };
    sort(all(lr),cmp);
    ll ans = 0;
    rep(i,n) {
      ans += (lr.at(i).second-lr.at(i).first) * c.at(i);
    }
    cout << ans << endl;
  }

  exit(0);
}
