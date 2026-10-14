#include <bits/stdc++.h>
using namespace std;
#include<atcoder/scc.hpp>
using namespace atcoder;
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

/**
 * @brief トポロジカルソート
 * @param graph 隣接リスト表現によるグラフ
 * @return トポロジカルソートの結果で辞書順最小のもの。グラフが閉路を含む場合は閉路の前まで
 * @note 1.3 トポロジカルソートの結果で辞書順最小のもの
 * @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/topological-sort
 */
vector<int> topological_sort(const vector<vector<int>>& graph) {
  vector<int> in(graph.size());

  for (auto v : graph) for (auto to : v) in.at(to)++;

  priority_queue<int, vector<int>, greater<int>> q;
  rep(i,graph.size()) {
    if(in.at(i) == 0) q.push(i);
  }
  vector<int> result;
  while (q.size()) {
    int from = q.top();q.pop();
    result.push_back(from);
    for(auto to : graph.at(from)) {
      in.at(to)--;
      if(in.at(to) == 0) q.push(to);
    }
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,m;cin>>n>>m;
  vector<ll>t(m),u(m),v(m);
  rep(i,m)cin>>t.at(i)>>u.at(i)>>v.at(i),u.at(i)--,v.at(i)--;
  auto uu=u;
  auto vv=v;
  map<int,int>mp;
  {
    scc_graph scc(n);
    rep(i,m){
      if(t.at(i)==0)scc.add_edge(u.at(i),v.at(i));
    }
    for(auto e:scc.scc()){
      if(e.size()==1)continue;
      reps(i,1,e.size()){
        mp[e.at(i)]=e.front();
      }
    }
  }
  set<pair<int,int>>es;
  
  vector<int>deg(n,0);
  rep(i,m){
    auto it=mp.find(v.at(i));
    if(it!=mp.end())v.at(i)=(*it).second;
    
    it=mp.find(u.at(i));
    if(it!=mp.end())u.at(i)=(*it).second;
    if(t.at(i)==0&&v.at(i)==u.at(i))continue;
    es.insert(pair(u.at(i),v.at(i)));
    deg.at(v.at(i))++;
  }
  vector g(n,vector<int>());
  for(auto [fr,to]:es)g.at(fr).push_back(to);
  auto top=topological_sort(g);
  if(top.size()<g.size())cout<<No<<endl;
  else {
    cout<<Yes<<endl;
    vector gg(n,vector<pair<ll,int>>());
    rep(i,m){
      ll w;
      if(t.at(i)==0)w=0;
      else w=1;
      gg.at(uu.at(i)).push_back(pair(w,vv.at(i)));
    }
    rep(i,n)sort(rall(gg.at(i)));
    set<int>sc;
    // rep(i,m){
    //   if(u.at(i)==v.at(i))continue;
    //   deg.at(v.at(i))++;
    //   // auto it=mp.find(vv.at(i));
    //   // if(it==mp.end())deg.at(vv.at(i))++;
    //   // else deg.at((*it).second)++;
    // }
    rep(i,n){
      auto it=mp.find(i);
      int cnt;
      if(it==mp.end())cnt=deg.at(i);
      else cnt=deg.at((*it).second);
      if(cnt==0)sc.insert(i);
    }
    vector<int>source(all(sc));
    // auto dists=dijkstra(gg,source);
    // rep(i,n)dists.at(i)++;
    vector<int>ans(n,-1);
    auto dfs=[&](auto self,int cur)->void{
      for(auto [w,nx]:gg.at(cur)){
        if(ans.at(nx)!=-1)continue;
        ans.at(nx)=ans.at(cur)+w;
        self(self,nx);
      }
    };
    for(auto ele:source){
      if(ans.at(ele)!=-1)continue;
      ans.at(ele)=1;
      dfs(dfs,ele);
    }
    rep(i,n){
      if(i)cout<<" ";
      // cout<<dists.at(i);
      cout<<ans.at(i);
    }
    cout<<endl;
  }

  return 0;
}
