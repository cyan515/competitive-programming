#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  vector flg(n,vector<bool>(m,false));
  flg.at(1).at(1) = true;
  queue<pair<int,int>> q;
  set<pair<int,int>> seen;
  set<pair<int,int>> ud;
  set<pair<int,int>> lr;
  q.push(make_pair(1,1));
  while(q.size()) {
    pair<int,int> p = q.front();
    seen.insert(p);
    ud.insert(p);
    lr.insert(p);
    q.pop();
    int x = p.first;
    int y = p.second;
    int dx = 0;
    int dy = 0;
    while(s.at(x+dx).at(y)=='.') {
      flg.at(x+dx).at(y) = true;
      dx++;
      if(ud.count(make_pair(x+dx,y))) break;
      ud.insert(make_pair(x+dx,y));
    }
    if(!seen.count(make_pair(x+dx-1,y))) q.push(make_pair(x+dx-1,y));
    dx = 0;
    while(s.at(x+dx).at(y)=='.') {
      flg.at(x+dx).at(y) = true;
      dx--;
      if(ud.count(make_pair(x+dx,y))) break;
      ud.insert(make_pair(x+dx,y));
    }
    if(!seen.count(make_pair(x+dx+1,y))) q.push(make_pair(x+dx+1,y));
    
    while(s.at(x).at(y+dy)=='.') {
      flg.at(x).at(y+dy) = true;
      dy++;
      if(lr.count(make_pair(x,y+dy))) break;
      lr.insert(make_pair(x,y+dy));
    }
    if(!seen.count(make_pair(x,y+dy-1))) q.push(make_pair(x,y+dy-1));
    dy = 0;
    while(s.at(x).at(y+dy)=='.') {
      flg.at(x).at(y+dy) = true;
      dy--;
      if(lr.count(make_pair(x,y+dy))) break;
      lr.insert(make_pair(x,y+dy));
    }
    if(!seen.count(make_pair(x,y+dy+1))) q.push(make_pair(x,y+dy+1));
    
  }

  int ans = 0;
  rep(i,n) rep(j,m) if(flg.at(i).at(j)) ans++;
  cout << ans << endl;

  exit(0);
}
