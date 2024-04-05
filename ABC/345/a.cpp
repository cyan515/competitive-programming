#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  string s;cin>>s;
  bool flg = true;
  flg &= s.front()=='<';
  flg &= s.back()=='>';
  reps(i,1,s.size()-1) {
    flg &= s.at(i)=='=';
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
