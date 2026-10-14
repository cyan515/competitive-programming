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
  ll n;cin>>n;
  vector<ll>a(n);cin>>a;
  vector g(n,vector<int>());
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector<string>ans(n,No);
  map<int,int>mp;
  int cnt=0;
  auto dfs=[&](auto self,int v,int p)->void{
    bool f=false;
    auto it = mp.find(a.at(v));
    if(it!=mp.end()&&(*it).second!=0)f=true;
    if(f)cnt++;
    if(cnt>0)ans.at(v)=Yes;
    mp[a.at(v)]++;
    for(auto nv:g.at(v)){
      if(nv==p)continue;
      self(self,nv,v);
    }
    mp[a.at(v)]--;
    if(f)cnt--;
  };
  dfs(dfs,0,-1);
  rep(i,n)cout<<ans.at(i)<<endl;

  return 0;
}
