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
  int x;cin>>x;
  vector<double> s(n),c(n),p(n);
  rep(i,n) cin>>s.at(i)>>c.at(i)>>p.at(i);
  rep(i,n) p.at(i) /= 100.0;
  vector dp(x+1,vector<double>(1<<n,0));
  for(int i=x;i>=0;i--) {
    rep(bit,1<<n) rep(j,n) {
      if(i+c.at(j)>x) continue;
      if((bit&(1<<j))!=0) continue;
      chmax(dp.at(i).at(bit),p.at(j)*(dp.at(i+c.at(j)).at(bit|(1<<j))+s.at(j))+(1-p.at(j))*dp.at(i+c.at(j)).at(bit));
    }
  }
  cout << fixed << setprecision(20) << dp.at(0).at(0) << endl;

  return 0;
}
