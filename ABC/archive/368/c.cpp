#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  vector<ll> h(n);cin>>h;
  ll ans = 0;
  rep(i,n) {
    ll ng = 0;
    ll ok = INF;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      ll right = ans+mid;
      ll d = mid;
      d += (right/3-ans/3)*2;
      if(d>=h.at(i)) ok = mid;
      else ng = mid;
    }
    ans += ok;
  }
  cout << ans << endl;

  return 0;
}
