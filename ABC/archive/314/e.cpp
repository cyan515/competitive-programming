#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector<int> c(n);
  vector<int> p(n);
  vector s(n,vector<int>());
  rep(i,n) {
    cin>>c.at(i)>>p.at(i);
    rep(j,p.at(i)) {
      int tmp;cin>>tmp;
      s.at(i).push_back(tmp);
    }
  }
  vector<int> sum(n,0);
  rep(i,n) rep(j,p.at(i)) sum.at(i) += s.at(i).at(j);
  vector<long double> e(n);
  rep(i,n) e.at(i) = (long double)sum.at(i) / (long double)p.at(i) / (long double)c.at(i);
  vector dp(n,vector<long double>(1e4+100));
  rep(i,n) dp.at(i).at(0) = e.at(i);
  long double ans = 0;
  rep(i,n) rep(j,1e4+10) {
    dp.at(i).at(j+1) = dp.at(i).at(j);
  }
  cout << fixed << setprecision(10);
  

  exit(0);
}
