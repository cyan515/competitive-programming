#include <bits/stdc++.h>
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
#include<atcoder/lazysegtree>
using namespace atcoder;
using S=int;
S op(S a,S b){
  return max(a,b);
}
S e(){
  return -INF;
}
using F=int;
S mapp(F f,S s){
  return f+s;
}
F comp(F f,F g){
  return f+g;
}
F id(){
  return 0;
}

int main() {
  int n;cin>>n;
  vector<int>a(n);cin>>a;
  lazy_segtree<S,op,e,F,mapp,comp,id>seg(n+1);
  rep(i,n+1)seg.set(i,-INF);
  seg.set(0,0);
  int ma=0;
  rep(i,n){
    if(a.at(i)>ma){
      if(ma>0)seg.apply(0,ma+1,1);
    }else{
      seg.set(a.at(i),max(seg.get(a.at(i)),seg.prod(0,a.at(i))+1));
    }
    chmax(ma,a.at(i));
  }
  int ans=seg.all_prod();
  if(ans<0)ans=0;
  cout<<ans<<endl;

  return 0;
}
