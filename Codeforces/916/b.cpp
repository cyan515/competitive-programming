#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
ll powll(ll BASE, ll EXPONENT) {
  ll RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}
int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a.at(i);
    ll ans = 1;
    while(1) {
      ans *= 2;
      set<ll> st;
      rep(i,n) {
        st.insert(a.at(i)%ans);
        if(st.size()>2) break;
      }
      if(st.size()==2) break;
    }
    cout << ans << endl;
  }

  exit(0);
}
