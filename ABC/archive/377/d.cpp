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
  vector<ll> l(n),r(n);
  rep(i,n) cin>>l.at(i)>>r.at(i);
  rep(i,n) l.at(i)--,r.at(i)--;
  map<int,ll> mp;
  rep(i,n) chmax(mp[r.at(i)],l.at(i));
  ll ans = 0;
  ll ma = 0;
  rep(i,m) {
    auto it = mp.find(i);
    if(it!=mp.end()) chmax(ma,(*it).second+1);
    ans += i+1-ma;
  }
  cout << ans << endl;
  
  return 0;
}
