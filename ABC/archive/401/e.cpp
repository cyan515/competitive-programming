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

int main() {
  int n,m;cin>>n>>m;
  vector g(n,vector<int>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  dsu uf(n);
  vector<set<int>> adj(n);
  rep(i,n) for(auto ii : g.at(i)) if(ii>i) adj.at(i).insert(ii);
  vector<int> ans(n,-1);
  rep(i,n) {
    for(auto ni : g.at(i)) {
      if(ni<i&&!uf.same(ni,i)) {
        int v = uf.leader(i);
        int nv = uf.leader(ni);
        uf.merge(ni,i);
        int nl = uf.leader(i);
        if(v==nl) {
          if(adj.at(v).size()<adj.at(nv).size()) adj.at(v).swap(adj.at(nv));
          for(auto ele : adj.at(nv)) if(ele!=v) adj.at(v).insert(ele);
        } else {
          if(adj.at(nv).size()<adj.at(v).size()) adj.at(nv).swap(adj.at(v));
          for(auto ele : adj.at(v)) if(ele!=nv) adj.at(nv).insert(ele);
        }
        adj.at(nl).erase(i);
        adj.at(nl).erase(ni);
      }
    }
    if(uf.size(0)==i+1) {
      ans.at(i) = adj.at(uf.leader(0)).size();
    }
  }
  rep(i,n) cout << ans.at(i) << endl;

  return 0;
}
