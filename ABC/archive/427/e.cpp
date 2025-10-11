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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  int ci,cj;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='T') ci = i, cj = j;
  }
  // current i, current j, upper done, lower done, left done, right done
  vector dp(h,vector(w,vector(h,vector(h,vector(w,vector(w,INF))))));
  dp.at(ci).at(cj).at(0).at(0).at(0).at(0) = 0;
  queue<tuple<int,int,int,int,int,int>> q;
  q.push(tuple(ci,cj,0,0,0,0));
  auto in = [&](unsigned i,unsigned j) -> bool {
    return i<h&&j<w;
  };
  while(q.size()) {
    auto [vi,vj,le,ri,up,lo] = q.front();q.pop();
    for(auto [di,dj] : dir) {
      int ni = vi+di;
      int nj = vj+dj;
      if(!in(ni,nj)) continue;
    }
  }

  return 0;
}
