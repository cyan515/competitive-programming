#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  vector<pair<ll,ll>> p(3);
  rep(i,3) {
    ll x,y;cin>>x>>y;p.at(i) = pair(x,y);
  }
  sort(all(p));
  bool ans = false;
  auto f = [](pair<ll,ll> a, pair<ll,ll> b) -> ll {
    ll dx = abs(a.first-b.first);
    ll dy = abs(a.second-b.second);
    return dx*dx+dy*dy;
  };
  do {
    ll aa = f(p.at(0),p.at(1));
    ll bb = f(p.at(1),p.at(2));
    ll cc = f(p.at(2),p.at(0));
    if(cc==aa+bb) ans = true;
  } while(next_permutation(all(p)));
  if(ans) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
