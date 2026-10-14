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
// vol,idx
using S=pair<int,int>;
using F=int;
S op(S a,S b){
  return max(a,b);
}
S e(){
  return pair(-INF,-1);
}
S mapping(F f,S s){
  return pair(s.first+f,s.second);
}
F comp(F f,F g){
  return f+g;
}
F id(){
  return 0;
}

int main() {
  int Q;cin>>Q;
  int QQ=Q;
  int v;cin>>v;
  lazy_segtree<S,op,e,F,mapping,comp,id>seg(Q);
  rep(i,Q){
    seg.set(i,e());
  }
  int cnt=0;
  int cur=0;
  int ci=0;
  while(Q--){
    int op;cin>>op;
    if(op==1){
      int t,w;cin>>t>>w;
      seg.apply(0,QQ,t-cur);
      seg.set(ci,pair(w,ci));
      ci++;
      cur=t;
      cnt++;
    }else{
      int t;cin>>t;
      seg.apply(0,QQ,t-cur);
      cur=t;
      if(cnt==0){
        cout<<-1<<endl;
        continue;
      }
      cnt--;
      auto x=seg.all_prod();
      int ans=min(x.first,v);
      cout<<ans<<endl;
      seg.set(x.second,e());
    }
  }

  return 0;
}
