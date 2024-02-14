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
  int x,y,z;cin>>x>>y>>z;
  string s;cin>>s;
  int len = s.length();
  vector<pair<ll,ll>> dp(len+1,make_pair(0,0));
  dp.at(0).second=z;
  for(int i=1;i<1+len;i++) {
    if(s.at(i-1)=='a') {
      dp.at(i).first = min(min(min(
        dp.at(i-1).first+x,
        dp.at(i-1).second+y+z),
        dp.at(i-1).second+z+x),
        dp.at(i-1).first+z+x+z);
      dp.at(i).second = min(min(min(
        dp.at(i-1).first+y+z,
        dp.at(i-1).first+z+x),
        dp.at(i-1).second+y),
        dp.at(i-1).second+z+x+z);
    } else {
      dp.at(i).first = min(min(min(
        dp.at(i-1).first+y,
        dp.at(i-1).second+x+z),
        dp.at(i-1).second+z+y),
        dp.at(i-1).first+z+y+z);
      dp.at(i).second = min(min(min(
        dp.at(i-1).first+x+z,
        dp.at(i-1).first+z+y),
        dp.at(i-1).second+x),
        dp.at(i-1).second+z+y+z);
    }
  }

  ll ans = min(dp.at(len).first,dp.at(len).second);
  cout << ans << endl;

  exit(0);
}
