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
  rep(_,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  int cnt = n;
  vector<int> ans;
  rep(i,n) {
    if(g.at(i).size()>2) {
      cnt -= g.at(i).size();
      cnt--;
      ans.push_back(g.at(i).size());
    }
  }
  rep(i,cnt/3) {
    ans.push_back(2);
  }
  sort(all(ans));
  rep(i,ans.size()) cout << ans.at(i) << " ";
  cout << endl;

  return 0;
}
