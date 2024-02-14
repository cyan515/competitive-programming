#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    ll n,p;cin>>n>>p;
    vector<pair<ll,ll>> ba(n);
    rep(i,n) cin>>ba.at(i).second,ba.at(i).second *= -1;
    rep(i,n) cin>>ba.at(i).first;
    sort(all(ba));
    ll sum = 1;
    ll c = p;
    rep(i,n) {
      if(ba.at(i).first>p) break;
      c += ba.at(i).first*min(ba.at(i).second*-1,n-sum);
      sum += ba.at(i).second*-1;
      if(sum >= n) break;
    }
    if(sum<n) c += (n-sum)*p;
    cout << c << endl;
  }

  exit(0);
}
