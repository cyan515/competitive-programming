#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

vector<ll> dijkstra(const vector<vector<pair<ll,ll>>>& G,int V=0) {
  
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  q.emplace(0,V);
  vector<ll> dists(G.size(),LINF);
  dists.at(V) = 0;
  while(q.size()) {
    auto [d,v] = q.top();q.pop();
    if(dists.at(v) < d) continue;
    for(auto [w,nv] : G.at(v)) {
      if(dists.at(nv) <= dists.at(v)+w) continue;
      dists.at(nv) = dists.at(v) + w;
      q.emplace(dists.at(v)+w,nv);
    }
  }
  return dists;
}

int main() {
  int n;cin>>n;
  vector g(n,vector<pair<ll,ll>>());
  rep(i,n-1) {
    ll a,b,x;cin>>a>>b>>x;x--;
    g.at(i).emplace_back(a,i+1);
    g.at(i).emplace_back(b,x);
  }
  auto dists = dijkstra(g);
  cout << dists.at(n-1) << endl;

  exit(0);
}
