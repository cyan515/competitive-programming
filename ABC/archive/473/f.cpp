#include <bits/stdc++.h>
#include<atcoder/lazysegtree>
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
using S=int;
S op(S a,S b){
  return min(a,b);
}
S e(){
  return INF;
}
using F=int;
S mapping(F f,S s){
  return f+s;
}
F comp(F f,F g){
  return f+g;
}
F id(){
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;cin>>n;
  string s;cin>>s;
  lazy_segtree<S,op,e,F,mapping,comp,id>seg(n);
  {
    int sum=0;
    rep(i,n){
      if(s.at(i)=='A')sum++;
      else sum--;
      seg.set(i,sum);
    }
  }
  int Q;cin>>Q;
  while(Q--){
    int op;cin>>op;
    if(op==1){
      int x;char c;cin>>x>>c;x--;
      if(s.at(x)==c)continue;
      s.at(x)=c;
      if(c=='A'){
        seg.apply(x,n,2);
      }else{
        seg.apply(x,n,-2);
      }
    }else{
      int l,r;cin>>l>>r;l--;
      int le;
      if(l==0)le=0;
      else le=seg.get(l-1);
      int ri=seg.get(r-1);
      int mi=seg.prod(l,r);
      if(le<=ri&&mi>=le)cout<<Yes<<endl;
      else cout<<No<<endl;
    }
  }

  return 0;
}
