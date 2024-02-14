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
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a.at(i);
    vector<ll> cnt(n,0);
    reps(i,1,n) {
      if(a.at(i-1)<a.at(i)) {
        ll x = a.at(i)/a.at(i-1);
        ll tmp = 0;
        while(x>1) tmp++,x/=2;
        cnt.at(i) = max(cnt.at(i-1) - tmp,0LL);
      } else if(a.at(i-1)==a.at(i)) {
        cnt.at(i) = cnt.at(i-1);
      } else {
        ll x = (a.at(i-1)+a.at(i)-1)/a.at(i);
        ll tmp = 0;
        bool flg = true;
        while(x>1) {
          tmp++;
          flg&=x%2==0;
          x/=2;
        }
        if(!flg) tmp++;
        cnt.at(i) = cnt.at(i-1) + tmp;
      }
    }
    ll ans = 0;
    rep(i,n) ans+=cnt.at(i);
    cout << ans << "\n";
  }

  exit(0);
}
