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
  ll n;cin>>n;
  vector<ll>w(n),h(n),b(n);
  rep(i,n)cin>>w.at(i)>>h.at(i)>>b.at(i);
  int m = 500010;
  vector<ll> dp(m,-LINF);
  ll base = 250000;
  dp.at(base) = 0;
  rep(i,n) {
    vector<ll> ndp(m,-LINF);
    rep(j,m) {
      if(0<=j+w.at(i)&&j+w.at(i)<m) chmax(ndp.at(j+w.at(i)),dp.at(j)+b.at(i));
      if(0<=j-w.at(i)&&j-w.at(i)<m) chmax(ndp.at(j-w.at(i)),dp.at(j)+h.at(i));
    }
    swap(dp,ndp);
  }
  ll ans = -LINF;
  reps(i,base,m) chmax(ans,dp.at(i));
  cout<<ans<<endl;

  return 0;
}
