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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(n);cin>>a;
  vector cnt(11,map<ll,ll>());
  {
    ll base = 1;
    rep(idx,11) {
      rep(i,n) {
        cnt.at(idx)[a.at(i)%m*base%m]++;
      }
      base *= 10;
      base %= m;
    }
  }
  ll ans = 0;
  rep(i,n) {
    ll len = to_string(a.at(i)).size();
    ll x = a.at(i) % m;
    if(x) ans += cnt.at(len)[m-x];
    else ans += cnt.at(len)[0];
  }
  cout << ans << endl;

  return 0;
}
