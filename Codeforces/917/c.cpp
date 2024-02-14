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
    vector<int> a(n);
    rep(i,n) cin>>a.at(i);
    int ans = 0;
    int x = INF;
    int y = INF;
    rep(i,n) {
      if(x>y) swap(x,y);
      if(x>=a.at(i)) {
        x = a.at(i);
      } else if(y>=a.at(i)) {
        y = a.at(i);
      } else {
        if(x<y) x = a.at(i);
        else y = a.at(i);
        ans++;
      }
    }
    cout << ans << endl;
  }

  exit(0);
}
