#include <bits/stdc++.h>
#include <atcoder/scc>
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
// https://atcoder.jp/contests/typical90/tasks/typical90_u
int main() {
  int n,m;cin>>n>>m;
  scc_graph scc(n);
  rep(i,m) {
    int a,b;cin>>a>>b;a--;b--;
    scc.add_edge(a,b);
  }
  auto x = scc.scc();
  ll ans = 0;
  for(auto vec : x) {
    ans += vec.size()*(vec.size()-1)/2;
  }
  cout << ans << endl;
  
  return 0;
}
