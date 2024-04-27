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
  int n,m;cin>>n>>m;
  vector<int> a(m);
  vector<int> b(m);
  rep(i,m) cin>>a.at(i),a.at(i)--;
  rep(i,m) cin>>b.at(i),b.at(i)--;
  dsu uf(n);
  rep(i,m) uf.merge(a.at(i),b.at(i));
  vector g(n,vector<int>());
  rep(i,m) {
    g.at(a.at(i)).push_back(b.at(i));
    g.at(b.at(i)).push_back(a.at(i));
  }
  
  vector<int> color(n, -1);
  string ans = "Yes";
  for(int v = 0; v < n; ++v) {
    if(color[v] != -1) {continue;}
    queue<int> que;
    color[v] = 0;
    que.push(v);
    while(que.size() > 0) {
      int qv = que.front();
      que.pop();
      for(auto nv : g.at(qv)) {
        if(color[nv] != -1) {
          if(color[nv] == color[qv]) {ans = "No";}
          continue;
        }
        color[nv] = 1 - color[qv];
        que.push(nv);
      }
    }
  }
  cout << ans << endl;
  
  exit(0);
}
