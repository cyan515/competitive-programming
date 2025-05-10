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
  queue<pair<int,int>> q;
  vector seen(h,vector<bool>(w,false));
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='E') {
      seen.at(i).at(j) = true;
      q.push({i,j});
    }
  }
  auto in = [&](unsigned ii, unsigned jj) -> bool {
    return ii<h&&jj<w;
  };
  string d = "<>^v";
  while(q.size()) {
    auto [vi,vj] = q.front();q.pop();
    rep(i,4) {
      auto [di,dj] = dir.at(i);
      int ni = vi+di;
      int nj = vj+dj;
      if(!in(ni,nj)) continue;
      if(seen.at(ni).at(nj)) continue;
      if(s.at(ni).at(nj)=='#') continue;
      seen.at(ni).at(nj) = true;
      q.push({ni,nj});
      s.at(ni).at(nj) = d.at(i);
    }
  }
  rep(i,h) cout << s.at(i) << endl;

  return 0;
}
