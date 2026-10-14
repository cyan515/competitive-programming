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

int main() {
  int Q;cin>>Q;
  while(Q--){
    int n;cin>>n;
    vector g(n,vector<int>());
    int ans=1;
    rep(i,n-1){
      int u,v;cin>>u>>v;u--;v--;
      g.at(u).push_back(v);
      g.at(v).push_back(u);
    }
    vector<int>dp(n,0);
    auto dfs=[&](auto self,int v,int p) -> int {
      vector<int>ch;
      for(auto nv:g.at(v)){
        if(nv==p)continue;
        int t=self(self,nv,v);
        ch.push_back(t);
        chmax(ans,t);
      }
      sort(rall(ch));
      if(ch.size()>=2&&g.at(v).size()>=4){
        chmax(ans,1+ch.at(0)+ch.at(1));
      }
      if(ch.size()>=2&&g.at(v).size()>=3){
        chmax(ans,1+ch.at(0));
      }
      if(ch.size()>=3)return dp.at(v)=1+ch.at(0);
      else if(ch.size()==2)return dp.at(v)=1;
      else return dp.at(v)=0;
    };
    dfs(dfs,0,-1);
    cout<<ans<<endl;
  }

  return 0;
}
