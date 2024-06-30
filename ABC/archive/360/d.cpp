#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n,t;cin>>n>>t;
  string s;cin>>s;
  vector<ll> x(n);cin>>x;
  vector<pair<ll,char>> v(n);
  rep(i,n) v.at(i) = pair(x.at(i),s.at(i));
  sort(all(v));
  rep(i,n) {
    auto [aa,bb] = v.at(i);
    x.at(i) = aa;
    s.at(i) = bb;
  }
  vector<ll> r;
  ll ans = 0;
  rep(i,n) {
    if(s.at(i)=='1') r.push_back(x.at(i));
    else {
      auto it = lower_bound(all(r),x.at(i)-2LL*t);
      ans += r.end() - it;
    }
  }
  cout << ans << endl;

  return 0;
}
