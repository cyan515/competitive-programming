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
    int a,b;cin>>a>>b;
    if((a+b)%2) cout << "Alice" << endl;
    else cout << "Bob" << endl;
  }

  exit(0);
}
