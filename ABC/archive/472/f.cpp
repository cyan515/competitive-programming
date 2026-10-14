#include <bits/stdc++.h>
#include<atcoder/segtree>
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
// https://ouchimath.com/3point-menseki/
using S=long double;
S op(S a,S b){
  return a+b;
}
S e(){
  return 0.0;
}
int main() {
  int n,Q;cin>>n>>Q;
  vector<int>x(n),y(n);
  rep(i,n)cin>>x.at(i)>>y.at(i);
  segtree<S,op,e>s(n*2),sxg(n*2),syg(n*2);
  rep(i,n-1){
    long double x1=x.at(i);
    long double x2=x.at(i+1);
    long double y1=y.at(i);
    long double y2=y.at(i+1);
    long double ss=x1*y2-x2*y1;
    ss/=2.0;
    s.set(i,ss);
    sxg.set(i,ss*(x1+x2)/3.0);
    syg.set(i,ss*(y1+y2)/3.0);
  }
  {
    long double x1=x.at(n-1);
    long double x2=x.at(0);
    long double y1=y.at(n-1);
    long double y2=y.at(0);
    long double ss=x1*y2-x2*y1;
    ss/=2.0;
    s.set(n-1,ss);
    sxg.set(n-1,ss*(x1+x2)/3.0);
    syg.set(n-1,ss*(y1+y2)/3.0);
  }
  rep(i,n){
    s.set(n+i,s.prod(i,i+1));
    sxg.set(n+i,sxg.prod(i,i+1));
    syg.set(n+i,syg.prod(i,i+1));
  }
  cout<<fixed<<setprecision(20);
  while(Q--){
    int u,v;cin>>u>>v;u--;v--;
    if(v<u)v+=n;
    long double xx=sxg.prod(u,v);
    long double yy=syg.prod(u,v);
    long double ss=s.prod(u,v);
    {
      
    long double x2=x.at(u);
    long double x1=x.at(v%n);
    long double y2=y.at(u);
    long double y1=y.at(v%n);
    long double sss=x1*y2-x2*y1;
    sss/=2.0;
    xx+=sss*(x1+x2)/3.0;
    yy+=sss*(y1+y2)/3.0;
    ss+=sss;
    }
    cout<<xx/ss<<" "<<yy/ss<<endl;
  }

  return 0;
}
