#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 4001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

void dfs(int v, vector<vector<int>> &G, vector<bool> &seen, vector<int> &order) {
    // 頂点 v に色を塗る
    seen[v] = true;
    // 頂点 v に隣接する頂点 v2 について、
    for(auto v2 : G[v]) {
        // v2 がすでに探索済みならば、スキップする
        if(seen[v2]) {continue;}
        // そうでなければ、頂点 v2 始点で深さ優先探索を行う
        dfs(v2, G, seen, order);
    }
    // order に頂点 v を挿入する
    order.push_back(v);
    return;
}

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector g(n,vector<int>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector<ll> w(n);cin>>w;
  vector<ll> a(n);cin>>a;
  vector<int> order;
  {
    vector gg(n,vector<int>());
    rep(i,n) {
      ll sum = 0;
      for(auto ele : g.at(i)) {
        sum += w.at(ele);
      }
      if(sum>w.at(i)) {
        for(auto ele : g.at(i)) {
          gg.at(i).push_back(ele);
        }
      }
    }
    
    vector<bool> seen(n, false);
    // 頂点 v = 0, 1, …, N-1 の順に
    for(int v = 0; v < n; ++v) {
        // 頂点 v がすでに訪問済みであれば order に含まれているため、スキップ
        if(seen[v]) {continue;}
        // そうでなければ、頂点 v を始点として深さ優先探索を行う
        dfs(v, gg, seen, order);
    }
    
  }
  reverse(all(order));
  int cnt = 0;
  rep(i,n) {
    queue<int> q;
    q.push(order.at(i));
    vector<bool> seen(n,false);
    seen.at(order.at(i)) = true;
    while(q.size()) {
      auto v = q.front();q.pop();
      for(auto ele : g.at(v)) {
        if(w.at(ele)<=w.at(v)) continue;
        if(seen.at(ele)) continue;
        a.at(ele) += a.at(order.at(v));
        cnt += a.at(order.at(v));
        q.push(ele);
        seen.at(ele) = true;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
