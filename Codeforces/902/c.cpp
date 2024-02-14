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
    ll n;cin>>n;ll m;cin>>m;ll k;cin>>k;
    if(k==1) {
      cout << 1 << endl;
    } else if(k==2) {
      cout << m/n + min(n-1,m) << endl;
    } else if(k==3) {
      if(m<n) cout << 0 << endl;
      else {
        cout << m-m/n-n+1 << endl;
      }
    } else {
      cout << 0 << endl;
    }
  }

  exit(0);
}
