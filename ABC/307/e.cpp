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
  ll m;cin>>m;
  vector dp(n,vector<ll>(2,0));
  dp.at(0).at(0) = m;
  dp.at(1).at(1) = dp.at(0).at(0)*(m-1)%MOD;
  for(int i=2;i<n;i++) {
    dp.at(i).at(0) = dp.at(i-1).at(1);
    dp.at(i).at(1) = dp.at(i-1).at(0)*(m-1)%MOD;
    dp.at(i).at(1) +=dp.at(i-1).at(1)*(m-2)%MOD;
    dp.at(i).at(1) %= MOD;
  }
  cout << dp.at(n-1).at(1) << endl;

  exit(0);
}
