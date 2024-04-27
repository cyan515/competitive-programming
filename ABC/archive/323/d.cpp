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
  ll n;cin>>n;
  map<ll,ll> sc;
  rep(i,n) {
    ll s,c;cin>>s>>c;
    sc[s] = c;
  }
  ll ans = 0;
  for(pair<ll,ll> p : sc) {
    ll s = p.first;
    ll c = p.second;
    if(c==0) continue;
    while(1) {
      if(c%2==1) ans++;
      if(c==1) break;
      s *= 2;
      c /= 2;
      if(sc.find(s)!=sc.end()) c += sc[s],sc[s] = 0;
    }
  }
  cout << ans << endl;

  exit(0);
}
