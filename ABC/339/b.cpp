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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int h,w,n;cin>>h>>w>>n;
  int x = 0;
  int y = 0;
  int d = 0;
  vector g(h,vector<char>(w,'.'));
  vector<pair<int,int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
  
  rep(i,n) {
    if(g.at(x).at(y)=='.') {
      g.at(x).at(y) = '#';
      d++;
    } else {
      g.at(x).at(y) = '.';
      d--;
    }
    d+=4;
    d%=4;
    auto [dx,dy] = dir.at(d);
    x += dx;
    y += dy;
    x += h;
    x %= h;
    y += w;
    y %= w;
  }
  
  rep(i,h) {
    rep(j,w) {
      cout << g.at(i).at(j);
    }
    cout << endl;
  }

  exit(0);
}
