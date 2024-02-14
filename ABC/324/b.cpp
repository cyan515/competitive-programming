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
  cin.tie(0) -> sync_with_stdio(0);
  ll n;cin>>n;
  ll x = 1;
  ll y = 1;
  bool ans = false;
  while(x<=n) {
    while(x*y<=n) {
      ans |= x*y==n;
      y *= 3;
    }
    y = 1;
    x *= 2;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
