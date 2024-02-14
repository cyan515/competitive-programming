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
    string s;cin>>s;
    int ans = 4;
    int now = 1;
    rep(i,4) {
      if(s.at(i)=='0'&&now!=0) {
        ans += abs(10-now);
      } else if(now==0&&s.at(i)!='0') {
        ans += abs(10-(s.at(i)-'0'));
      } else {
        ans += abs(now-(s.at(i)-'0'));
      }
      now = s.at(i)-'0';
    }
    cout << ans << endl;
  }

  exit(0);
}
