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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector g(n,vector<int>());
  vector<int> d(n,0);
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
    d.at(u)++;
    d.at(v)++;
  }
  int ans = INF;
  rep(i,n) {
    vector<int> vec;
    int ma = -INF;
    for(auto v : g.at(i)) {
      vec.push_back(d.at(v)-1);
    }
    sort(all(vec));
    reverse(all(vec));
    rep(ii,vec.size()) {
      if(vec.at(ii)==0) break;
      chmax(ma,int(1+ii+1+(ii+1)*vec.at(ii)));
    }
    chmin(ans,n-ma);
  }
  cout << ans << endl;

  return 0;
}
