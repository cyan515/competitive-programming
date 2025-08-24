#include <bits/stdc++.h>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  vector dists(h,vector(w,vector<int>(2,INF)));
  int si,sj,gi,gj;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='S') si = i, sj = j;
    if(s.at(i).at(j)=='G') gi = i, gj = j;
  }
  auto in = [&](unsigned ii,unsigned jj) -> bool {
    return ii<h&&jj<w;
  };
  dists.at(si).at(sj).at(0) = 0;
  queue<tuple<int,int,int>> q;
  q.push(tuple(si,sj,0));
  while(q.size()) {
    auto [vi,vj,sw] = q.front();q.pop();
    rep(ddi,4) {
      auto [di,dj] = dir.at(ddi);
      int ni = vi+di;
      int nj = vj+dj;
      if(!in(ni,nj)) continue;
      if(s.at(ni).at(nj)=='#') continue;
      if(sw==0&&s.at(ni).at(nj)=='x') continue;
      if(sw==1&&s.at(ni).at(nj)=='o') continue;
      int nsw = (s.at(ni).at(nj)=='?'?sw^1:sw);
      if(dists.at(ni).at(nj).at(nsw)!=INF) continue;
      dists.at(ni).at(nj).at(nsw) = dists.at(vi).at(vj).at(sw) + 1;
      q.push(tuple(ni,nj,nsw));
    }
  }
  int ans = INF;
  rep(i,2) chmin(ans,dists.at(gi).at(gj).at(i));
  if(ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
}
