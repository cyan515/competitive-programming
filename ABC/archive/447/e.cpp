#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace atcoder;
using mint = modint998244353;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  // vector g(n,vector<pair<int,ll>>());
  // rep(i,m){
  //   int u,v;cin>>u>>v;u--;v--;
  //   // 2 の冪乗であることに注意
  //   g.at(u).push_back(pair(v,i+1));
  //   g.at(v).push_back(pair(u,i+1));
  // }
  vector<pair<int,int>> es(m);
  rep(i,m){
    int u,v;cin>>u>>v;u--;v--;
    es.at(i)=pair(u,v);
  }
  dsu uf(n);
  int cnt=n;
  mint ans=0;
  for(int i=m-1;i>=0;i--){
    auto [u,v]=es.at(i);
    if(uf.same(u,v))continue;
    else {
      if(cnt==2){
        ans+=mint(2).pow(i+1);
      }else{
        uf.merge(u,v);
        cnt--;
      }
    }
  }
  cout<<ans.val()<<endl;

  return 0;
}
