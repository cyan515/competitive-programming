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

ll powll(ll BASE, ll EXPONENT) {
  ll RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}
template <class T> bool overflow_if_mul(T a, T b) {
  return (std::numeric_limits<T>::max() / a) < b;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  auto cnt = [&](ll n,ll x,ll k) -> ll {
    if(k>=60) return 0;
    ll l = x;
    ll r = x;
    rep(i,k) {
      if(overflow_if_mul(l,2LL)||overflow_if_mul(r,2LL)) return 0;
      l = l*2, r = r*2+1;
    }
    if(n<l) return 0;
    else if(r<n) return r-l+1;
    else return n-l+1;
  };
  while(T--) {
    ll n,x,k;cin>>n>>x>>k;
    ll ans = cnt(n,x,k);
    ll tmp = x;
    rep(i,min(63LL,k)) tmp>>=1;
    if(tmp>0&&k) ans++;
    k-=2;
    while(k>=0 && x>1) {
      ans += cnt(n,x^1,k);
      x /= 2;
      k--;
    }
    cout << ans << "\n";
  }

  exit(0);
}
