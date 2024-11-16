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
  int n,Q;cin>>n>>Q;
  vector dp(n,LINF);
  dp.at(1) = 0;
  char bh = 'L';
  int bt = 0;
  auto f = [&](int x,int y,int z,int d) -> pair<int,int> {
    if(x==z) return pair(0,y);
    if(d==0) {
      int xz = (z-x+n)%n;
      int xy = (y-x+n)%n;
      int yz = (z-y+n)%n;
      if(xy<=xz) return pair(xz+yz+1,(z+1)%n);
      else return pair(xz,y);
    } else {
      int zx = (x-z+n)%n;
      int yx = (x-y+n)%n;
      int zy = (y-z+n)%n;
      if(yx<=zx) return pair(zx+zy+1,(z-1+n)%n);
      else return pair(zx,y);
    }
  };
  // while(1) {
  //   int a,b,c,d;cin>>a>>b>>c>>d;
  //   auto [x,y] = f(a,b,c,d);
  //   cout << x << " " << y << endl;
  // }
  while(Q--) {
    char h;cin>>h;
    int t;cin>>t;t--;
    vector ndp(n,LINF);
    if(h=='L') {
      if(bh=='L') {
        rep(i,n) rep(j,2) {
          auto [cost,x] = f(bt,i,t,j);
          chmin(ndp.at(x),dp.at(i)+cost);
        }
      } else {
        rep(i,n) rep(j,2) {
          auto [cost,x] = f(i,bt,t,j);
          chmin(ndp.at(x),dp.at(i)+cost);
        }
      }
    } else {
      if(bh=='R') {
        rep(i,n) rep(j,2) {
          auto [cost,x] = f(bt,i,t,j);
          chmin(ndp.at(x),dp.at(i)+cost);
        }
      } else {
        rep(i,n) rep(j,2) {
          auto [cost,x] = f(i,bt,t,j);
          chmin(ndp.at(x),dp.at(i)+cost);
        }
      }
    }
    swap(dp,ndp);
    bh = h;
    bt = t;
  }
  ll ans = INF;
  rep(i,n) chmin(ans,dp.at(i));
  cout << ans << endl;

  return 0;
}
