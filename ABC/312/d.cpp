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
  string s;cin>>s;
  int n = s.length();
  vector dp(n,vector<ll>(n,0));
  if((s.at(0)=='('||s.at(0)=='?')&&n>1) dp.at(0).at(1)++;
  if(s.at(0)==')') {
    cout << 0 << endl;
    exit(0);
  }
  reps(i,1,n) {
    if(s.at(i)=='(' || s.at(i)=='?') rep(j,n-1) dp.at(i).at(j+1) += dp.at(i-1).at(j),dp.at(i).at(j+1)%=MOD;
    if(s.at(i)==')' || s.at(i)=='?') reps(j,1,n) dp.at(i).at(j-1) += dp.at(i-1).at(j),dp.at(i).at(j-1)%=MOD;
  }
  cout << dp.at(n-1).at(0)%MOD << endl;

  exit(0);
}
