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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  ll cnt = 0;
  ll mi = 0;
  rep(i,n) {
    cnt += a.at(i);
    mi = min(mi,cnt);
  }
  ll ans = abs(mi);
  rep(i,n) ans += a.at(i);
  cout << ans << endl;

  exit(0);
}
