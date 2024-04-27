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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int h,w,n;cin>>h>>w>>n;
  string t;cin>>t;
  vector<string> s(h);cin>>s;
  reverse(all(t));
  int ans = 0;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='#') continue;
    int x = i;
    int y = j;
    bool flg = true;
    rep(k,n) {
      if(t.at(k)=='U') x++;
      if(t.at(k)=='D') x--;
      if(t.at(k)=='L') y++;
      if(t.at(k)=='R') y--;
      flg &= s.at(x).at(y) != '#';
      if(!flg) break;
    }
    if(flg) ans++;
  }
  cout << ans << endl;

  return 0;
}
