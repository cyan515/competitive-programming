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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  int sum = 0;
  rep(i,n) sum += b.at(i);
  if(sum%3!=0) {
    cout << -1 << endl;
    return 0;
  }
  int m = 1510;
  vector dp(m,vector<int>(m,INF));
  dp.at(0).at(0) = 0;
  rep(i,n) {
    vector ndp(m,vector<int>(m,INF));
    rep(j,m) rep(k,m) {
      if(j+b.at(i)<m) {
        if(a.at(i)==1) chmin(ndp.at(j+b.at(i)).at(k),dp.at(j).at(k));
        else chmin(ndp.at(j+b.at(i)).at(k),dp.at(j).at(k)+1);
      }
      if(k+b.at(i)<m) {
        if(a.at(i)==2) chmin(ndp.at(j).at(k+b.at(i)),dp.at(j).at(k));
        else chmin(ndp.at(j).at(k+b.at(i)),dp.at(j).at(k)+1);
      }
      if(a.at(i)==3) chmin(ndp.at(j).at(k),dp.at(j).at(k));
      else chmin(ndp.at(j).at(k),dp.at(j).at(k)+1);
    }
    swap(dp,ndp);
  }
  int ans = dp.at(sum/3).at(sum/3);
  if(ans==INF) ans = -1;
  cout << ans << endl;

  return 0;
}
