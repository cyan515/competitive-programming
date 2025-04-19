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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(m),b(m);
  rep(i,m) cin>>a.at(i)>>b.at(i);
  rep(i,m) a.at(i)--, b.at(i)--;
  map<ll,ll> mp;
  auto f = [&](ll s,ll t) -> ll {
    return s*1000000LL+t;
  };
  rep(i,m) {
    ll x = a.at(i);
    ll y = n-b.at(i);
    if(x<y) {
      mp[f(min(a.at(i)-x,(b.at(i)+x)%n),max(a.at(i)-x,(b.at(i)+x)%n))]++;
    } else if(x>y) {
      mp[f(min(a.at(i)-y,(b.at(i)+y)%n),max(a.at(i)-y,(b.at(i)+y)%n))]++;
    } else {
      mp[f(1,n-1)]++;
    }
  }
  ll ans = m*(m-1)/2;
  for(auto [k,v] : mp) {
    ans -= v*(v-1)/2;
  }
  cout << ans << endl;

  return 0;
}
