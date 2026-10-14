#include <bits/stdc++.h>
#include<atcoder/lazysegtree.hpp>
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
// size, sum
using S=pair<ll,ll>;
using F=ll;
S op(S a,S b){
  return pair(a.first+b.first,a.second+b.second);
}
S e(){
  return pair(0LL,0LL);
}
S mapping(F f,S s){
  return pair(s.first,s.first*f+s.second);
}
F comp(F f,F g){
  return f+g;
}
F id(){
  return 0LL;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m,Q;cin>>n>>m>>Q;
  vector<ll>le(n),ri(n);
  rep(i,n)cin>>le.at(i)>>ri.at(i);
  // down, right
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>q;
  vector<tuple<ll,ll,ll,ll>>qs(Q);
  rep(i,Q){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    qs.at(i)=tuple(a,b,c,d);
    q.push(pair(b,d));
    q.push(pair(b,c-1));
    q.push(pair(a-1,d));
    q.push(pair(a-1,c-1));
  }
  lazy_segtree<S,op,e,F,mapping,comp,id>seg(m+1);
  rep(i,m+1)seg.set(i,pair(1,0));
  map<pair<ll,ll>,ll>memo;
  rep(i,n){
    while(q.size()&&q.top().first==i){
      auto [down,right]=q.top();
      auto val=seg.prod(0,right+1).second;
      memo[q.top()]=val;
      q.pop();
    }
    seg.apply(le.at(i),ri.at(i)+1,1);
    rep(j,m+1)cout<<seg.get(j).second<<" ";cout<<endl;// debug!!!!!!!
  }
  while(q.size()){
    auto [down,right]=q.top();
    memo[q.top()]=seg.prod(0,right+1).second;
    q.pop();
  }
  auto f=[&](ll x,ll y)->ll{
    return memo[pair(x,y)];
  };
  for(auto [a,b,c,d]:qs){
    ll a1=f(b,d);
    ll a2=f(b,c-1);
    ll a3=f(a-1,d);
    ll a4=f(a-1,c-1);
    ll ans=a1-a2-a3+a4;
    cout<<ans<<endl;
  }

  return 0;
}
