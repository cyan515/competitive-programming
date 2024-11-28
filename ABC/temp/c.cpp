#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// #include <ext/pb_ds/assoc_container.hpp>
// template<typename T>
// using ordered_set = __gnu_pbds::tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//https://atcoder.jp/contests/tupc2023/tasks/tupc2023_a
int main() {
  int n;cin>>n;
  vector<ll> x(200010,0),y(20010,0);
  vector<tuple<int,int,ll>> xy(n);
  rep(i,n) {
    int a,b;cin>>a>>b;a--;b--;
    ll p;cin>>p;
    x.at(a) += p;
    y.at(b) += p;
    xy.at(i) = tuple(a,b,p);
  }
  ll ans = 0;
  for(auto [a,b,p] : xy) {
    chmax(ans,x.at(a)+y.at(b)-p);
  }
  cout << ans << endl;

  return 0;
}
