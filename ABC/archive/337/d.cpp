#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
  int h,w,k;cin>>h>>w>>k;
  vector<string> s(h);cin>>s;
  vector seen(h,vector(w,vector<bool>(2,false)));
  vector<pair<int,int>> dlt = {{0,1},{1,0}};
  auto in = [&](int i,int j) -> bool {
    return 0<=i && i<h && 0<=j && j<w;
  };
  int ans = INF;
  auto f = [&](int vi,int vj,int dir) -> int {
    auto [di,dj] = dlt.at(dir);
    int ni = vi;
    int nj = vj;
    int ret = INF;
    int len = 0;
    int cnt = 0;
    while(in(ni,nj) && s.at(ni).at(nj)!='x') {
      seen.at(ni).at(nj).at(dir) = true;
      if(s.at(ni).at(nj)=='o') len++;
      else len++,cnt++;
      if(len>k) {
        if(s.at(ni-di*k).at(nj-dj*k)=='.') cnt--;
      }
      if(len>=k) {
        ret = min(ret,cnt);
      }
      ni += di;
      nj += dj;
    }
    return ret;
  };
  rep(i,h) rep(j,w) {
    rep(dir,2) {
      if(seen.at(i).at(j).at(dir)) continue;
      ans = min(ans,f(i,j,dir));
    }
  }
  if(ans==INF) ans = -1;
  cout << ans << endl;

  exit(0);
}
