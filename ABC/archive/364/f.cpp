#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
using S = ll;
using F = ll;
S op(S a,S b) {
  return a+b;
}
S e() {
  return 0;
}
S mapping(F f,S s) {
  return min(f,s);
}
F comp(F f,F g) {
  return min(f,g);
}
F id() {
  return LINF;
}

int main() {
  int n,m;cin>>n>>m;
  vector<tuple<ll,int,int>> a(m);
  rep(i,m) {
    ll l,r,c;cin>>l>>r>>c;l--;
    a.at(i) = tuple(c,l,r);
  }
  lazy_segtree<S,op,e,F,mapping,comp,id> st(n);
  sort(all(a));
  ll ans = 0;
  bool ok = true;
  rep(i,m) {
    auto [c,l,r] = a.at(i);
    st.apply(l,r,c);
    ans += c;
  }
  ans += st.all_prod();
  if(ok) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}
