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
  int h,w,n;cin>>h>>w>>n;
  set<pair<int,int>> a;
  rep(i,n) {
    int x,y;cin>>x>>y;x--;y--;
    a.emplace(x,y);
  }
  vector dp(h,vector<ll>(w,1));
  for(auto [x,y] : a) dp.at(x).at(y) = 0;
  reps(i,1,h) reps(j,1,w) {
    if(a.count(make_pair(i,j))) continue;
    dp.at(i).at(j) = min(dp.at(i-1).at(j-1),min(dp.at(i).at(j-1),dp.at(i-1).at(j))) + 1;
  }
  ll ans = 0;
  rep(i,h) rep(j,w) ans += dp.at(i).at(j);
  cout << ans << endl;

  exit(0);
}
