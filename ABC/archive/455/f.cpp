#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
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
// cost, sum, cnt
using S=tuple<mint,mint,ll>;
using F=mint;
S op(S a,S b){
  auto [acost,asum,acnt]=a;
  auto [bcost,bsum,bcnt]=b;
  mint cost=acost+bcost+asum*bsum;
  mint sum=asum+bsum;
  ll cnt=acnt+bcnt;
  return tuple(cost,sum,cnt);
}
S e(){
  return tuple(0,0,0);
}
S mapping(F f,S s){
  auto [cost,sum,cnt]=s;
  return tuple(cost+f*(cnt-1)*sum+cnt*(cnt-1)/2*f*f,sum+f*cnt,cnt);
}
F comp(F f,F g){
  return f+g;
}
F id(){
  return 0;
}

int main() {
  ll n,Q;cin>>n>>Q;
  lazy_segtree<S,op,e,F,mapping,comp,id>seg(n);
  rep(i,n)seg.set(i,tuple(0,0,1));
  while(Q--){
    ll l,r,x;cin>>l>>r>>x;l--;
    seg.apply(l,r,x);
    auto ans=seg.prod(l,r);
    cout<<get<0>(ans).val()<<endl;
  }

  return 0;
}
