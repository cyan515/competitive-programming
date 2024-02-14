#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint =  modint1000000007;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int h,w;cin>>h>>w;
  int si,sj,gi,gj;cin>>si>>sj>>gi>>gj;
  si--;sj--;gi--;gj--;
  vector<string> s(h);cin>>s;
  deque<tuple<int,int,int>> q;
  q.emplace_front(si,sj,-1);
  vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1},};
  vector dists(h,vector(w,vector<int>(4,INF)));
  rep(i,4) dists.at(si).at(sj).at(i) = 0;
  auto in = [&](int x,int y) -> bool {
    return 0<=x && x<h && 0<=y && y<w;
  };
  while(q.size()) {
    auto [vi,vj,d] = q.front();q.pop_front();
    rep(i,4) {
      auto [dx,dy] = dir.at(i);
      int x = vi+dx;
      int y = vj+dy;
      if(!in(x,y)) continue;
      if(s.at(x).at(y)=='#') continue;
      if(dists.at(x).at(y).at(i)!=INF) continue;
      if(d!=-1 && d!=i) {
        dists.at(x).at(y).at(i) = dists.at(vi).at(vj).at(d)+1;
        q.emplace_back(x,y,i);
      } else {
        dists.at(x).at(y).at(i) = dists.at(vi).at(vj).at(i);
        q.emplace_front(x,y,i);
      }
    }
  }
  int ans = INF;
  rep(i,4) chmin(ans,dists.at(gi).at(gj).at(i));
  cout << ans << endl;
  
  return 0;
}
