#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int x,y;cin>>x>>y;
  string ans;
  if(x<y&&x-y<-2) ans="No";
  else if(x>y&&x-y>3) ans="No";
  else ans="Yes";
  cout << ans << endl;

  exit(0);
}
