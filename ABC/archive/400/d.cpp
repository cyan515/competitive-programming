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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
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
  int h,w;cin>>h>>w;
  vector<string> s(h);cin>>s;
  int a,b,c,d;cin>>a>>b>>c>>d;a--;b--;c--;d--;
  auto in = [&](unsigned ii,unsigned jj) -> bool {
    return ii<h&&jj<w;
  };
  auto conv = [&](int ii,int jj) -> int {
    return ii*w+jj;
  };
  vector g(h*w,vector<pair<ll,ll>>());
  rep(i,h) rep(j,w) {
    for(auto [di,dj] : dir) {
      int ni = i+di;
      int nj = j+dj;
      if(!in(ni,nj)) continue;
      if(s.at(ni).at(nj)=='.') g.at(conv(i,j)).push_back(pair(0,conv(ni,nj)));
      if(s.at(ni).at(nj)=='#') {
        g.at(conv(i,j)).push_back(pair(1,conv(ni,nj)));
        ni += di;
        nj += dj;
        if(!in(ni,nj)) continue;
        g.at(conv(i,j)).push_back(pair(1,conv(ni,nj)));
      }
    }
  }
  auto dist = dijkstra(g,conv(a,b));
  cout << dist.at(conv(c,d)) << endl;

  return 0;
}
