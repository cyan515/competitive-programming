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
  int n;cin>>n;
  vector ans(n,vector<int>(n,INF));
  ans.at(n/2).at(n/2) = -1;
  vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
  auto dfs = [&](auto dfs,int vx=0,int vy=0,int num=1,int diri=0) -> void {
    ans.at(vx).at(vy) = num;
    if(num==n*n-1) return;
    auto [dx,dy] = dir.at(diri);
    int nx = vx + dx;
    int ny = vy + dy;
    if(nx<0||n<=nx||ny<0||n<=ny||ans.at(nx).at(ny)!=INF) {
      nx -= dx;
      ny -= dy;
      diri++;
      diri %= 4;
      auto [dxx,dyy] = dir.at(diri);
      nx += dxx;
      ny += dyy;
    }
    dfs(dfs,nx,ny,num+1,diri);
  };
  dfs(dfs);
  rep(i,n) {
    rep(j,n) {
      if(ans.at(i).at(j)==-1) cout << "T";
      else cout << ans.at(i).at(j);
      if(j!=n-1) cout << " ";
    }
    cout << endl;
  }

  exit(0);
}
