#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int h,w;cin>>h>>w;
  int x,y;cin>>x>>y;x--;y--;
  vector<string> s(h);cin>>s;
  string t;cin>>t;
  set<pair<int,int>> st;
  int m = t.size();
  auto in = [&](unsigned int xx,unsigned int yy) -> bool {
    return xx<h&&yy<w;
  };
  rep(i,m) {
    int dx,dy;
    if(t.at(i)=='U') {
      dx = dir.at(3).first;
      dy = dir.at(3).second;
    }
    if(t.at(i)=='D') {
      dx = dir.at(2).first;
      dy = dir.at(2).second;
    }
    if(t.at(i)=='L') {
      dx = dir.at(1).first;
      dy = dir.at(1).second;
    }
    if(t.at(i)=='R') {
      dx = dir.at(0).first;
      dy = dir.at(0).second;
    }
    int nx = x+dx;
    int ny = y+dy;
    if(!in(nx,ny)) continue;
    if(s.at(nx).at(ny)=='#') continue;
    x = nx;
    y = ny;
    if(s.at(nx).at(ny)=='@') {
      st.insert(pair(nx,ny));
    }
  }
  x++;y++;
  cout << x << " " << y << " ";
  cout << st.size() << endl;

  return 0;
}
