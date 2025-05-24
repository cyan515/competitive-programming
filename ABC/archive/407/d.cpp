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
  vector a(h,vector<ll>(w));
  rep(i,h) cin>>a.at(i);
  vector x(h,vector<bool>(w,false));
  ll cur = 0;
  ll ans = 0;
  auto in = [&](unsigned ii, unsigned jj) -> bool {
    return ii<h&&jj<w;
  };
  auto dfs = [&](auto self,int vi,int vj) -> void {
    if(vi==h-1&&vj==w-1) {
      if(x.at(vi).at(vj)) {
        chmax(ans,cur);
      } else {
        cur ^= a.at(vi).at(vj);
        chmax(ans,cur);
        cur ^= a.at(vi).at(vj);
      }
      return ;
    }
    int ni = vi;
    int nj = vj+1;
    ni += nj/w;
    nj %= w;
    if(in(vi,vj+1) && !x.at(vi).at(vj) && !x.at(vi).at(vj+1)) {
      x.at(vi).at(vj) = true;
      x.at(vi).at(vj+1) = true;
      self(self,ni,nj);
      x.at(vi).at(vj) = false;
      x.at(vi).at(vj+1) = false;
    }
    if(in(vi+1,vj) && !x.at(vi).at(vj) && !x.at(vi+1).at(vj)) {
      x.at(vi).at(vj) = true;
      x.at(vi+1).at(vj) = true;
      self(self,ni,nj);
      x.at(vi).at(vj) = false;
      x.at(vi+1).at(vj) = false;
    }
    if(x.at(vi).at(vj)) {
      self(self,ni,nj);
    } else {
      cur ^= a.at(vi).at(vj);
      self(self,ni,nj);
      cur ^= a.at(vi).at(vj);
    }
  };
  dfs(dfs,0,0);
  cout << ans << endl;

  return 0;
}
