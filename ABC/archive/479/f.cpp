// for my libraries, refer to https://github.com/cyan515/competitive-programming
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
#include<atcoder/lazysegtree.hpp>
using namespace atcoder;
// num,x
using S=pair<int,ll>;
S op(S a,S b){
  if(a.second<b.second)return b;
  else return a;
}
S e(){return pair(-1,-INF);}
using F=int;
S mapping(F f,S s){
  return pair(s.first,s.second+f);
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
  vector<int>a(n),b(n);cin>>a>>b;
  vector<int>ord(n);
  rep(i,n)ord.at(i)=i;
  sort(all(ord),[&](int i,int j)->bool{
    return b.at(i)<b.at(j);
  });
  lazy_segtree<S,op,e,F,mapping,comp,id>seg(n);
  rep(i,n){
    int o=ord.at(i);
    seg.set(i,pair(o,a.at(o)));
  }
  ll ans=0;
  rep(rank,n){
    auto [num,from]=seg.get(rank);
    auto to=b.at(num);
    ans+=abs(from-to);
    if(from<to){
      auto l = rank + 1;
      auto r = seg.max_right(l, [&](S s) {
        return s.second <= from;
      });
      seg.apply(l, r, 1);
      seg.apply(l,r,-1);
    }else if(from>to){
      auto l=rank+1;
      auto r=seg.max_right(l,
        [&](S s){
          return s.second<=from;
        }
     );
     seg.apply(l,r,1);
   }
  }
  cout<<ans<<endl;

  return 0;
}
