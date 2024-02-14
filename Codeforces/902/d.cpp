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
    if (EXPONENT & 1) RET = RET * BASE % MOD;
    BASE = BASE * BASE % MOD;
    EXPONENT >>= 1;
  }
  return RET;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n;cin>>n;
  vector<ll> a(n+1);
  rep(i,n) cin>>a.at(i+1);
  vector<ll> m(n+1,-LINF);
  for(int i=n;i>=1;i--) {
    ll ma = a.at(i);
    for(int j=i*2;j<=n;j+=i) {
      ma = max(ma,a.at(j));
    }
    m.at(i) = ma;
    for(int j=1;j*j<=i;j++) {
      if(i%j==0) {
        m.at(j) = max(m.at(j),ma);
        m.at(i/j) = max(m.at(n/j),ma);
      }
    }
  }
  // max element, can paint cnt sum
  vector<pair<ll,ll>> p(n+1,make_pair(0,0));
  rep(i,n) p.at(i+1).first=m.at(i+1),p.at(i+1).second=n/(i+1);
  sort(all(p));
  rep(i,n) p.at(i+1).second += p.at(i).second,p.at(i+1).second%=MOD;
  
  ll ans;
  
  rep(i,n) {
    ans += p.at(i+1).first * (powll(2,p.at(i+1).second)%MOD)%MOD;
  }
  
  cout << ans%MOD << endl;

  exit(0);
}
