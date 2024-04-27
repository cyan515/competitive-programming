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
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  vector g(n,vector<ll>(n,LINF));
  rep(i,n) rep(j,n-1-i) {
    ll tmp;cin>>tmp;
    g.at(i).at(i+j+1) = tmp;
    g.at(i+j+1).at(i) = tmp;
  }
  vector<ll> dp(1<<n,0);
  for(ll msk=0;msk<(1<<n);msk++) {
    int bit_cnt = 0;
    rep(i,n) if((msk&(1<<i))) bit_cnt++;
    if(bit_cnt%2==1) continue;
    rep(i,n) reps(j,i+1,n) {
      if((msk&(1<<i))) continue;
      if((msk&(1<<j))) continue;
      ll nx = msk | (1<<i) | (1<<j);
      dp.at(nx) = max(dp.at(nx),dp.at(msk)+g.at(i).at(j));
    }
  }
  ll ans = -1;
  rep(i,1<<n) ans = max(ans,dp.at(i));
  cout << ans << endl;

  exit(0);
}
