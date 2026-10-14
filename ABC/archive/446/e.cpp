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
  ll m,a,b;cin>>m>>a>>b;
  ll n = 10001000;
  // int n=10010;
  vector g(n,vector<int>());
  auto conv=[&](int i,int j)->int{
    return i*1000+j;
  };
  auto rconv=[&](int v)->pair<int,int>{
    return pair(v/1000,v%1000);
  };
  rep(i,m)rep(j,m){
    int v=conv(i,j);
    int k=b*i+a*j;
    int u=conv(j%m,k%m);
    g.at(u).push_back(v);
  }
  vector seen(n,false);
  queue<int>q;
  rep(i,m)q.push(conv(0,i)),seen.at(conv(0,i))=true;
  reps(i,1,m)q.push(conv(i,0)),seen.at(conv(i,0))=true;
  while(q.size()){
    auto v=q.front();q.pop();
    for(auto nv:g.at(v)){
      if(seen.at(nv))continue;
      seen.at(nv)=true;
      q.push(nv);
    }
  }
  ll ans=m*m;
  rep(i,n)if(seen.at(i))ans--;
  cout<<ans<<endl;

  return 0;
}
