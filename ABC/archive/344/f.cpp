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
vector<vector<ll>> p;
ll n;

ll cd(ll a,ll b) {
  int i = a/n;
  int j = a%n;
  int k = b/n;
  int l = b%n;
  return abs(i-k)+abs(j-l);
}

vector<ll> dijkstra(const vector<vector<pair<ll,ll>>>& G,int V=0) {
  
  priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>> q;
  q.emplace(0,V,0);
  vector<ll> dists(G.size(),LINF);
  dists.at(V) = 0;
  while(q.size()) {
    auto [d,v,mon] = q.top();q.pop();
    ll fd = d - mon/p.at(v/n).at(v%n);
    if(dists.at(v) < fd) continue;
    for(auto [w,nv] : G.at(v)) {
      int wait = w - cd(v,nv);
      wait -= mon/p.at(v/n).at(v%n);
      if(dists.at(nv) <= dists.at(v)+cd(v,nv)+wait) continue;
      dists.at(nv) = dists.at(v) + w;
      ll rmon = mon+cd(v,nv)*p.at(v/n).at(v%n)-w;
      q.emplace(dists.at(v)+w,nv,rmon);
    }
  }
  return dists;
}

int main() {
  cin>>n;
  p.resize(n);
  rep(i,n) p.at(i).resize(n);
  rep(i,n) cin>>p.at(i);
  vector r(n,vector<ll>(n-1));
  rep(i,n) cin>>r.at(i);
  vector d(n-1,vector<ll>(n));
  rep(i,n-1) cin>>d.at(i);
  vector pref(n,vector<ll>(n,LINF));
  pref.at(0).at(0) = 0;
  rep(i,n) rep(j,n) {
    if(i!=n-1) {
      chmin(pref.at(i+1).at(j),pref.at(i).at(j)+d.at(i).at(j));
    }
    if(j!=n-1) {
      chmin(pref.at(i).at(j+1),pref.at(i).at(j)+r.at(i).at(j));
    }
  }
  vector g(n*n,vector<pair<ll,ll>>());
  rep(i,n) rep(j,n) reps(x,i,n) reps(y,j,n) {
    if(x==i && y==j) continue;
    ll v = i*n+j;
    ll nv = x*n+y;
    ll cst = pref.at(x).at(y) - pref.at(i).at(j);
    g.at(v).emplace_back(cst/p.at(i).at(j)+x-i+y-j,nv);
  }
  auto dist = dijkstra(g);
  cout << dist.at(n*n-1) << endl;

  return 0;
}
