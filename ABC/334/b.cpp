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
template <class T> bool overflow_if_mul(T a, T b) {
  return (std::numeric_limits<T>::max() / a) < b;
}
int main() {
  ll a,m,l,r;cin>>a>>m>>l>>r;
  if(m==1) {
    cout << (r-l)+1 << endl;
    return 0;
  }
  a -= LINF/m*m;
  ll right,left;
  {
    ll ok = 0;
    ll ng = LINF;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      if(overflow_if_mul(mid,m) || a+mid*m>r) ng = mid;
      else ok = mid;
    }
    right = a+ok*m;
  }
  {
    ll ok = LINF;
    ll ng = 0;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      if(overflow_if_mul(mid,m) || a+mid*m>=l) ok = mid;
      else ng = mid;
    }
    left = a+ok*m;
  }
  ll ans = (right-left)/m+1;
  cout << ans << endl;

  exit(0);
}
