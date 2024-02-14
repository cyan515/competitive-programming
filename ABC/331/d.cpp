#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  ll n,Q;cin>>n>>Q;
  vector<string> p(n);
  rep(i,n) cin>>p.at(i);
  vector s(n+1,vector<ll>(n+1,0));
  rep(i,n) rep(j,n) if(p.at(i).at(j)=='B') s.at(i+1).at(j+1)++;
  rep(i,n) rep(j,n) {
    s.at(i+1).at(j+1) += s.at(i).at(j+1) + s.at(i+1).at(j) - s.at(i).at(j);
  }
  while(Q--) {
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll ans = 0;
    ll x = (a+n)/n;
    ll y = (b+n)/n;
    ll X = (c+n)/n;
    ll Y = (d+n)/n;
    a %= n;
    b %= n;
    c %= n;
    d %= n;
    auto f = [&](ll x1,ll y1,ll x2,ll y2) -> ll {
      return s.at(x2).at(y2) - s.at(x1).at(y2) - s.at(x2).at(y1) + s.at(x1).at(y1);
    };
    if(x!=X && y!=Y) {
      ans += f(a,b,n,n);
      ans += f(0,0,c+1,d+1);
      ans += f(a,0,n,d+1);
      ans += f(0,b,c+1,n);
      
      if(X-x-1>0) {
        ans += f(0,b,n,n) * (X-x-1);
        ans += f(0,0,n,d+1) * (X-x-1);
      }
      if(Y-y-1>0) {
        ans += f(a,0,n,n) * (Y-y-1);
        ans += f(0,0,c+1,n) * (Y-y-1);
      }
            
      if(X-x-1>0&&Y-y-1>0) ans += s.at(n).at(n) * (X-x-1) * (Y-y-1);
    } else if(x==X && y==Y) {
      ans += f(a,b,c+1,d+1);
    } else if(x==X && y!=Y) {
      ans += f(a,b,c+1,n);
      ans += f(a,0,c+1,d+1);
      if(Y-y-1>0) ans += f(a,0,c+1,n) * (Y-y-1);
    } else if(x!=X && y==Y) {
      ans += f(a,b,n,d+1);
      ans += f(0,b,c+1,d+1);
      if(X-x-1>0) ans += f(0,b,n,d+1) * (X-x-1);
    }
    
    cout << ans << endl;
  }

  exit(0);
}
