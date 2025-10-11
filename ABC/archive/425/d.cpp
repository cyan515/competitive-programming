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
  ll h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  queue<pair<int,int>> q;
  vector seen(h,vector<bool>(w,false));
  auto in =[&](unsigned ii,unsigned jj) -> bool {
    return ii<h&&jj<w;
  };
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='#') continue;
    int cnt = 0;
    for(auto [di,dj]:dir) {
      int ni=i+di;
      int nj=j+dj;
      if(!in(ni,nj)) continue;
      if(s.at(ni).at(nj)=='#') cnt++;
    }
    if(cnt==1) q.push(pair(i,j));
  }
  queue<pair<int,int>> buf;
  while(q.size()) {
    queue<pair<int,int>> qq;
    while(q.size()) {
      auto [vi,vj] = q.front();q.pop();
      buf.push(pair(vi,vj));
      for(auto [di,dj]:dir) {
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(ni,nj)) continue;
        if(seen.at(ni).at(nj)) continue;
        seen.at(ni).at(nj) = true;
        qq.push(pair(ni,nj));
      }
    }
    while(buf.size()) {
      auto [vi,vj] = buf.front();buf.pop();
      s.at(vi).at(vj) = '#';
    }
    while(qq.size()) {
      auto [vi,vj] = qq.front();qq.pop();
      if(s.at(vi).at(vj)=='#') continue;
      int cnt = 0;
      for(auto [di,dj]:dir) {
        int ni = vi+di;
        int nj = vj+dj;
        if(!in(ni,nj)) continue;
        if(s.at(ni).at(nj)=='#') cnt++;
      }
      if(cnt==1) q.push(pair(vi,vj));
    }
  }
  int ans = 0;
  rep(i,h) rep(j,w) if(s.at(i).at(j)=='#') ans++;
  cout << ans << endl;
  // rep(i,h) cout << s.at(i) << endl;

  return 0;
}
