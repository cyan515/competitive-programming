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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,Q;cin>>n>>Q;
  vector<ll>a(n),b(n);cin>>a>>b;
  vector<ll>aa={0};
  rep(_,2)rep(i,n)aa.push_back(a.at(i));
  rep(i,aa.size()-1)aa.at(i+1)+=aa.at(i);
  vector g(n+1,vector<pair<ll,int>>());
  rep(i,n){
    g.at(i).push_back(pair(a.at(i),(i+1)%n));
    g.at((i+1)).push_back(pair(a.at(i),i));
    g.at(i).push_back(pair(b.at(i),n));
    g.at(n).push_back(pair(b.at(i),i));
  }
  auto dists=dijkstra(g,{n});
  while(Q--){
    int s,t;cin>>s>>t;s--;t--;
    if(s>t)swap(s,t);
    if(t==n){
      cout<<dists.at(s)<<endl;
      continue;
    }
    ll d1=dists.at(s)+dists.at(t);
    ll d2=aa.at(t)-aa.at(s);
    ll d3=aa.at(s+n)-aa.at(t);
    cout<<min(d1,min(d2,d3))<<endl;
  }

  return 0;
}
