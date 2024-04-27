#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int main() {
  int n;cin>>n;
  vector<ll> x(n);
  vector<ll> y(n);
  for(int i=0;i<n;i++) cin>>x.at(i)>>y.at(i);
  vector<pair<ll,ll>> dp(n+1);
  for(int i=1;i<=n;i++) {
    if(x.at(i-1)) {
      dp.at(i).first = dp.at(i-1).first;
      dp.at(i).second = max(dp.at(i-1).first+y.at(i-1), dp.at(i-1).second);
    } else {
      dp.at(i).first = max(max(dp.at(i-1).first, dp.at(i-1).first+y.at(i-1)), dp.at(i-1).second+y.at(i-1));
      dp.at(i).second = dp.at(i-1).second;
    }
  }
  cout << max(dp.at(n).first, dp.at(n).second) << endl;

  exit(0);
}
