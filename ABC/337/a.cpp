#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n;cin>>n;
  int x = 0;
  int y = 0;
  rep(i,n) {
    int a,b;cin>>a>>b;
    x+=a;y+=b;
  }
  if(x>y) cout << "Takahashi" << endl;
  else if(x==y) cout << "Draw" << endl;
  else cout << "Aoki" << endl;

  exit(0);
}
