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
  vector<ll> ox,oy,ex,ey;
  rep(i,n) {
    int a,b;cin>>a>>b;
    if((a+b)%2) ox.push_back(a+b),oy.push_back(a-b);
    else ex.push_back(a+b),ey.push_back(a-b);
  }
  sort(all(ox));
  sort(all(oy));
  sort(all(ex));
  sort(all(ey));
  ll ans = 0;
  auto f = [&](vector<ll>& vec) -> ll {
    ll cnt = 0;
    rep(i,vec.size()) {
      cnt += (i-(vec.size()-1-i))*vec.at(i);
    }
    return cnt/2;
  };
  ans += f(ox) + f(oy) + f(ex) + f(ey);
  cout << ans << endl;

  return 0;
}
