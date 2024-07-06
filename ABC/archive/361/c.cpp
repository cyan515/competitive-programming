#include <bits/stdc++.h>
#include <atcoder/segtree>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> a(n);cin>>a;
  sort(all(a));
  ll ans = LINF;
  rep(i,n) {
    if(i+n-1-k>=n) break;
    chmin(ans,a.at(i+n-1-k)-a.at(i));
  }
  cout << ans << endl;

  return 0;
}
