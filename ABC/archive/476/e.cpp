#include <bits/stdc++.h>
using namespace std;
#include<atcoder/segtree.hpp>
using namespace atcoder;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// val,idx
using S=pair<int,int>;
S op1(S a,S b){
  return max(a,b);
}
S e1(){
  return pair(-INF,-1);
}
S op2(S a,S b){
  return min(a,b);
}
S e2(){
  return pair(INF,-1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m;cin>>n>>m;
  vector<ll>p(n);cin>>p;
  vector<ll>l(m),r(m);
  rep(i,m)cin>>l.at(i)>>r.at(i);
  segtree<S,op1,e1>seg(n);
  segtree<S,op2,e2>teg(n);
  rep(i,m)l.at(i)--;
  rep(i,n){
    seg.set(i,pair(p.at(i),i));
    teg.set(i,pair(p.at(i),i));
  }
  rep(i,m){
    auto x=seg.prod(l.at(i),r.at(i));
    auto y=teg.prod(l.at(i),r.at(i));
    if(x.second==-1)continue;
    {
      auto tmp=seg.get(y.second);
      seg.set(y.second,pair(x.first,y.second));
      seg.set(x.second,pair(tmp.first,x.second));
    }
    {
      auto tmp=teg.get(x.second);
      teg.set(x.second,pair(y.first,x.second));
      teg.set(y.second,pair(tmp.first,y.second));
    }
  }
  rep(i,n){
    if(i)cout<<" ";
    cout<<seg.get(i).first;
  }
  cout<<endl;

  return 0;
}
