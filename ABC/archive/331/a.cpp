#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int M,D;cin>>M>>D;
  int y,m,d;cin>>y>>m>>d;
  if(d!=D) cout << y << " " << m << " " << d+1 << endl;
  else if(m!=M) cout << y << " " << m+1 << " 1" << endl;
  else cout << y+1 << " 1 1" << endl;

  exit(0);
}
