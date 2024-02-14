#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n;cin>>n;
  vector g(n,vector<int>());
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  if(g.at(0).size()==1) {
    cout << 1 << endl;
    return 0;
  }
  auto f = [&](int& v) -> int {
    queue<int> q;
    q.push(v);
    vector<bool> seen(n,false);
    seen.at(v) = true;
    seen.at(0) = true;
    int ret = 1;
    while(q.size()) {
      int nv = q.front();q.pop();
      for(auto ele : g.at(nv)) {
        if(seen.at(ele)) continue;
        seen.at(ele) = true;
        q.push(ele);
        ret++;
      }
    }
    return ret;
  };
  int ans = INF;
  int ma = 0;
  for(auto ele : g.at(0)) {
    ma = max(ma,f(ele));
  }
  ans = n-ma;
  cout << ans << endl;

  exit(0);
}
