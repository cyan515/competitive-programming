#include <bits/stdc++.h>
#include <atcoder/scc>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--){
    ll n,m;cin>>n>>m;
    vector<pair<int,int>>es(m);
    rep(i,m){
      int u,v;cin>>u>>v;u--;v--;
      es.at(i)=pair(u,v);
    }
    int w;cin>>w;
    vector<string>s(n);cin>>s;
    scc_graph scc(n*w);
    auto conv=[&](int city,int day)->int{
      return n*day+city;
    };
    auto rconv=[&](int v)->pair<int,int>{
      return pair(v%n,v/n);
    };
    rep(i,n){
      rep(j,w)if(s.at(i).at(j)=='o'&&s.at(i).at((j+1)%w)=='o')scc.add_edge(conv(i,j),conv(i,(j+1)%w));
    }
    rep(i,m){
      auto [u,v]=es.at(i);
      rep(j,w){
        if(s.at(u).at(j)=='o'&&s.at(v).at((j+1)%w)=='o')scc.add_edge(conv(u,j),conv(v,(j+1)%w));
        if(s.at(v).at(j)=='o'&&s.at(u).at((j+1)%w)=='o')scc.add_edge(conv(v,j),conv(u,(j+1)%w));
      }
    }
    bool ok=false;
    for(auto g:scc.scc()){
      ok|=g.size()>1;
    }
    cout<<(ok?Yes:No)<<endl;
  }

  return 0;
}
