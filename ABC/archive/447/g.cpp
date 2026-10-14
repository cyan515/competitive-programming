#include <bits/stdc++.h>
#include <atcoder/segtree>
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
struct problem {
  int idx,kind,happy;
  bool operator<(const problem& other) const {
    return happy<other.happy;
  }
  bool operator>(const problem& other) const {
    return happy>other.happy;
  }
  bool operator==(const problem& other) const {
    return happy==other.happy;
  }
};
using S = tuple<problem,problem,problem,problem>;
S op(S a,S b) {
  vector<problem>vec(8);
  {
    auto [s,t,u,v]=a;
    vec.at(0)=s;
    vec.at(1)=t;
    vec.at(2)=u;
    vec.at(3)=v;
  }
  {
    auto [s,t,u,v]=b;
    vec.at(4)=s;
    vec.at(5)=t;
    vec.at(6)=u;
    vec.at(7)=v;
  }
  sort(rall(vec));
  return tuple(vec.at(0),vec.at(1),vec.at(2),vec.at(3));
}
S e(){
  auto p = problem(-1,-1,-1);
  return tuple(p,p,p,p);
}

int main() {
  int n;cin>>n;
  vector<int>k(n);
  vector<ll>a(n);
  rep(i,n)cin>>k.at(i)>>a.at(i);
  {
    vector vec(n+1,vector<pair<ll,int>>());
    rep(i,n)vec.at(k.at(i)).push_back(pair(a.at(i),i));
    rep(i,n) sort(rall(vec.at(i)));
    vector<tuple<int,int,ll>> ika;
    rep(i,n+1) rep(j,vec.at(i).size()){
      if(j==2)break;
      ika.push_back(tuple(vec.at(i).at(j).second,i,vec.at(i).at(j).first));
    }
    vector<int>nk;
    vector<ll>na;
    for(auto [ii,kk,aa]:ika){
      nk.push_back(kk);
      na.push_back(aa);
    }
    k=nk;
    a=na;
    n=nk.size();
  }
  segtree<S,op,e> seg(n);
  rep(i,n){
    auto p = problem(-1,-1,-1);
    seg.set(i,tuple(problem(i,k.at(i),a.at(i)),p,p,p));
  }
  rep(i,n) {
    auto [s,t,u,v] = seg.prod(0,i+1);
    int ai=-1,bi=-1,ak=-1;
    vector<problem> vec(4);
    vec.at(0)=s;
    vec.at(1)=t;
    vec.at(2)=u;
    vec.at(3)=v;
    rep(j,4){
      auto [idx,kind,happy] = vec.at(j);
      if(idx==-1)continue;
      if(ai==-1)ai=idx;
      else if(bi==-1&&kind!=ak)bi=idx;
    }
  }

  return 0;
}
