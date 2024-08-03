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
  int n;cin>>n;
  string s;cin>>s;
  vector dp(n+1,vector(3,-INF));
  rep(i,3) dp.at(0).at(i) = 0;
  rep(i,n) {
    if(s.at(i)!='P') chmax(dp.at(i+1).at(0),dp.at(i).at(1)+(s.at(i)=='S'?1:0));
    if(s.at(i)!='P') chmax(dp.at(i+1).at(0),dp.at(i).at(2)+(s.at(i)=='S'?1:0));
    if(s.at(i)!='S') chmax(dp.at(i+1).at(1),dp.at(i).at(0)+(s.at(i)=='R'?1:0));
    if(s.at(i)!='S') chmax(dp.at(i+1).at(1),dp.at(i).at(2)+(s.at(i)=='R'?1:0));
    if(s.at(i)!='R') chmax(dp.at(i+1).at(2),dp.at(i).at(0)+(s.at(i)=='P'?1:0));
    if(s.at(i)!='R') chmax(dp.at(i+1).at(2),dp.at(i).at(1)+(s.at(i)=='P'?1:0));
  }
  int ans = 0;
  rep(i,3) chmax(ans,dp.at(n).at(i));
  cout << ans << endl;

  return 0;
}
