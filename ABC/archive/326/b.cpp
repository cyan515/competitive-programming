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
  int n;cin>>n;
  reps(i,n,920) {
    int a = i/100;
    int b = i/10%10;
    int c = i%10;
    if(a*b==c) {
      cout << i << endl;
      return 0;
    }
  }

  exit(0);
}
