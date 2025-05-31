#include <bits/stdc++.h>
#include <atcoder/dsu>
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
  int n,m;cin>>n>>m;
  vector g(n,vector<pair<int,int>>());
  rep(i,m) {
    int u,v,w;cin>>u>>v>>w;u--;v--;
    g.at(u).push_back(pair(v,w));
    g.at(v).push_back(pair(u,w));
  }
  int ans = (1LL<<31)-1;
  for(int dig=30;dig>=0;dig--) {
    int bit = ans & ~(1<<dig);
    dsu uf(n);
    rep(i,n) for(auto [j,w] : g.at(i)) {
      if((bit|w)==bit) uf.merge(i,j);
    }
    if(uf.same(0,n-1)) {
      ans = bit;
    }
  }
  cout << ans << endl;

  return 0;
}
