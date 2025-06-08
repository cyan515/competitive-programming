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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n;cin>>n;
  ll h,m;cin>>h>>m;
  vector<int> a(n),b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  vector dp(n+1,vector<int>(h+1,-INF));
  dp.at(0).at(h) = m;
  rep(i,n) rep(j,h+1) {
    if(j-a.at(i)>=0) chmax(dp.at(i+1).at(j-a.at(i)),dp.at(i).at(j));
    if(dp.at(i).at(j)-b.at(i)>=0) chmax(dp.at(i+1).at(j),dp.at(i).at(j)-b.at(i));
  }
  int ans = 0;
  rep(i,n+1) rep(j,h+1) {
    if(dp.at(i).at(j)>=0) {
      chmax(ans,(int)i);
    }
  }
  cout << ans << endl;

  return 0;
}
