#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
constexpr string_view DIRECTION = "RLDU";
constexpr int INF = 1<<30;

int main() {
  int n;cin>>n;
  vector<string> s(n);cin>>s;
  auto in = [&](unsigned int i, unsigned int j) -> bool {
    return i<n && j<n;
  };
  auto rev = [&](int i) -> int {
    return i%2?i-1:i+1;
  };
  auto is_vertical = [&](int i) -> bool {
    return i>=2;
  };
  
  rep(i,n) rep(j,n) {
    if(s.at(i).at(j)!='x') continue;
    int c = INF;
    int dir_i = -1;
    rep(d,4) {
      auto [di,dj] = dir.at(d);
      int ci = i;
      int cj = j;
      while(in(ci,cj)&&s.at(ci).at(cj)!='o') {
        ci += di;
        cj += dj;
      }
      if(!in(ci,cj)) if(chmin(c,abs(ci-i)+abs(cj-j))) dir_i = d;
    }
    rep(_,c) {
      cout << DIRECTION.at(dir_i) << " " << (is_vertical(dir_i)?j:i) << endl;;
    }
    rep(_,c) {
      cout << DIRECTION.at(rev(dir_i)) << " " << (is_vertical(dir_i)?j:i) << endl;;
    }
  }

  return 0;
}
