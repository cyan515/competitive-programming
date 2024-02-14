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

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector g(n,vector<int>());
  dsu D(n);
  rep(i,m) {
    int a,b;cin>>a>>b;a--;b--;
    g.at(b).push_back(a);
    D.merge(a,b);
  }
  bool dup = false;
  int ans = -INF;
  rep(i,n) {
    if(g.at(i).empty()) {
      if(ans!=-INF) dup = true;
      ans = i;
    }
  }
  if(D.size(0)==n && !dup) cout << ans+1 << endl;
  else cout << -1 << endl;

  exit(0);
}
