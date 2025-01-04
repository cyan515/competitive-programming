#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
// using mint = modint998244353;
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
ll op(ll a,ll b) {
  return max(a,b);
}
ll e() {
  return -LINF;
}
// https://atcoder.jp/contests/typical90/tasks/typical90_ak
int main() {
  int w;cin>>w;
  int n;cin>>n;
  vector<int> l(n),r(n),v(n);
  rep(i,n) cin>>l.at(i)>>r.at(i)>>v.at(i);
  lazy_segtree<ll,op,e,ll,op,op,e> dp(w+1);
  dp.set(0,0);
  rep(i,n) {
    auto ep = dp;
    rep(j,w+1) {
      ep.apply(min((ll)w+1,j+l.at(i)),min((ll)w+1,j+r.at(i)+1),dp.get(j)+v.at(i));
    }
    swap(dp,ep);
  }
  ll ans = dp.get(w);
  if(ans<0) ans = -1;
  cout << ans << endl;
  
  return 0;
}
