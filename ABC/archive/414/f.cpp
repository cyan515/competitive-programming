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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--) {
    int n,k;cin>>n>>k;
    vector g(n,vector<int>());
    vector<int> ans(n,-1);
    rep(i,n-1) {
      int u,v;cin>>u>>v;u--;v--;
      g.at(u).push_back(v);
      g.at(v).push_back(u);
    }
    queue<int> q;
    q.push(0);
    while(q.size()) {
      int v = q.front();q.pop();
      vector<int> vec;
      auto dfs = [&](auto self,int vv,int p,int d) -> void {
        if(d==k) {
          vec.push_back(vv);
          return;
        }
        for(auto nv : g.at(vv)) {
          if(nv==p) continue;
          self(self,nv,vv,d+1);
        }
      };
      dfs(dfs,v,-1,0);
      for(auto nv : vec) {
        if(ans.at(nv)!=-1) continue;
        ans.at(nv) = ans.at(v) + 1;
        q.push(nv);
      }
    }
    reps(i,1,n) {
      if(i-1) cout << " ";
      if(ans.at(i)!=-1) cout << ans.at(i)+1;
      else cout << -1;
    }
    cout << endl;
  }

  return 0;
}
