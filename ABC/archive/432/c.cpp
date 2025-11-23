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
  ll n,x,y;cin>>n>>x>>y;
  vector<ll>a(n);cin>>a;
  sort(all(a));
  {
    vector<ll> b(n);
    rep(i,n) b.at(i) = a.at(i)*x;
    bool ok = true;
    rep(i,n-1) {
      ok &= b.at(i)%abs(y-x) == b.at(i+1)%abs(y-x);
    }
    vector<ll> c(n);
    rep(i,n) c.at(i) = a.at(i)*y;
    ll b_ma = *max_element(all(b));
    ll c_mi = *min_element(all(c));
    if(c_mi<b_ma) ok = false;
    if(!ok) {
      cout << -1 << endl;
      return 0;
    }
  }
  ll ans = 0;
  rep(i,n) ans+=a.at(i);
  reps(i,1,n) {
    ll cnt = a.at(i)*y - a.front()*y;
    ans -= cnt / abs(y-x);
  }
  cout << ans << endl;

  return 0;
}
