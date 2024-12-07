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
  int d;cin>>d;
  vector<string> s(h);cin>>s;
  queue<pair<int,int>> q;
  vector dist(h,vector<int>(w,INF));
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='H') {
      q.push(pair(i,j));
      dist.at(i).at(j) = 0;
    }
  }
  auto in = [&](unsigned int x,unsigned int y) -> bool {
    return x<h&&y<w;
  };
  while(q.size()) {
    auto [vi,vj] = q.front();q.pop();
    for(auto [di,dj] : dir) {
      int ni = vi+di;
      int nj = vj+dj;
      if(!in(ni,nj)) continue;
      if(s.at(ni).at(nj)=='#') continue;
      if(dist.at(ni).at(nj)!=INF) continue;
      dist.at(ni).at(nj) = dist.at(vi).at(vj) + 1;
      q.push(pair(ni,nj));
    }
  }
  int ans = 0;
  rep(i,h) rep(j,w) ans += dist.at(i).at(j)<=d;
  cout << ans << endl;

  return 0;
}
