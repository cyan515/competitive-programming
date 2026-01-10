#include <bits/stdc++.h>
#include <atcoder/segtree>
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
using S = tuple<ll,ll,ll,ll,int,int,int,int>;
S op(S a,S b) {
  auto [x,y,z,zz,xi,yi,zi,zzi] = a;
  auto [X,Y,Z,ZZ,XI,YI,ZI,ZZI] = b;
  int nxi,nyi,nzi,nzzi;
  if(x>X) nxi = xi;
  else nxi = XI;
  if(y>Y) nyi = yi;
  else nyi = YI;
  if(z<Z) nzi = zi;
  else nzi = ZI;
  if(zz<ZZ) nzzi = zzi;
  else nzzi = ZZI;
  return tuple(max(x,X),max(y,Y),min(z,Z),min(zz,ZZ),nxi,nyi,nzi,nzzi);
}
S e() {
  return tuple(-LINF,-LINF,LINF,LINF,-1,-1,-1,-1);
}
int main() {
  int n,Q;cin>>n>>Q;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  vector<ll> xx(n),yy(n);
  rep(i,n) {
    xx.at(i) = x.at(i)-y.at(i);
    yy.at(i) = x.at(i)+y.at(i);
  }
  segtree<S,op,e> seg(n);
  rep(i,n) {
    seg.set(i,tuple(xx.at(i),yy.at(i),xx.at(i),yy.at(i),i,i,i,i));
  }
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      ll idx,x0,y0;cin>>idx>>x0>>y0;idx--;
      ll X = x0-y0;
      ll Y = x0+y0;
      seg.set(idx,tuple(X,Y,X,Y,idx,idx,idx,idx));
      x.at(idx) = x0;
      y.at(idx) = y0;
      xx.at(idx) = X;
      yy.at(idx) = Y;
    } else {
      ll l,r,x0,y0;cin>>l>>r>>x0>>y0;l--;
      ll X = x0-y0;
      ll Y = x0+y0;
      auto [xma,yma,xmi,ymi,i1,i2,i3,i4] = seg.prod(l,r);
      int mai = -1;
      ll ma = -INF;
      if(chmax(ma,abs(X-xma))) mai = i1;
      if(chmax(ma,abs(Y-yma))) mai = i2;
      if(chmax(ma,abs(X-xmi))) mai = i3;
      if(chmax(ma,abs(Y-ymi))) mai = i4;
      cout << abs(x0-x.at(mai)) + abs(y0-y.at(mai)) << endl;
    }
  }

  return 0;
}
