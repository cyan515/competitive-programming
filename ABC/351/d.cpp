#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  auto conv = [&](int i,int j) -> int {
    return i*w+j;
  };
  auto rconv = [&](int v) -> pair<int,int> {
    return pair(v/w,v%w);
  };
  auto in = [&](unsigned int i,unsigned int j) -> bool {
    return i<h&&j<w;
  };
  vector mov(h,vector<bool>(w,true));
  vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='#') {
      mov.at(i).at(j)=false;
      continue;
    }
    bool can = true;
    for(auto [di,dj] : dir) {
      int ni = i+di;
      int nj = j+dj;
      if(!in(ni,nj)) continue;
      can &= s.at(ni).at(nj)!='#';
    }
    mov.at(i).at(j) = can;
  }
  dsu uf(h*w);
  rep(i,h) rep(j,w) {
    for(auto [di,dj] : dir) {
      int ni = i+di;
      int nj = j+dj;
      if(!in(ni,nj)) continue;
      if(mov.at(i).at(j)&&mov.at(ni).at(nj)) uf.merge(conv(i,j),conv(ni,nj));
    }
  }
  map<int,int> mp;
  ll ans = 0;
  for(auto vec : uf.groups()) {
    set<int> st;
    for(auto ele : vec) {
      auto [i,j] = rconv(ele);
      if(!mov.at(i).at(j)) continue;
      for(auto [di,dj] : dir) {
        int ni = i+di;
        int nj = j+dj;
        if(!in(ni,nj)) continue;
        if(!mov.at(ni).at(nj)&&s.at(ni).at(nj)!='#') st.insert(conv(ni,nj));
      }
    }
    chmax(ans,(ll)vec.size()+(ll)st.size());
  }
  cout << ans << endl;

  return 0;
}
