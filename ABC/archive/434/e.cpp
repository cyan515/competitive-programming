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
// https://ei1333.github.io/algorithm/bipartite-matching.html
struct Bipartite_Matching
{
  vector< vector< int > > graph;
  vector< int > match, alive, used;
  int timestamp;
 
  Bipartite_Matching(int n)
  {
    timestamp = 0;
    graph.resize(n);
    alive.assign(n, 1);
    used.assign(n, 0);
    match.assign(n, -1);
  }
 
  void add_edge(int u, int v)
  {
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
 
  bool dfs(int v)
  {
    used[v] = timestamp;
    for(int i = 0; i < graph[v].size(); i++) {
      int u = graph[v][i], w = match[u];
      if(alive[u] == 0) continue;
      if(w == -1 || (used[w] != timestamp && dfs(w))) {
        match[v] = u;
        match[u] = v;
        return (true);
      }
    }
    return (false);
  }
 
  int bipartite_matching()
  {
    int ret = 0;
    for(int i = 0; i < graph.size(); i++) {
      if(alive[i] == 0) continue;
      if(match[i] == -1) {
        ++timestamp;
        ret += dfs(i);
      }
    }
    return (ret);
  } 
};
// 座標圧縮
template <typename T>
class coordinate_compression {
public:
  coordinate_compression(const vector<T>& data) {
    _sorted = data;
    sort(_sorted.begin(),_sorted.end());
    _sorted.erase(unique(_sorted.begin(),_sorted.end()),_sorted.end());
  }
  
  /**
   * @fn
   * 受け取った値を座標圧縮した場合いくつになるかを返す。
   * 計算量 O(logN)
   * 
   * @param val 圧縮前の値
   */
  int compress(const T& val) const {
    T ret = lower_bound(_sorted.begin(),_sorted.end(),val) - _sorted.begin();
    return ret;
  }
  
  /**
   * @fn
   * 受け取った値を座標圧縮する前にいくつだったかを返す。
   * 計算量 O(1)
   * 
   * @param val 圧縮後の値
   */
  const T& decompress(const int& val) const {
    return this->_sorted.at(val);
  }
  
  /**
   * @fn
   * 圧縮後の値の種類数を返す。
   */
  size_t size() const {
    return this->_sorted.size();
  }
  
private:
  vector<T> _sorted;
};

int main() {
  int n;cin>>n;
  vector<ll> x(n),r(n);
  rep(i,n) cin>>x.at(i)>>r.at(i);
  vector<ll> b;
  rep(i,n) {
    b.push_back(x.at(i)-r.at(i));
    b.push_back(x.at(i)+r.at(i));
  }
  sort(all(b));
  coordinate_compression cc(b);
  Bipartite_Matching bm(n+cc.size());
  rep(i,n) {
    bm.add_edge(i,n+cc.compress(x.at(i)-r.at(i)));
    bm.add_edge(i,n+cc.compress(x.at(i)+r.at(i)));
  }
  cout<<bm.bipartite_matching() << endl;
  
  return 0;
}
