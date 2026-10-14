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

/**
 * @fn
 * ダイクストラ法
 * @param 隣接リスト表現によるグラフ。pair は (weight, to)
 */
vector<ll> dijkstra(const vector<vector<pair<ll,int>>>& graph, const vector<int>& source_nodes = {0}) {
  
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  for(auto ele : source_nodes) q.push(pair(0,ele));
  vector<ll> dists(graph.size(),LINF);
  for(auto ele : source_nodes) dists.at(ele) = 0;
  while(q.size()) {
    auto [d,v] = q.top();q.pop();
    if(dists.at(v) < d) continue;
    for(auto [w,nv] : graph.at(v)) {
      if(dists.at(nv) <= dists.at(v)+w) continue;
      dists.at(nv) = dists.at(v) + w;
      q.emplace(dists.at(v)+w,nv);
    }
  }
  return dists;
}

int main() {
  ll n,m,y;cin>>n>>m>>y;
  int IN=n;
  int OUT=n+1;
  vector g(n+2,vector<pair<ll,int>>());
  rep(i,m){
    int u,v;cin>>u>>v;u--;v--;
    ll w;cin>>w;
    g.at(u).push_back(pair(w,v));
    g.at(v).push_back(pair(w,u));
  }
  vector<ll>x(n);cin>>x;
  rep(i,n){
    g.at(i).push_back(pair(x.at(i),IN));
    g.at(OUT).push_back(pair(x.at(i),i));
  }
  g.at(IN).push_back(pair(y,OUT));
  auto ans=dijkstra(g);
  reps(i,1,n){
    if(i!=1)cout<<" ";
    cout<<ans.at(i);
  }
  cout<<endl;

  return 0;
}
