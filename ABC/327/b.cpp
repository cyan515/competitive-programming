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
  ll b;cin>>b;
  if(b==1) {
    cout << 1 << endl;
    return 0;
  }
  for(ll a = 2;;a++) {
    ll tmp = a;
    rep(i,a-1) {
      tmp *= a;
      if(tmp>b) {
        cout << -1 << endl;
        return 0;
      }
    }
    if(tmp==b) {
      cout << a << endl;
      return 0;
    }
  }
  
  exit(0);
}
