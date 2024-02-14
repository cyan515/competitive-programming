#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int x,y;
vvi g;

int bfs(int f) {

  vector<bool> seen(x+y);
  queue<pair<int,int>> q;
  q.emplace(f,0);
  seen.at(f) = true;
  int ma = -INF;
  while(q.size()) {
    int v = q.front().first;
    int d = q.front().second;
    ma = max(ma,d);
    q.pop();
    for(auto ele : g.at(v)) {
      if(seen.at(ele)) continue;
      q.emplace(ele,d+1);
      seen.at(ele) = true;
    }
  }
  return ma;
}

int main() {
  int m;
  cin>>x>>y>>m;
  g.resize(x+y);
  rep(i,m) {
    int a,b;cin>>a>>b;a--;b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  int ans = bfs(0);
  ans += bfs(x+y-1);
  ans++;
  cout << ans << endl;

  exit(0);
}
