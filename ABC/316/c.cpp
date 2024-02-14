#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  int m;cin>>m;
  // node, dist
  vector g(n,vector<pair<int,int>>());
  rep(i,m) {
    int a,b,c;cin>>a>>b>>c;a--;b--;
    g.at(a).push_back(make_pair(b,c));
    g.at(b).push_back(make_pair(a,c));
  }
  int ans = 0;
  vector<int> dist;
  vector<int> path;
  auto dfs = [&](auto f,int v) -> void {
    ans = max(ans,dist.at(v));
    for(auto [ele,d] : g.at(v)) {
      if(dist.at(ele)!=-1) continue;
      dist.at(ele) = dist.at(v) + d;
      path.push_back(ele);
      f(f,ele);
      dist.at(ele) = -1;
      path.pop_back();
    }
  };
  rep(i,n) {
    dist = vector<int>(n,-1);
    dist.at(i) = 0;
    path = vector<int>();
    path.push_back(i);
    dfs(dfs,i);
  }
  cout << ans << endl;

  exit(0);
}
