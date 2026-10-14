#include <bits/stdc++.h>
#include <atcoder/dsu>
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

int main() {
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  dsu uf(n);
  // i を約数にもつ index ただし 1 除く
  vector b(1000100,vector<int>());
  rep(i,n){
    for(ll x=1;x*x<=a.at(i);x++){
      if(a.at(i)%x)continue;
      b.at(x).push_back(i);
      if(x*x!=a.at(i))b.at(a.at(i)/x).push_back(i);
      b.at(a.at(i)).push_back(i);
    }
  }
  ll ans=0;
  for(int x=1000100-1;x>=0;x--){
    if(b.at(x).empty())continue;
    auto u=b.at(x).front();
    for(auto v:b.at(x)){
      if(uf.same(u,v))continue;
      uf.merge(u,v);
      ans+=x;
    }
  }
  cout<<ans<<endl;

  return 0;
}
