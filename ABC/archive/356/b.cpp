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
  ll n,m;cin>>n>>m;
  vector<ll> a(m);cin>>a;
  vector x(n,vector<ll>(m));
  rep(i,n) cin>>x.at(i);
  vector<ll> cnt(m,0);
  rep(i,n) {
    rep(j,m) cnt.at(j) += x.at(i).at(j);
  }
  bool ans = true;
  rep(i,m) ans &= cnt.at(i)>=a.at(i);
  if(ans) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
