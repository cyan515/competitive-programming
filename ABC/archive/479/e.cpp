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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;cin>>n;
  vector<ll>a(n-1),b(n-1);
  rep(i,n-1)cin>>a.at(i)>>b.at(i),a.at(i)--,b.at(i)--;
  map<pair<int,int>,ll>rev;
  rep(i,n-1)rev[pair(a.at(i),b.at(i))]=i;
  vector g(n,vector<int>());
  rep(i,n-1){
    g.at(a.at(i)).push_back(b.at(i));
    g.at(b.at(i)).push_back(a.at(i));
  }
  vector<ll>cnt(n,0),par(n,-1);
  {
    auto dfs=[&](auto self,int v,int p)->void{
      par.at(v)=p;
      int sum=1;
      for(auto nv:g.at(v)){
        if(nv==p)continue;
        self(self,nv,v);
        sum+=cnt.at(nv);
      }
      cnt.at(v)=sum;
    };
    dfs(dfs,0,-1);
  }
  vector<ll>wc(n,0),lc(n,0);
  {
    ll win=0,lose=0;
    auto dfs=[&](auto self,int v,int p)->void{
      if(p!=-1&&cnt.at(v)>n/2)win+=rev[pair(min(p,v),max(p,v))]+1;
      else if(p!=-1) lose+=rev[pair(min(p,v),max(p,v))]+1;
      wc.at(v)+=win;
      lc.at(v)-=lose;
      for(auto nv:g.at(v)){
        if(nv==p)continue;
        self(self,nv,v);
      }
      if(p!=-1&&cnt.at(v)>n/2)win-=rev[pair(min(p,v),max(p,v))]+1;
      else if(p!=-1) lose-=rev[pair(min(p,v),max(p,v))]+1;
    };
    dfs(dfs,0,-1);
  }
  ll x=0;
  reps(i,1,n){
    if(cnt.at(i)<=n/2){
      x+=rev[pair(min(i,par.at(i)),max(i,par.at(i)))]+1;
    }
  }
  rep(i,n)lc.at(i)+=x;
  rep(i,n){
    if(i)cout<<" ";
    cout<<wc.at(i)+lc.at(i);
  }
  cout<<endl;

  return 0;
}
