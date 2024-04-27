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
  int n,d,w;cin>>n>>d>>w;
  vector tx(2e5+100,vector<int>());
  rep(i,n) {
    int a,b;cin>>a>>b;
    tx.at(a).push_back(b);
  }
  rep(i,2e5+100) {
    sort(all(tx.at(i)));
  }
  ll ans = 0;
  rep(i,2e5+100) {
    if(tx.at(i).empty()) continue;
    
  }
  cout << ans << endl;

  exit(0);
}
