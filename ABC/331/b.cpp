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
  ll n,s,m,l;cin>>n>>s>>m>>l;
  ll ans = LINF;
  rep(i,n+1) rep(j,n+1) rep(k,n+1) {
    if(6*i+8*j+12*k<n) continue;
    ans = min(ans,i*s+j*m+k*l);
  }
  cout << ans << endl;

  exit(0);
}
