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

int main() {
  ll n,m;cin>>n>>m;
  vector<ll>a(n);cin>>a;
  ll ans = 0;
  vector<ll> pref(n+1,0);
  rep(i,n) pref.at(i+1) = pref.at(i) + a.at(i);
  map<ll,ll> x;
  rep(i,n) {
    ans += x[pref.at(i)%m];
    ans += x[(m-(pref.at(n)-pref.at(i))%m)%m];
    x[pref.at(i)%m]++;
  }
  cout << ans << endl;

  return 0;
}
