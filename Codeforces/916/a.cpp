#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    bool xp = true;
    bool yp = true;
    bool xn = true;
    bool yn = true;
    rep(i,n) {
      int x,y;cin>>x>>y;
      if(x>0) xn = false;
      if(x<0) xp = false;
      if(y>0) yn = false;
      if(y<0) yp = false;
    }
    if(xp||yp||xn||yn) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  exit(0);
}
