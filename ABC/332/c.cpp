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
  int n,M;cin>>n>>M;
  string s;cin>>s;
  int cnt = 0;
  int ans = 0;
  int m = M;
  rep(i,n) {
    if(s.at(i)=='0') {
      m = M;
      ans = max(ans,cnt);
      cnt = 0;
    } else if(s.at(i)=='1') {
      if(m) m--;
      else cnt++;
    } else {
      cnt++;
    }
  }
  cout << max(ans,cnt) << endl;

  exit(0);
}
