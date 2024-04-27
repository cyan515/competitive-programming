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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  ll ans = 1;
  auto f = [](string s) -> bool {
    int si = s.size();
    rep(i,si) {
      if(s.at(i)!=s.at(si-1-i)) return false;
    }
    return true;
  };
  for(ll i=1;i*i*i<=n;i++) {
    if(f(to_string(i*i*i))) ans = i*i*i;
  }
  cout << ans << endl;

  return 0;
}
