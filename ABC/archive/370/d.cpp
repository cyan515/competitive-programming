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
  int h,w,Q;cin>>h>>w>>Q;
  vector<string> ans(h,string(w,'#'));
  vector<fenwick_tree<int>> hor(h,fenwick_tree<int>(w));
  vector<fenwick_tree<int>> ver(w,fenwick_tree<int>(h));
  auto f = [&](fenwick_tree<int>& ft, int ok, int ng) -> int {
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      bool flg = true;
      if(mid>=ok) {
        flg = ft.sum(ok,mid) == abs(mid-ok);
      } else {
        flg = ft.sum(mid+1,ok+1) == abs(mid-ok);
      }
      if(flg) ok = mid;
      else ng = mid;
    }
    return ok;
  };
  while(Q--) {
    int r,c;cin>>r>>c;r--;c--;
    if(ans.at(r).at(c)=='#') {
      hor.at(r).add(c,1);
      ver.at(c).add(r,1);
      ans.at(r).at(c) = '.';
    } else {
      int down = f(ver.at(c),r,h);
      int up = f(ver.at(c),r,-1);
      int right = f(hor.at(r),c,w);
      int left = f(hor.at(r),c,-1);
      if(ver.at(c).sum(down,down+1)==0) ver.at(c).add(down,1);
      if(ver.at(c).sum(up,up+1)==0) ver.at(c).add(up,1);
      if(ver.at(right).sum(r,r+1)==0) ver.at(right).add(r,1);
      if(ver.at(left).sum(r,r+1)==0) ver.at(left).add(r,1);
      if(hor.at(r).sum(left,left+1)==0) hor.at(r).add(left,1);
      if(hor.at(r).sum(right,right+1)==0) hor.at(r).add(right,1);
      if(hor.at(down).sum(c,c+1)==0) hor.at(down).add(c,1);
      if(hor.at(up).sum(c,c+1)==0) hor.at(up).add(c,1);
      ans.at(down).at(c) = '.';
      ans.at(up).at(c) = '.';
      ans.at(r).at(left) = '.';
      ans.at(r).at(right) = '.';
    }
  }
  int cnt = 0;
  rep(i,h) rep(j,w) {
    if(ans.at(i).at(j)=='#') cnt++;
  }
  cout << cnt << endl;

  return 0;
}
