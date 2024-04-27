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
  int k,G,M;cin>>k>>G>>M;
  int g = 0;
  int m = 0;
  while(k--) {
    if(g==G) {
      g = 0;
    } else if(m==0) {
      m = M;
    } else {
      if(G-g>m) {
        g += m;
        m = 0;
      } else {
        m -= G-g;
        g = G;
      }
    }
  }
  cout << g << " " << m << endl;

  exit(0);
}
