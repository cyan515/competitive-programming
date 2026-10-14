#include <bits/stdc++.h>
#include <atcoder/dsu>
#include <atcoder/modint>
using namespace atcoder;
using mint=modint998244353;
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
  int n,m;cin>>n>>m;
  string s;cin>>s;
  vector<int>a(m),b(m);
  rep(i,m)cin>>a.at(i)>>b.at(i),a.at(i)--,b.at(i)--;
  vector g(n,vector<int>());
  rep(i,m)g.at(a.at(i)).push_back(b.at(i)),g.at(b.at(i)).push_back(a.at(i));
  dsu uf(n);
  rep(i,m)uf.merge(a.at(i),b.at(i));
  bool dup=false;
  mint ans=1;
  auto fact=[](int x)->mint{
    mint ret=1;
    while(x>0)ret*=x,x--;
    return ret;
  };
  for(auto vec:uf.groups()){
    mint cnt=1;
    map<char,int>ccnt;
    for(auto v:vec){
      if(++ccnt[s.at(v)]>=2)dup=true;
    }
    ans*=fact(vec.size());
    for(auto [kk,vv]:ccnt){
      ans/=fact(vv);
    }
  }
  if(!dup)ans/=2;
  cout<<ans.val()<<endl;

  return 0;
}
