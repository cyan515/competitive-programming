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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  vector g(n,vector<int>());
  rep(i,m){
    int a,b;cin>>a>>b;a--;b--;
    g.at(a).push_back(b);
  }
  vector<int>dist(n,INF);
  queue<int>q;
  q.push(0);
  dist.at(0)=0;
  while(q.size()){
    auto v=q.front();q.pop();
    for(auto nv:g.at(v)){
      if(dist.at(nv)!=INF)continue;
      dist.at(nv)=dist.at(v)+1;
      q.push(nv);
    }
  }
  int ans=0;
  rep(i,n)if(dist.at(i)!=INF)ans++;
  cout<<ans<<endl;

  return 0;
}
