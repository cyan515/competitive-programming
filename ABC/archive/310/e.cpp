#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  ll n;cin>>n;
  string s;cin>>s;
  vector dp(n,vector<int>(2));
  if(s.at(0)=='0') dp.at(0).at(0) = 1;
  else dp.at(0).at(1) = 1;
  reps(i,1,n) {
    if(s.at(i)=='0') {
      dp.at(i).at(0) = 1;
      dp.at(i).at(1) = dp.at(i-1).at(1) + dp.at(i-1).at(0);
    } else {
      dp.at(i).at(0) = dp.at(i-1).at(1);
      dp.at(i).at(1) = dp.at(i-1).at(0) + 1;
    }
  }
  ll ans = 0;
  rep(i,n) ans += dp.at(i).at(1);
  cout << ans << endl;

  exit(0);
}
