#include <bits/stdc++.h>
#include <atcoder/dsu>
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
  ll n,m;cin>>n>>m;
  vector<tuple<ll,ll,vector<ll>>> tup(m);
  rep(i,m) {
    ll k,c;cin>>k>>c;
    vector<ll> a(k);cin>>a;
    rep(i,k) a.at(i)--;
    tup.at(i) = tuple(c,k,a);
  }
  sort(all(tup));
  ll ans = 0;
  ll root = get<2>(tup.front()).front();
  dsu uf(n);
  for(auto [c,k,a] : tup) {
    rep(i,k-1) {
      if(!uf.same(a.at(i),a.at(i+1))){
        uf.merge(a.at(i),a.at(i+1));
        ans += c;
      }
    }
  }
  if(uf.groups().size()==1) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}
