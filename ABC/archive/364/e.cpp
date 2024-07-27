#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n,x,y;cin>>n>>x>>y;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  int ans = 0;
  vector dp(n+1,vector(x+1,vector<int>(2,INF)));
  dp.at(0).at(0).at(0) = 0;
  rep(i,n) {
    auto ndp = dp;
    rep(j,n+1) rep(k,x+1) {
      chmin(ndp.at(j).at(k).at(1),dp.at(j).at(k).at(0));
      chmin(ndp.at(j).at(k).at(1),dp.at(j).at(k).at(1));
      if(j==n||k+a.at(i)>x) continue;
      chmin(ndp.at(j+1).at(k+a.at(i)).at(0),dp.at(j).at(k).at(0)+b.at(i));
      chmin(ndp.at(j+1).at(k+a.at(i)).at(1),dp.at(j).at(k).at(1)+b.at(i));
    }
    swap(ndp,dp);
  }
  rep(i,n+1) rep(j,x+1) {
    if(dp.at(i).at(j).at(0)<=y) chmax(ans,(int)i);
    if(dp.at(i).at(j).at(1)<=y) chmax(ans,(int)i+1);
  }
  cout << ans << endl;

  return 0;
}
