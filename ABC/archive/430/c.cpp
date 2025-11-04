#include <bits/stdc++.h>
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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,a,b;cin>>n>>a>>b;
  string s;cin>>s;
  ll ans = 0;
  vector<ll> x(n+1,0),y(n+1,0);
  rep(i,n) {
    if(s.at(i)=='a') x.at(i+1)++;
    else y.at(i+1)++;
    x.at(i+1) += x.at(i);
    y.at(i+1) += y.at(i);
  }
  rep(i,n) {
    ll ca = x.at(i);
    ll cb = y.at(i);
    auto ait = lower_bound(all(x),a+ca) - x.begin();
    auto bit = lower_bound(all(y),b+cb) - y.begin();
    if(ait>bit) continue;
    ans += abs(ait-bit);
  }
  cout << ans << endl;

  return 0;
}
