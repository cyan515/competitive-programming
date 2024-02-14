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
  ll n;cin>>n;
  string x;cin>>x;
  bool zero_found = false;
  int one_cnt = 0;
  rep(i,x.size()) {
    if(x.at(x.size()-1-i)=='1') one_cnt++;
    if(x.at(x.size()-1-i)=='0') zero_found = true;
    if(zero_found && x.at(x.size()-1-i)=='1') {
      cout << 0 << endl;
      return 0;
    }
  }
  modint998244353 ans(1);
  rep(i,n-one_cnt) {
    ans *= 2;
  }
  if(ans.val()!=1) cout << ans.val() << endl;
  else cout << 0 << endl;

  exit(0);
}
