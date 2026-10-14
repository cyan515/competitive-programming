#include <bits/stdc++.h>
#include<atcoder/segtree.hpp>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
using S=bool;
S op(S a,S b){
  return a||b;
}
S e(){
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;cin>>Q;
  string s,t;cin>>s>>t;
  int n=s.size();
  int m=t.size();
  segtree<S,op,e>seg(n);
  rep(i,n){
    bool ok=true;
    if(i+m-1>=n)break;
    rep(j,m){
      ok&=s.at(i+j)==t.at(j);
    }
    seg.set(i,ok);
  }
  while(Q--){
    int l,r;cin>>l>>r;l--;
    if(r-l<m){
      cout<<No<<endl;
    }else{
      auto ans=seg.prod(l,r-m+1);
      cout<<(ans?Yes:No)<<endl;
    }
  }

  return 0;
}
