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
  ll n;cin>>n;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  vector<ll> r(n,0);
  vector<ll> c(n,0);
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)=='o') r.at(i)++,c.at(j)++;
  }
  ll ans = 0;
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)!='o') continue;
    ans += (r.at(i)-1)*(c.at(j)-1);
  }
  cout << ans << endl;

  exit(0);
}
