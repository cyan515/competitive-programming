#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  string s;cin>>s;
  rep(i,n-2) {
    if(s.at(i)=='A'&&s.at(i+1)=='B'&&s.at(i+2)=='C') {
      cout << i+1 << endl;
      exit(0);
    }
  }
  cout << -1 << endl;

  exit(0);
}
