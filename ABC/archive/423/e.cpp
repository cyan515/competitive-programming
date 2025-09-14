#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  fenwick_tree<ll> x(n),y(n),z(n);
  rep(i,n) {
    x.add(i,a.at(i));
    y.add(i,a.at(i)*(i+1));
    z.add(i,a.at(i)*(i+1)*(i+1));
  }
  while(Q--) {
    ll l,r;cin>>l>>r;
    ll ans = 0;
    ans += (-r*l-l+r+1) * x.sum(l-1,r);
    ans += (r+l) * y.sum(l-1,r);
    ans += - z.sum(l-1,r);
    cout << ans << endl;
  }

  return 0;
}
