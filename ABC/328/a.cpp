#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n,x;cin>>n>>x;
  int ans = 0;
  rep(i,n) {
    int a;cin>>a;
    if(a<=x) ans+=a;
  }
  cout << ans << endl;

  exit(0);
}
