#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    vector g(n,vector<int>());
    rep(i,n-1) {
      int u,v;cin>>u>>v;u--;v--;
      g.at(u).push_back(v);
      g.at(v).push_back(u);
    }
    int leaf = 0;
    rep(i,n) if(g.at(i).size()==1) leaf++;
    cout << (leaf+1)/2 << endl;
  }

  exit(0);
}
