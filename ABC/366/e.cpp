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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll lim = 2000100;
  ll n;cin>>n;
  ll d;cin>>d;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  sort(all(x));
  sort(all(y));
  ll a = 0;
  rep(i,n) {
    a += abs(-lim-x.at(i));
  }
  ll ans = 0;
  vector<ll> yy(lim*2+1,0);
  ll b = 0;
  rep(i,n) {
    b += abs(-lim-y.at(i));
  }
  int le = 0;
  reps(j,-lim,lim+1) {
    yy.at(j+lim) = b;
    while(le<n&&y.at(le)<=j) le++;
    b += le;
    b -= n-le;
  }
  sort(all(yy));
  le = 0;
  a+=n;
  reps(i,-lim,lim) {
    while(le<n&&x.at(le)<i) le++;
    a += le;
    a -= n-le;
    ll bb = d - a;
    if(bb<0) continue;
    ans += upper_bound(all(yy),bb) - yy.begin();
  }
  cout << ans << endl;

  return 0;
}
