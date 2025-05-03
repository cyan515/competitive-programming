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
  int n,t,m,k;cin>>n>>t>>m>>k;
  vector dp(t+1,vector<long double>(k+1,0));
  dp.at(0).at(0) = 1.0;
  rep(i,t) rep(j,k+1) {
    if(j==k) {
      dp.at(i+1).at(j) += dp.at(i).at(j);
      continue;
    }
    int rem = k-j;
    int cnt = m/rem;
    int frac = m%rem;
    if(cnt<n) {
      dp.at(i+1).at(j+rem) += dp.at(i).at(j)*((long double)cnt/n);
      // dp.at(i+1).at(j) += dp.at(i).at(j)*(1.0-(((long double)cnt+1.0)/n));
      if(frac>n-cnt) {
        int cntt = frac/(n-cnt);
        int fracc = frac%(n-cnt);
        dp.at(i+1).at(j+cntt+1) += dp.at(i).at(j)*((long double)fracc/n);
        dp.at(i+1).at(j+cntt) += dp.at(i).at(j)*((long double)n-cnt-fracc)/(long double)n;
      } else {
        dp.at(i+1).at(j+1) += dp.at(i).at(j)*((long double)frac)/(long double)n;
        dp.at(i+1).at(j) += dp.at(i).at(j)*(1.0-(((long double)frac+cnt)/(long double)n));
        // dp.at(i+1).at(j+frac) += dp.at(i).at(j)*(1.0/n);
      }
    } else {
      dp.at(i+1).at(k) += dp.at(i).at(j);
    }
  }
  cout << fixed << setprecision(20) << dp.at(t).at(k) << endl;
    
  return 0;
}
