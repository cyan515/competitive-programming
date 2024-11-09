#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  vector<ll> a(n);cin>>a;
  vector<ll> x(n+1,0);
  fenwick_tree<ll> pref(n);
  rep(i,n) {
    x.at(i+1) += x.at(i)+a.at(i);
    pref.add(i,a.at(i));
    if(i!=0) pref.add(i,pref.sum(i-1,i));
  }
  rep(i,n+1) x.at(i) %= m;
  ll ans = 0;
  rep(l,n) {
    reps(i,l+1,n+1) {
      x.at(i) -= x.at(l);
      if(x.at(i)<0) x.at(i) += m;
    }
    reps(i,l+1,n+1) ans += x.at(i);
  }
  cout << ans << endl;

  return 0;
}
