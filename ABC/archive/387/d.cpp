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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  int si,sj,gi,gj;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='S') si = i, sj = j;
    if(s.at(i).at(j)=='G') gi = i, gj = j;
  }
  queue<tuple<int,int,int>> q;
  q.push(tuple(si,sj,-1));
  auto in = [&](unsigned int ii, unsigned int jj) -> bool {
    return ii<h&&jj<w;
  };
  vector dist(h,vector(w,vector<int>(2,INF)));
  rep(i,2) dist.at(si).at(sj).at(i) = 0;
  while(q.size()) {
    auto [vi,vj,d] = q.front();q.pop();
    if(d!=0) { // 直前に横でない
      rep(dd,2) {
        auto [di,dj] = dir.at(dd);
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(ni,nj)) continue;
        if(s.at(ni).at(nj)=='#') continue;
        if(dist.at(ni).at(nj).at(0)!=INF) continue;
        dist.at(ni).at(nj).at(0) = dist.at(vi).at(vj).at(1) + 1;
        q.push(tuple(ni,nj,0));
      }
    }
    if(d!=1) { // 直前に縦でない
      reps(dd,2,4) {
        auto [di,dj] = dir.at(dd);
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(ni,nj)) continue;
        if(s.at(ni).at(nj)=='#') continue;
        if(dist.at(ni).at(nj).at(1)!=INF) continue;
        dist.at(ni).at(nj).at(1) = dist.at(vi).at(vj).at(0) + 1;
        q.push(tuple(ni,nj,1));
      }
    }
  }
  int ans = INF;
  rep(i,2) chmin(ans,dist.at(gi).at(gj).at(i));
  if(ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
}
