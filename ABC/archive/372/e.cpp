#include <bits/stdc++.h>
#include <atcoder/dsu>
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
  int n,Q;cin>>n>>Q;
  dsu uf(n);
  vector vec(n,set<int>());
  rep(i,n) vec.at(i).insert(i);
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int u,v;cin>>u>>v;u--;v--;
      u = uf.leader(u);
      v = uf.leader(v);
      auto x = vec.at(u);
      auto y = vec.at(v);
      for(auto ele : y) x.insert(ele);
      while(x.size()>10) x.erase(x.begin());
      uf.merge(u,v);
      vec.at(uf.leader(u)) = x;
    } else {
      int v,k;cin>>v>>k;v--;
      v = uf.leader(v);
      auto x = vec.at(v);
      if(x.size()<k) {
        cout << -1 << endl;
        continue;
      }
      auto it = x.rbegin();
      rep(i,k-1) it++;
      cout << *it + 1 << endl;
    }
  }

  return 0;
}
