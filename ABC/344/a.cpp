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
  rep(i,s.size()) {
    if(s.at(i)=='|') flg = !flg;
    if(flg && s.at(i)!='|') cout << s.at(i);
  }
  cout << endl;

  return 0;
}
