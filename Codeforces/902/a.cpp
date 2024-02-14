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
    vector<int> a(n-1);
    rep(i,n-1) cin>>a.at(i);
    int sum = 0;
    rep(i,n-1) sum+=a.at(i);
    cout << -sum << endl;
  }

  exit(0);
}
