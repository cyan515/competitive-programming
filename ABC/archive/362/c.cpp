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
  vector<ll> a(n),b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  vector<ll> x(n);
  bool ok = true;
  ll sa = 0;
  {
    ll sb = 0;
    rep(i,n) sa += a.at(i);
    rep(i,n) sb += b.at(i);
    ok &= sa <= 0;
    ok &= 0 <= sb;
  }
  rep(i,n) {
    ll diff = b.at(i) - a.at(i);
    ll ad = min(-sa,diff);
    sa += ad;
    x.at(i) = a.at(i)+ad;
  }
  if(ok) {
    cout << Yes << endl;
    rep(i,n) {
      if(i) cout << " ";
      cout << x.at(i);
    }
    cout << endl;
  } else {
    cout << No << endl;
  }

  return 0;
}
