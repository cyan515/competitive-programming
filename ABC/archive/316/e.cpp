#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int h,w;cin>>h>>w;
  pair<int,int> frm;
  pair<int,int> to;
  vector<string> a(h);
  rep(i,h) cin>>a.at(i);
  vector tate(h,vector(w,false));
  vector yoko(h,vector(w,false));
  vector<char> human = {'>', 'v', '<', '^' };
  rep(i,h) rep(j,w) {
    int dir = -1;
    rep(k,4) if(a.at(i).at(j)==human.at(k)) dir = k;
    int dx=0,dy=0;
    if(dir==-1) continue;
    else if(dir==0) dx = 1;
    else if(dir==1) dy = 1;
    else if(dir==2) dx = -1;
    else if(dir==3) dy = -1;
    int x = j;
    int y = i;
    while(1) {
      x += dx;
      y += dy;
      if(x>=w || x<0 || y>=h || y<0) break;
      if(dir%2==0 && yoko.at(y).at(x)) break;
      if(dir%2==1 && tate.at(y).at(x)) break;
      if(a.at(y).at(x) == '#') break;
      bool flg = false;
      rep(k,4) {
        if(a.at(y).at(x)==human.at(k)) flg = true;
      }
      if(flg) break;
      a.at(y).at(x) = 'x';
    }
  }
  rep(i,h) rep(j,w) {
    rep(k,4) if(a.at(i).at(j)==human.at(k)) a.at(i).at(j) = '#';
    if(a.at(i).at(j)=='x') a.at(i).at(j) = '#';
    if(a.at(i).at(j)=='S') frm.first=i,frm.second=j;
    if(a.at(i).at(j)=='G') to.first=i,to.second=j;
  }
  queue<pair<int,int>> q;
  vector dist(h,vector<int>(w,-1));
  dist.at(frm.first).at(frm.second) = 0;
  q.push(frm);
  auto can_move = [&](int xx,int yy) -> bool {
    if(xx>=w || xx<0 || yy>=h || yy<0 || a.at(yy).at(xx)=='#') return false;
    return true;
  };
  while(q.size()) {
    auto [y,x] = q.front();q.pop();
    int nx = x;
    int ny = y;
    x--;
    if(can_move(x,y) && dist.at(y).at(x)==-1) dist.at(y).at(x) = dist.at(ny).at(nx) + 1, q.push(make_pair(y,x));
    x++;x++;
    if(can_move(x,y) && dist.at(y).at(x)==-1) dist.at(y).at(x) = dist.at(ny).at(nx) + 1, q.push(make_pair(y,x));
    x--;y--;
    if(can_move(x,y) && dist.at(y).at(x)==-1) dist.at(y).at(x) = dist.at(ny).at(nx) + 1, q.push(make_pair(y,x));
    y++;y++;
    if(can_move(x,y) && dist.at(y).at(x)==-1) dist.at(y).at(x) = dist.at(ny).at(nx) + 1, q.push(make_pair(y,x));
  }
  cout << dist.at(to.first).at(to.second) << endl;

  exit(0);
}
