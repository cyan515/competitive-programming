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
  vector<ll> a(n);cin>>a;
  vector<ll> w(n);cin>>w;
  ll ans = 0;
  vector x(n,vector<ll>());
  rep(i,n) {
    a.at(i)--;
    x.at(a.at(i)).push_back(w.at(i));
  }
  rep(i,n) sort(all(x.at(i)));
  rep(i,n) {
    rep(j,x.at(i).size()-1) {
      ans += x.at(i).at(j);
    }
  }
  cout << ans << endl;

  return 0;
}
