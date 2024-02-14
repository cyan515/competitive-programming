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
  string s;cin>>s;
  int n = s.length();
  bool flg =true;
  rep(i,n-1) {
    flg &= s.at(i) >s.at(i+1);
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
