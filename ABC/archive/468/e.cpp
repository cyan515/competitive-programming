#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using mint=atcoder::modint998244353;
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
using S=pair<mint,mint>;// val,len
S op(S a,S b){
  return pair(a.first+b.first,a.second+b.second);
}
S e(){
  return pair(0,0);
}
using F=mint;
S mapping(F f,S s){
  return pair(s.first+s.second*f,s.second);
}
F comp(F f,F g){
  return f+g;
}
F id(){
  return 0;
}
int main() {
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  mint ans=0;
  lazy_segtree<S,op,e,F,mapping,comp,id>seg(n);
  rep(i,n)seg.set(i,pair(0,1));
  rep(i,n){
    int x=min(i+1,n-i);
    seg.apply(0,x,a.at(i));
    if(n-x+1<n)seg.apply(n-x+1,n,-a.at(i));
  }
  reps(i,1,n){
    seg.apply(i,seg.get(i-1).first);
  }
  rep(i,n){
    ans+=seg.get(i).first/mint(i+1);
  }
  cout<<ans.val()<<endl;

  return 0;
}
