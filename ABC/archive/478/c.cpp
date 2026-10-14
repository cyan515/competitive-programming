#include <bits/stdc++.h>
#include<atcoder/segtree.hpp>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
using S=ll;
S op1(S a,S b){return max(a,b);}
S e1(){return -INF;}
S op2(S a,S b){return min(a,b);}
S e2(){return INF;}
using namespace atcoder;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,k;cin>>n>>k;
  vector<ll>a(n);cin>>a;
  segtree<S,op1,e1>ma(n);
  segtree<S,op2,e2>mi(n);
  rep(i,n){
    ma.set(i,a.at(i));
    mi.set(i,a.at(i));
  }
  vector<bool>pref(n,false),suff(n,false);
  pref.at(0)=true;
  suff.at(n-1)=true;
  rep(i,n-1){
    pref.at(i+1)=pref.at(i)&&a.at(i)<=a.at(i+1);
  }
  for(int i=n-2;i>=0;i--){
    suff.at(i)=suff.at(i+1)&&a.at(i)<=a.at(i+1);
  }
  rep(i,n){
    if(i+k>n)break;
    bool pre=i==0||pref.at(i-1);
    bool suf=i+k+1>=n||suff.at(i+k+1);
    if(!pre||!suf)continue;
    auto lo=mi.prod(i,i+k);
    auto hi=ma.prod(i,i+k);
    auto lhi=ma.prod(0,i);
    auto rlo=mi.prod(i+k,n);
    if(lhi<=lo&&hi<=rlo){
      cout<<Yes<<endl;
      return 0;
    }
  }
  cout<<No<<endl;

  return 0;
}
