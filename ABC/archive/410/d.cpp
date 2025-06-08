#include <bits/stdc++.h>
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

int main() {
  ll n,m;cin>>n>>m;
  vector g(n,vector<pair<ll,int>>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    ll w;cin>>w;
    g.at(u).push_back(pair(w,v));
  }
  vector dp(n,vector<bool>(1200,false));
  dp.at(0).at(0) = true;
  // node, weight
  queue<pair<int,int>> q;q.push(pair(0,0));
  while(q.size()) {
    auto [v,w] = q.front();q.pop();
    for(auto [nw,nv] : g.at(v)) {
      if(dp.at(nv).at(nw^w)) continue;
      dp.at(nv).at(nw^w) = true;
      q.push(pair(nv,nw^w));
    }
  }
  int ans = INF;
  rep(i,1200) {
    if(dp.at(n-1).at(i)) {
      ans = min(ans,(int)i);
    }
  }
  if(ans==INF) ans = -1;
  cout << ans << endl;

  return 0;
}
