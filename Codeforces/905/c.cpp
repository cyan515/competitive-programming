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
    int n,k;cin>>n>>k;
    vector<int> a(n);
    rep(i,n) cin>>a.at(i);
    if(k==2) {
      int even = 0;
      rep(i,n) if(a.at(i)%2==0) even++;
      if(even) cout << 0 << "\n";
      else cout << 1 << "\n";
    } else if(k==3) {
      int ans = 2;
      rep(i,n) if(a.at(i)%3==0) ans = min(ans,0);
      rep(i,n) if(a.at(i)%3==2) ans = min(ans,1);
      cout << ans << "\n";
    } else if(k==4) {
      int even = 0;
      int fourth = 0;
      int third = 0;
      rep(i,n) {
        if(a.at(i)%2==0) even++;
        if(a.at(i)%4==0) fourth++;
        if(a.at(i)%4==3) third++;
      }
      if(even>=2||fourth>0) cout << 0 << "\n";
      else if(even==1||third>0) cout << 1 << "\n";
      else cout << 2 << "\n";
    } else if(k==5) {
      int ans = 4;
      rep(i,n) if(a.at(i)%5==0) ans = min(ans,0);
      rep(i,n) if(a.at(i)%5==4) ans = min(ans,1);
      rep(i,n) if(a.at(i)%5==3) ans = min(ans,2);
      rep(i,n) if(a.at(i)%5==2) ans = min(ans,3);
      rep(i,n) if(a.at(i)%5==1) ans = min(ans,4);
      cout << ans << "\n";
    }
  }

  exit(0);
}
