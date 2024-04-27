#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  vector<pair<ll,ll>> o,e;
  rep(i,n) {
    int a,b;cin>>a>>b;
    if((a+b)%2) o.push_back(pair(a,b));
    else e.push_back(pair(a,b));
  }
  sort(all(o));
  sort(all(e));
  ll ans = 0;
  
  rep(i,o.size()) {

  }
  cout << ans << endl;

  return 0;
}
