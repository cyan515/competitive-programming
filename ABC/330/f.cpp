#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> x(n);
  vector<ll> y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  sort(all(x));
  sort(all(y));
  vector<ll> xs(n+1,0);
  vector<ll> ys(n+1,0);
  rep(i,n) xs.at(i+1) += xs.at(i)+x.at(i);
  rep(i,n) ys.at(i+1) += ys.at(i)+y.at(i);
  ll ok = LINF;
  ll ng = -1;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll x_mi = LINF;
    ll y_mi = LINF;
    rep(i,n) {
      ll cnt = 0;
      cnt += x.at(i)*i-xs.at(i);
      ll it = upper_bound(all(x),x.at(i)+mid) - x.begin();
      cnt += xs.at(n)-xs.at(it)-(x.at(i)+mid)*(n-it);
      x_mi = min(x_mi,cnt);
    }
    rep(i,n) {
      ll cnt = 0;
      cnt += y.at(i)*i-ys.at(i);
      ll it = upper_bound(all(y),y.at(i)+mid) - y.begin();
      cnt += ys.at(n)-ys.at(it)-(y.at(i)+mid)*(n-it);
      y_mi = min(y_mi,cnt);
    }
    if(x_mi+y_mi<=k) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  exit(0);
}
