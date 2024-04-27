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
  int n;cin>>n;
  vector<int> w(n);
  vector<int> x(n);
  rep(i,n) cin>>w.at(i)>>x.at(i);
  int ans = 0;
  rep(i,24) {
    int cnt = 0;
    rep(j,n) {
      if(9<=(x.at(j)+i)%24&&(x.at(j)+i)%24<=17) cnt += w.at(j);
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;

  exit(0);
}
