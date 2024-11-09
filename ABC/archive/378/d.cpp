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
  int k;cin>>k;
  vector<string> s(h);cin>>s;
  auto in = [&](unsigned x,unsigned y) -> bool {
    return x<h&&y<w;
  };
  vector seen(h,vector<bool>(w,false));
  auto f = [&](auto f,int x,int y,int t) -> int {
    if(t==k) return 1;
    int ret = 0;
    seen.at(x).at(y) = true;
    for(auto [dx,dy] : dir) {
      int nx = x+dx;
      int ny = y+dy;
      if(!in(nx,ny)) continue;
      if(s.at(nx).at(ny)=='#') continue;
      if(seen.at(nx).at(ny)) continue;
      ret += f(f,nx,ny,t+1);
    }
    seen.at(x).at(y) = false;
    return ret;
  };
  int ans = 0;
  rep(si,h) rep(sj,w) {
    if(s.at(si).at(sj)=='#') continue;
    int cnt = f(f,si,sj,0);
    ans += cnt;
  }
  cout << ans << endl;

  return 0;
}
