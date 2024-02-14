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
  int n;cin>>n;
  set<ll> st;
  rep(i,13) rep(j,13) rep(k,13) {
    ll x = 1;
    ll y = 1;
    ll z = 1;
    rep(a,i) x *= 10,x++;
    rep(b,j) y *= 10,y++;
    rep(c,k) z *= 10,z++;
    st.insert(x+y+z);
  }
  ll ans;
  auto it = st.begin();
  rep(i,n-1) it++;
  ans = *it;
  cout << ans << endl;

  exit(0);
}
