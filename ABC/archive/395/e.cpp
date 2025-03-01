#include <bits/stdc++.h>
#include <atcoder/all>
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

vector<ll> dijkstra(const vector<vector<pair<ll,ll>>>& graph, const int& source_node=0) {
  
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  q.emplace(0,source_node);
  vector<ll> dists(graph.size(),LINF);
  dists.at(source_node) = 0;
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
  ll n,m,x;cin>>n>>m>>x;
  vector g(n*2,vector<pair<ll,ll>>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(pair(1,v));
    g.at(n+v).push_back(pair(1,n+u));
  }
  rep(i,n) {
    g.at(i).push_back(pair(x,n+i));
    g.at(n+i).push_back(pair(x,i));
  }
  auto dist = dijkstra(g);
  cout << min(dist.at(n-1),dist.at(2*n-1)) << endl;

  return 0;
}
