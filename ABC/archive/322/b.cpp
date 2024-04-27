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
  cin.tie(0) -> sync_with_stdio(0);
  int n,m;cin>>n>>m;
  string s,t;cin>>s>>t;
  string pre = t.substr(0,n);
  string sub = t.substr(m-n,n);
  int ans;
  if(pre==s && sub==s) ans = 0;
  else if(pre==s) ans = 1;
  else if(sub==s) ans = 2;
  else ans = 3;
  cout << ans << endl;

  exit(0);
}
