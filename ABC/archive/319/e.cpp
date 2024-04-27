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
  ll n;cin>>n;
  ll x,y;cin>>x>>y;
  vector<pair<ll,ll>> pt(n-1);
  rep(i,n-1) cin>>pt.at(i).first>>pt.at(i).second;
  vector dp(n,vector<ll>(840,LINF));
  rep(i,840) dp.at(n-1).at(i) = 0;
  for(int i=n-2;i>=0;i--) {
    rep(j,840) {
      ll w = pt.at(i).first - j%pt.at(i).first;
      if(w==pt.at(i).first) w = 0;
      ll t = pt.at(i).second;
      dp.at(i).at(j) = min(dp.at(i).at(j),dp.at(i+1).at((j+w+t)%840)+w+t);
    }
  }
  
  int Q;cin>>Q;
  while(Q--) {
    ll q;cin>>q;
    ll m = (x+q)%840;
    cout << q + dp.at(0).at(m)+x+y << endl;
  }

  exit(0);
}
