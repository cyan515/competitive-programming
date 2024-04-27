#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  string s;cin>>s;
  bool flg = true;
  flg &= s.at(0)>='A' && s.at(0)<='Z';
  reps(i,1,s.size()) {
    flg &= s.at(i)>='a' && s.at(i)<='z';
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
