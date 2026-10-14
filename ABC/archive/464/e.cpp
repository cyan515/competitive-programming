#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
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
// j,i
using S=pair<int,int>;
S op(S a,S b){
  return min(a,b);
}
S e(){
  return pair(INF,INF);
}

int main() {
  ll h,w,Q;cin>>h>>w>>Q;
  bool flg=false;
  // if(h>=w){
  //   flg=true;
  //   swap(h,w);
  // }
  vector ans(h,string(w,'A'));
  vector<ll>rs(Q),cs(Q);
  vector<char>xs(Q);
  rep(i,Q)cin>>rs.at(i)>>cs.at(i)>>xs.at(i);
  reverse(all(rs));
  reverse(all(cs));
  reverse(all(xs));
  segtree<S,op,e>seg(h);
  rep(i,h)seg.set(i,pair(0,i));
  rep(qi,Q){
    ll r=rs.at(qi);r--;
    ll c=cs.at(qi);c--;
    char x=xs.at(qi);
    while(1){
      auto res=seg.prod(0,r+1);
      if(res.first>c)break;
      ans.at(res.second).at(res.first)=x;
      seg.set(res.second,pair(res.first+1,res.second));
    }
  }
  if(!flg)rep(i,h)cout<<ans.at(i)<<endl;
  // else{
  //   rep(j,w)rep(i,h){
  //     cout<<ans.at(i).at(j);
  //     if(i==h-1)cout<<endl;
  //   }
  // }

  return 0;
}
